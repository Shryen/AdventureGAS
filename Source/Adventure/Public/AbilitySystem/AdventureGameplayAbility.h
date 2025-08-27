#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AdventureGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTURE_API UAdventureGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag StartupInputTag;
};
