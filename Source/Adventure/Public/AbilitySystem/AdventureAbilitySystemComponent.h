#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AdventureAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ADVENTURE_API UAdventureAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	void AddCharacterAbilities(TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);
};
