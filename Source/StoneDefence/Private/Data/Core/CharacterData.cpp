// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Core/CharacterData.h"

// Guid.NewGuid() 是生成不为零的guid,字符串为:14870550-1334-4AA6-A229-3726B7AAB2AE new Guid() 是生成为零的guid,字符串为:00000000-0000-0000-0000-00000000
// 如果你需要一个唯一的标识符,答案是Guid.NewGuid() 
FCharacterData::FCharacterData(): Lv(1.f),ID(INDEX_NONE) // ,GUID(FGuid::NewGuid().ToString())
{
	
}

// 判断是否有效
bool FCharacterData::IsValid()
{
	return ID != INDEX_NONE;
}
