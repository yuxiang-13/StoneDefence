// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillData.h"
#include "Engine/DataTable.h"
#include "CharacterData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCharacterData: public FTableRowBase
{
	GENERATED_BODY()
public:
	FCharacterData();
	
	//////// 
	// 基础
	////////
	
	// 玩家名字
	UPROPERTY(EditDefaultsOnly, Category="Character Attribute")
	FName Name;
	
	// 玩家等级
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character Attribute")
	int32 Lv;

	// 最大生命
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float MaxHealth;

	// 生命
	UPROPERTY()
	float Health;

	// 基础攻击
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float PhysicalAttack;

	// 护甲
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float Armor;
	
	// 最大经验值
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float MaxEmpircalValue;
	
	// 经验值
	UPROPERTY()
	float EmpircalValue;

	// 攻击速度
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float AttackSpeed;
	
	// CD
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float CD;

	// 如果是塔则代表花费多少金币可以建造
	// 如果是怪物代表消认获取多少金币
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	float Glod;

	// 角色简介
	UPROPERTY(EditDefaultsOnly,Category= "Character Attribute")
	FText Introduction;


	
	//////// 
	// 增益
	//////// 

	// 怪 增益金币
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddGlod;
	
	// 怪 增益血
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddHealth;

	// 怪 增益攻击力
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddPhysicalAttack;
	
	// 怪 增益护甲
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddArmor;
	
	// 怪 增益经验
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddEmpiricalValue;
	
	// 怪 增益攻击速度
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float AddAttackSpeed;
	
	// 怪 增益自动回复生命值
	UPROPERTY(EditDefaultsOnly,Category= "Character Profit")
	float RestoreHealth;


	//////// 
	// 塔技能
	////////

	// 添加被动生命值
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float AddPassiveSkillHealth;

	// 添加 持续恢复生命值
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float AddContinueHealth;
	
	// 添加 被动攻击力
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float AddPassiveSkillPhysicalAttack;
	
	// 添加 被动护甲
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float AddPassiveSkillArmor;
	
	// 添加 被动攻击速度
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float AddPassiveSkillAttackSpeed;
	
	// 添加 被动CD  [rɪˈdjuːs] 减少;  [ˈpæsɪv] 被动的
	UPROPERTY(EditDefaultsOnly,Category= "Skill")
	float ReducePassiveSkillCDTime;
	
	// 角色多久建立好   [kənˈstrʌkʃn]  建设;
	UPROPERTY(EditDefaultsOnly,Category= "Build")
	float ConstructionTime;
	
	//////// 
	// 技能 (每一等级对应不同技能)
	////////
	UPROPERTY(EditDefaultsOnly,Category= "Character Skill")
	TMap<int32, FSkillData> CharacterSkill;
	
};
