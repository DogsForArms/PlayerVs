// Fill out your copyright notice in the Description page of Project Settings.

#include "ABCharacterBase.h"


AABCharacterBase::AABCharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

bool AABCharacterBase::GetMovementAxisForHand(float& Right, float& Forward, UMotionControllerComponent* Hand)
{
	bool HMDEnabled = UVRExpansionFunctionLibrary::GetIsHMDConnected() && UVRExpansionFunctionLibrary::IsInVREditorPreviewOrGame();
	if (!HMDEnabled || !Hand) 
		return false;
	
	bool bIsRight = Hand == RightMotionController;
	Right = GetInputAxisValue(bIsRight ? FName("RightRH") : FName("RightLH"));
	Forward = GetInputAxisValue(bIsRight ? FName("ForwardRH") : FName("ForwardLH"));
	return true;
}
