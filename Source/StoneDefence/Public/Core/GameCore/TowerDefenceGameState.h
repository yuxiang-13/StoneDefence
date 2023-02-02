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
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefenceGameState : public AGameState
{
	GENERATED_BODY()

public:
	ATowerDefenceGameState();
	
	ARuleOfTheCharacter *SpawnCharacter(const FVector &Location, const FRotator &Rotator);
	template<class T>
	T *SpawnCharacter(const FVector &Location, const FRotator &Rotator)
	{
		return Cast<T>(SpawnCharacter(Location, Rotator));
	}
	
public:
	const FCharacterData &AddCharacterData(const FGuid &Hash, const FCharacterData &Data);
	bool RemoveCharacterData(const FGuid &Hash);
	FCharacterData &GetCharacterData(const FGuid &Hash);
private:
	// 所有角色数据（包括所有建筑 和 所有的塔）
	UPROPERTY()
	TMap<FGuid,FCharacterData> CharacterDatas;
};
