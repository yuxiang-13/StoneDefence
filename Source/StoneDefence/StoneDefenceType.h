
#pragma once

#include "CoreMinimal.h"
#include "StoneDefenceType.generated.h"

UENUM()
namespace EGameCharacterType
{
	enum Type
	{
		TOWER,
		MAIN_TOWER,
		MONSTER,
		BOSS_MONSTER,
		MAX
	};
}

UENUM(BlueprintType)
enum EBulletType
{
	BULLET_NONE,            //不产生任何效果
 
	BULLET_DIRECT_LINE,     //无障碍直线攻击
	BULLET_LINE,            //非跟踪类型，类似手枪子弹；
	BULLET_TRACK_LINE,      //跟踪类型 (不管穿)
	BULLET_TRACK_LINE_SP,   //跟踪类型
	BULLET_RANGE_LINE,      //范围伤害，丢手雷；
	BULLET_RANGE,           //范围伤害，类似自爆；
	BULLET_CHAIN,           //链条类型，持续伤害类型;
};



