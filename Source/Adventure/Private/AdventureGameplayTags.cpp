

#include "AdventureGameplayTags.h"

#include "GameplayTagsManager.h"

FAdventureGameplayTags FAdventureGameplayTags::GameplayTags;

void FAdventureGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"), TEXT("Amount of strength the character has. Raising Physical Damage"));

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"), TEXT("Amount of Vigor the character has. Raising Maximum Health."));

	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Health"), TEXT("Amount of health the character has."));

	GameplayTags.InputTag_CTRL = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.CTRL"), TEXT("Left Control button"));
}
