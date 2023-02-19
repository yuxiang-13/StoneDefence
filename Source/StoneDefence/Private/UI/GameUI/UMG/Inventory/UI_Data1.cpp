#include "UI/GameUI/UMG/Inventory/UI_Data1.h"
#include "Character/Core/RuleOfTheCharacter.h"

FGuid TowerICOGUID;
bool bLocalGUID = false;
AActor *TowerDoll = nullptr;

ARuleOfTheCharacter *ClickedTargetTower = nullptr;
ARuleOfTheCharacter *ClickedTargetMonster = nullptr;