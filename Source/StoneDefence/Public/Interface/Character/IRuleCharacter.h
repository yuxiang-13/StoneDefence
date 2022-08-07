
#pragma once

#include "CoreMinimal.h"
#include "../StoneDefenceType.h"

class IRuleCharacter
{
public:
	
	virtual bool IsDeath() = 0;
	virtual float GetHealth() = 0;
	virtual float GetMaxHealth() = 0;
	virtual bool IsTream() = 0;
	
	virtual EGameCharacterType::Type GetType() { return EGameCharacterType::Type::TOWER; };
};

