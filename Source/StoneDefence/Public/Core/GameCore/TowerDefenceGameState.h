// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TowerDefenceGameState.generated.h"

struct FCharacterData;
class ARuleOfTheCharacter;

//static 与 extern 联系：
//加了static修饰的全局变量或函数，无法在使用extern在其他源文件中使用。
// 声明这个变量，cpp上边给 定义这个是静态变量
extern FCharacterData CharacterDataNULL;
class UDataTable;
class AMonsters;
class ATowers;
class UGameSaveData;
class UGameSaveSlotList;

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
	ATowers *SpawTowner(int32 CharacterID, int32 CharacterLevel,  const FVector &Location, const FRotator &Rotator);
	
	UFUNCTION(BlueprintCallable, Category="Spawn")
	AMonsters *SpawnMonster(int32 CharacterID, int32 CharacterLevel,  const FVector &Location, const FRotator &Rotator);
	
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
	const FCharacterData &AddCharacterData(const uint32 &ID, const FCharacterData &Data);
	bool RemoveCharacterData(const uint32 &ID);
	FCharacterData &GetCharacterData(const uint32& ID);
protected:
	UGameSaveData *GetSaveData();
	UGameSaveSlotList *GetGameSaveSlotList();
private:
	UPROPERTY()
	UGameSaveData *SaveData;
	
	UPROPERTY()
	UGameSaveSlotList *SlotList;
};
