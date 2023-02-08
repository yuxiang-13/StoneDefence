// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefenceGameState.h"

#include "Character/Core/RuleOfTheCharacter.h"
#include "Data/Core/CharacterData.h"
#include "Data/Save/GameSaveData.h"
#include "Data/Save/GameSaveSlotList.h"
#include "Kismet/GameplayStatics.h"
#include "StoneDefence/StoneDefenceMacro.h"

//static 与 extern 联系：
//加了static修饰的全局变量或函数，无法在使用extern在其他源文件中使用。

// 定义静态类
// extern ：extern（外部引用）可以置于变量或者函数前，以标示变量或函数的定义在别的文件中，在一个文件中用到的extern这些变量或函数是外来的，
// 不是本文件定义的，提示编译器遇到此变量和函数时在其他模块中寻找其定义。注意，只有其他文件中的全局变量才能被其他文件所extern。
FCharacterData CharacterDataNULL;
FBuildingTower BuildingTowerNULL;

ATowerDefenceGameState::ATowerDefenceGameState()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> MyTable_Towers(TEXT("/Game/GameData/TowersData"));
	static ConstructorHelpers::FObjectFinder<UDataTable> MyTable_Monster(TEXT("/Game/GameData/MonsterData"));

	
	AITowerCharacterData = MyTable_Towers.Object;
	AIMonsterCharacterData = MyTable_Monster.Object;

	for (int32 i = 0; i < 21; i++)
	{
		GetSaveData()->BuildingTowers.Add(FGuid::NewGuid(), FBuildingTower());
	}
}

void ATowerDefenceGameState::BeginPlay()
{
	Super::BeginPlay();
}

ATowers* ATowerDefenceGameState::SpawTowner(int32 CharacterID, int32 CharacterLevel, const FVector& Location,
                                            const FRotator& Rotator)
{
	return SpawnCharacter<ATowers>(CharacterID, CharacterLevel, AITowerCharacterData, Location, Rotator);
}

AMonsters* ATowerDefenceGameState::SpawnMonster(int32 CharacterID, int32 CharacterLevel, const FVector& Location,
	const FRotator& Rotator)
{
	return SpawnCharacter<AMonsters>(CharacterID, CharacterLevel, AIMonsterCharacterData, Location, Rotator);
}

bool ATowerDefenceGameState::SaveGameData(int32 SaveNumber)
{
	if (SaveData && SlotList)
	{
		SlotList->SlotList.AddGameDataByNumber(SaveNumber);
		
		return UGameplayStatics::SaveGameToSlot(SlotList, TEXT("SlotList"), 0)
			&& UGameplayStatics::SaveGameToSlot(SaveData, FString::Printf(TEXT("SaveSlot_%i"), SaveNumber), 0);
	}
	return false;
}

bool ATowerDefenceGameState::ReadGameData(int32 SaveNumber)
{
	SaveData = Cast<UGameSaveData>(UGameplayStatics::LoadGameFromSlot(FString::Printf(TEXT("SaveSlot_%i"), SaveNumber), 0));
	return SaveData != nullptr;
}

ARuleOfTheCharacter* ATowerDefenceGameState::SpawnCharacter(int32 CharacterID, int32 CharacterLevel, UDataTable* InCharacterData,const FVector& Location, const FRotator& Rotator)
{
	if (InCharacterData)
	{
		TArray<FCharacterData*> Datas;
		InCharacterData->GetAllRows(TEXT("CharacterData Error"), Datas);
		auto GetCharacterData = [&](int32 ID) -> FCharacterData*
		{
			for (auto &Tmp : Datas)
			{
				if (Tmp->ID == ID)
				{
					return Tmp;
				}
			}
			return nullptr;
		};
		if (FCharacterData *CharacterData = GetCharacterData(CharacterID))
		{
			// 获取DataTable配置好的 class  LoadSynchronous 同步加载
			UClass* NewClass = CharacterData->CharacterBlueprintKey.LoadSynchronous();

		
			if (GetWorld() && NewClass)
			{
				if (ARuleOfTheCharacter * RuleOfTheCharacter = GetWorld()->SpawnActor<ARuleOfTheCharacter>(NewClass, Location, Rotator))
				{
					CharacterData->UpdateHealth();
					AddCharacterData(RuleOfTheCharacter->GUID, *CharacterData);
				}
			}
		}
	}
	return nullptr;
}

const FCharacterData &ATowerDefenceGameState::AddCharacterData(const FGuid &ID,const FCharacterData& Data)
{
	return GetSaveData()->CharacterDatas.Add(ID, Data);
}

const FBuildingTower& ATowerDefenceGameState::AddBuildingTower(const FGuid& ID, const FBuildingTower& Data)
{
	return GetSaveData()->BuildingTowers.Add(ID, Data);
}

bool ATowerDefenceGameState::RemoveCharacterData(const FGuid& ID)
{
	GetSaveData()->CharacterDatas.Remove(ID);
	return true;
}

FCharacterData& ATowerDefenceGameState::GetCharacterData(const FGuid& ID)
{
	if (GetSaveData()->CharacterDatas.Contains(ID))
	{
		return GetSaveData()->CharacterDatas[ID];
	} else
	{
		// SD_print_r(Error, "The current [%s] is invalid", *Hash);
		return CharacterDataNULL;
	}
}

FBuildingTower& ATowerDefenceGameState::GetBuildingTower(const FGuid& ID)
{
	if (GetSaveData()->BuildingTowers.Contains(ID))
	{
		return GetSaveData()->BuildingTowers[ID];
	} else
	{
		// SD_print_r(Error, "The current [%s] is invalid", *Hash);
		return BuildingTowerNULL;
	}
}

const TArray<const FGuid*> ATowerDefenceGameState::GetBuildingTowersID()
{
	TArray<const FGuid*> TowersID;
	
	for (const auto &Tmp: GetSaveData()->BuildingTowers)
	{
		TowersID.Add(&Tmp.Key);
	}
	return TowersID;
}

UGameSaveData* ATowerDefenceGameState::GetSaveData()
{
	if (!SaveData)
	{
		// 创建SaveGame
		SaveData = Cast<UGameSaveData>(UGameplayStatics::CreateSaveGameObject(UGameSaveData::StaticClass()));
	}
	return SaveData;
}

UGameSaveSlotList* ATowerDefenceGameState::GetGameSaveSlotList()
{
	if (!SlotList)
	{
		SlotList = Cast<UGameSaveSlotList>(UGameplayStatics::LoadGameFromSlot(TEXT("SlotList"), 0));
		if (!SlotList)
		{
			SlotList = Cast<UGameSaveSlotList>(UGameplayStatics::CreateSaveGameObject(UGameSaveSlotList::StaticClass()));
		}
	}
	return SlotList;
}
