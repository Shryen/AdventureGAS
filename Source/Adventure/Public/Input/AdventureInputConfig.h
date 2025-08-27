#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AdventureInputConfig.generated.h"

USTRUCT(BlueprintType)
struct FAdventureInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag Tag = FGameplayTag();
};

UCLASS()
class ADVENTURE_API UAdventureInputConfig : public UDataAsset
{
public:
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable)
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound = false);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FAdventureInputAction> AbilityInputActions;
};
