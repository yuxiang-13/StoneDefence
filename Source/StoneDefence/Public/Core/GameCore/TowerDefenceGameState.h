// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Core/CharacterData.h"
#include "GameFramework/GameState.h"
#include "TowerDefenceGameState.generated.h" 

class ARuleOfTheCharacter;


class UDataTable;
class AMonsters;
class UGameSaveData;
class UGameSaveSlotList;

struct FBuildingTower;
struct FCharacterData;


//static 与 extern 联系：
//加了static修饰的全局变量或函数，无法在使用extern在其他源文件中使用。
// 声明这个变量，cpp上边给 定义这个是静态变量
extern FCharacterData CharacterDataNULL;
extern FBuildingTower BuildingTowerNULL;

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefenceGameState : public AGameState
{
	GENERATED_BODY()

	// 塔数据
	UPROPERTY()
	UDataTable* AITowerCharacterData;
	
	// 怪物数据
	UPROPERTY()
	UDataTable* AIMonsterCharacterData;
	// 怪物数据
public:
	ATowerDefenceGameState();

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category="Spawn")
	class ATowers *SpawTowner(int32 CharacterID, int32 CharacterLevel,  const FVector &Location, const FRotator &Rotator);
	
	UFUNCTION(BlueprintCallable, Category="Spawn")
	class AMonsters *SpawnMonster(int32 CharacterID, int32 CharacterLevel,  const FVector &Location, const FRotator &Rotator);
	
	UFUNCTION(BlueprintCallable, Category="SaveData")
	bool SaveGameData(int32 SaveNumber);
	UFUNCTION(BlueprintCallable, Category="SaveData")
	bool ReadGameData(int32 SaveNumber);
protected:
	ARuleOfTheCharacter *SpawnCharacter(int32 CharacterID, int32 CharacterLevel, UDataTable* InCharacterData,  const FVector &Location, const FRotator &Rotator);
	template<class T>
	T *SpawnCharacter(int32 CharacterID, int32 CharacterLevel, UDataTable* InCharacterData, const FVector &Location, const FRotator &Rotator)
	{
		return Cast<T>(SpawnCharacter(CharacterID, CharacterLevel, InCharacterData, Location, Rotator));
	}
	
public:
	const FCharacterData &AddCharacterData(const FGuid &ID, const FCharacterData &Data);
	bool RemoveCharacterData(const FGuid &ID);
	FCharacterData &GetCharacterData(const FGuid& ID);

	const FBuildingTower &AddBuildingTower(const FGuid &ID, const FBuildingTower &Data);
	// 获取塔数据
	FBuildingTower &GetBuildingTower(const FGuid& ID);
	// 获取所有塔ID 数据
	const TArray<const FGuid*> GetBuildingTowersID();

	bool GetCharacterDataFormTable(TArray<const FCharacterData*> &Datas);

	// 交换数据，要放到服务器上
	void RequestInventorySlotSwap(const FGuid &A, const FGuid &B);
protected:
	UGameSaveData *GetSaveData();
	UGameSaveSlotList *GetGameSaveSlotList();
private:
	UPROPERTY()
	UGameSaveData *SaveData;
	
	UPROPERTY()
	UGameSaveSlotList *SlotList;
};
