#pragma once

#include "CoreMinimal.h"


enum EScreenMoveState
{
	Screen_None,
	Screen_UP, // 上
	Screen_Down, // 下
	Screen_Right, // 右
	Screen_Left, // 左
	Screen_RightAndUP, // 右上
	Screen_RightAndDown, // 右下
	Screen_LeftAndUP, // 左上
	Screen_LeftAndDown, // 左下
	Screen_MAX
};

// 屏幕移动
struct STONETOOLCLASS_API FScreenMoveUnits
{
	
	/*
	 * 监听屏幕移动
	 * @Param PlayerController 玩家控制
	 * @Param ScreenMoveSpeed 移动速度
	 * @return 返回当前是否移动成功
	 */ 
	void ListenScreenMove(class APlayerController *PlayerController,const float &ScreenMoveSpeed = 100.f);
	
	// 判断移动方向
	EScreenMoveState CursorMove(const class APlayerController * PlayerController);

	/*
	 * 让Pawn随着鼠标移动
	 * @Param PlayerController 玩家控制
	 * @Param ScreenMoveState 移动状态
	 * @Param ScreenMoveSpeed 移动速度
	 * @return 返回当前是否移动成功
	 */ 
	bool MoveDirection(class APlayerController *PlayerController, EScreenMoveState ScreenMoveState,const float &ScreenMoveSpeed = 100.f);
};




