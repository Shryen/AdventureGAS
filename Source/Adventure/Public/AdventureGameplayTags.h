#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FAdventureGameplayTags
{
public:
	static const FAdventureGameplayTags& Get() {return GameplayTags;}

	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Vigor;

	FGameplayTag InputTag_CTRL;

private:
	static FAdventureGameplayTags GameplayTags;
};