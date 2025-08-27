#include "Player/AdventurePlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/AdventureAbilitySystemComponent.h"
#include "Input/AdventureInputComponent.h"

AAdventurePlayerController::AAdventurePlayerController()
{
	bReplicates = true;
}

void AAdventurePlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AdventureMappingContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(AdventureMappingContext, 0);
	}
}

void AAdventurePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UAdventureInputComponent* AdventureInputComponent = CastChecked<UAdventureInputComponent>(InputComponent);
	AdventureInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAdventurePlayerController::Move);
	AdventureInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAdventurePlayerController::Look);
}

UAdventureAbilitySystemComponent* AAdventurePlayerController::GetASC()
{
	if(AdventureAbilitySystemComponent == nullptr)
	{
		UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>());
		AdventureAbilitySystemComponent = Cast<UAdventureAbilitySystemComponent>(AbilitySystemComponent);
	}
	return AdventureAbilitySystemComponent;
}

void AAdventurePlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAdventurePlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();

	AddPitchInput(-LookAxis.Y);
	AddYawInput(LookAxis.X);
}

void AAdventurePlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	
}

void AAdventurePlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{

}

void AAdventurePlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if(GetASC()) GetASC()->AbilityInputTagHeld(InputTag);
}
