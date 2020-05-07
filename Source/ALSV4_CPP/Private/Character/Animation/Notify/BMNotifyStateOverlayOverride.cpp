// Copyright (C) 2020, Doga Can Yanikoglu


#include "Character/Animation/Notify/BMNotifyStateOverlayOverride.h"

#include "Character/Animation/BMCharacterAnimInstance.h"

void UBMNotifyStateOverlayOverride::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	UBMCharacterAnimInstance* AnimInst = Cast<UBMCharacterAnimInstance>(MeshComp->GetAnimInstance());
	if (AnimInst)
	{
		AnimInst->OverlayOverrideState = OverlayOverrideState;
	}
}

void UBMNotifyStateOverlayOverride::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UBMCharacterAnimInstance* AnimInst = Cast<UBMCharacterAnimInstance>(MeshComp->GetAnimInstance());
	if (AnimInst)
	{
		AnimInst->OverlayOverrideState = 0;
	}
}

FString UBMNotifyStateOverlayOverride::GetNotifyName_Implementation() const
{
	FString Name(TEXT("Overlay Override State: "));
	Name.Append(GetEnumerationToString(EBMOverlayState(OverlayOverrideState)));
	return Name;
}
