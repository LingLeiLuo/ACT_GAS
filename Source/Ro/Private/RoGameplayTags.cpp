// Fill out your copyright notice in the Description page of Project Settings.


#include "RoGameplayTags.h"
 
namespace RoGameplayTags
{
	// 输入Tag
	UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(Input_Ctrl, "Input.Ctrl");
	
	UE_DEFINE_GAMEPLAY_TAG(Input_LMB, "Input.LMB");
	UE_DEFINE_GAMEPLAY_TAG(Input_RMB, "Input.RMB");
	UE_DEFINE_GAMEPLAY_TAG(Input_Shift, "Input.Shift");
	
	
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_Start, "Ability.NormalAttack.Start");
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_A, "Ability.NormalAttack.A");
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_B, "Ability.NormalAttack.B");
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_C, "Ability.NormalAttack.C");
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_D, "Ability.NormalAttack.D");
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_Attacking, "Ability.NormalAttack.Attacking");
	
	UE_DEFINE_GAMEPLAY_TAG(Ability_NormalAttack_Window, "Ability.NormalAttack.Window");
	UE_DEFINE_GAMEPLAY_TAG(Ability_MoveCancel_Window, "Ability.MoveCancel.Window");

	UE_DEFINE_GAMEPLAY_TAG(Ability_Action_Roll, "Ability.Action.Roll");
	
}


