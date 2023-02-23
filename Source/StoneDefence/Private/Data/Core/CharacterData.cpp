// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Core/CharacterData.h"

// Guid.NewGuid() 是生成不为零的guid,字符串为:14870550-1334-4AA6-A229-3726B7AAB2AE new Guid() 是生成为零的guid,字符串为:00000000-0000-0000-0000-00000000
// 如果你需要一个唯一的标识符,答案是Guid.NewGuid()  : Lv(1.f),ID(INDEX_NONE), Health(1000.f) // ,GUID(FGuid::NewGuid().ToString())
FCharacterData::FCharacterData()
{
	ID = INDEX_NONE;
	Lv = 0;
	MaxHealth = 100.f;
	Health = MaxHealth;
	PhysicalAttack = 10.f;
	Armor = 10.f;
	MaxEmpircalValue = 100.f;
	EmpircalValue = 0.f;
	CD = 2.f;
	AttackSpeed = 0.66f;
	Glod = 80;

	AddGlod = 30;
	AddHealth = 50.f;
	AddPhysicalAttack = 10.f;
	AddArmor = 8.f;
	AddEmpiricalValue = 100.f;
	AddAttackSpeed = 0.001f;
	RestoreHealth = 0.2f;
	// WalkSpeed = 356.f;
	//
	// Location = FVector::ZeroVector;
	// Rotator = FRotator::ZeroRotator;
	// Team = ETeam::RED;
}

float FCharacterData::GetEPPercent() const
{
	if (MaxEmpircalValue != 0)
	{
		return EmpircalValue / MaxEmpircalValue;
	}
	return 0.f;
}

// 判断是否有效
bool FCharacterData::IsValid()
{
	return ID != INDEX_NONE;
}

void FCharacterData::UpdateHealth()
{
	Health = MaxHealth;
}

bool FCharacterData::UpdateLevel(float InExp)
{
	EmpircalValue += InExp;
	// 自动升级
	if (EmpircalValue >= MaxEmpircalValue)
	{
		EmpircalValue = EmpircalValue - MaxEmpircalValue;
		//被动技能加成
		float Coefficient = .1f;
		
		Lv++;
		Glod += (Lv - 1)*AddGlod * Coefficient;
		MaxHealth += (Lv - 1)*AddHealth * Coefficient;
		PhysicalAttack += (Lv - 1)*AddPhysicalAttack * Coefficient;
		AttackSpeed += (Lv - 1)*AddAttackSpeed * Coefficient;
		Armor += (Lv - 1)*AddArmor * Coefficient;
		MaxEmpircalValue += (Lv - 1)*AddEmpiricalValue * Coefficient;
		RestoreHealth += (RestoreHealth * Lv) / 100;
		
		AddPassiveSkillHealth += ((Lv - 1)*AddPassiveSkillHealth)* (Coefficient - 0.09f);
		AddPassiveSkillPhysicalAttack += (Lv - 1)*AddPassiveSkillPhysicalAttack *(Coefficient - 0.09f);
		AddPassiveSkillAttackSpeed += (Lv - 1)*AddPassiveSkillAttackSpeed *(Coefficient - 0.09f);
		// AddPassiveSkilldArmor = +(Lv - 1)*AddPassiveSkilldArmor * (Coefficient - 0.09f);
		
		Health = MaxHealth;
		return true;
	}
	return false;
}
