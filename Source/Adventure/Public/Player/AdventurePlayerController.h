#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AdventurePlayerController.generated.h"

class UAdventureInputConfig;
class UAdventureAbilitySystemComponent;
struct FGameplayTag;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class ADVENTURE_API AAdventurePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAdventurePlayerController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	UAdventureAbilitySystemComponent* GetASC();
private:
	/*
	 * Input Actions Start
	 */
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> AdventureMappingContext;

	UPROPERTY(EditDefaultsOnly, Category="Input|Actions")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Input|Actions")
	TObjectPtr<UInputAction> LookAction;
	/*
	 * Input Actions End
	 */

	/*
	 * Input Functions start
	 */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	/*
	 * Input Functions End
	 */

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAdventureInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAdventureAbilitySystemComponent> AdventureAbilitySystemComponent;
};
