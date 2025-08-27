#include "Character/AdventurePlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AdventureAbilitySystemComponent.h"
#include "Player/AdventurePlayerState.h"


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

void AAdventurePlayerCharacter::InitAbilityActorInfo()
{
	AAdventurePlayerState* AdventurePlayerState = GetPlayerState<AAdventurePlayerState>();
	check(AdventurePlayerState);

	AdventurePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AdventurePlayerState, this);
	AbilitySystemComponent = AdventurePlayerState->GetAbilitySystemComponent();
	AttributeSet = AdventurePlayerState->GetAttributeSet();
	InitializeDefaultAttributes();
}

