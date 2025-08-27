#include "Character/AdventureBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AdventureAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"


AAdventureBaseCharacter::AAdventureBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(true);

	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
}

void AAdventureBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AAdventureBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAdventureBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AAdventureBaseCharacter::InitAbilityActorInfo()
{
	
}

void AAdventureBaseCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass,
	float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, EffectContextHandle);
	EffectContextHandle.AddSourceObject(this);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAdventureBaseCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(InitialVitalAttributes, 1.f);
}

void AAdventureBaseCharacter::AddCharacterAbilities()
{
	UAdventureAbilitySystemComponent* AdventureASC = CastChecked<UAdventureAbilitySystemComponent>(AbilitySystemComponent);
	if(!HasAuthority()) return;
	AdventureASC->AddCharacterAbilities(StartupAbilities);
}





