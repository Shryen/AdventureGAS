#include "Player/AdventurePlayerState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AdventureAbilitySystemComponent.h"
#include "AbilitySystem/AdventureAttributeSet.h"
#include "Net/UnrealNetwork.h"

AAdventurePlayerState::AAdventurePlayerState()
{
	SetNetUpdateFrequency(100);

	AbilitySystemComponent = CreateDefaultSubobject<UAdventureAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAdventureAttributeSet>("AttributeSet");
}

void AAdventurePlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAdventurePlayerState, Level);
}

UAbilitySystemComponent* AAdventurePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAdventurePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

void AAdventurePlayerState::OnRep_Level(int32 OldLevel)
{
	
}

