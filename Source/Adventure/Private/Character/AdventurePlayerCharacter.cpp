#include "Character/AdventurePlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Player/AdventurePlayerController.h"
#include "Player/AdventurePlayerState.h"
#include "UI/AdventureHUD.h"


AAdventurePlayerCharacter::AAdventurePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAdventurePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void AAdventurePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AAdventurePlayerCharacter::InitOverlay(AAdventurePlayerState* AdventurePlayerState)
{
	if(AAdventurePlayerController* PlayerController = Cast<AAdventurePlayerController>(GetController()))
	{
		if(AAdventureHUD* AdventureHUD = Cast<AAdventureHUD>(PlayerController->GetHUD()))
		{
			AdventureHUD->InitOverlay(PlayerController, AdventurePlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}

void AAdventurePlayerCharacter::InitAbilityActorInfo()
{
	AAdventurePlayerState* AdventurePlayerState = GetPlayerState<AAdventurePlayerState>();
	check(AdventurePlayerState);
	AdventurePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AdventurePlayerState, this);
	AbilitySystemComponent = AdventurePlayerState->GetAbilitySystemComponent();
	AttributeSet = AdventurePlayerState->GetAttributeSet();
	InitializeDefaultAttributes();
	InitOverlay(AdventurePlayerState);

}

