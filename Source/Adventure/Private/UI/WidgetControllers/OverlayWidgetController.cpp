#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/AdventureAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAdventureAttributeSet* AdventureAttributeSet = CastChecked<UAdventureAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AdventureAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AdventureAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAdventureAttributeSet* AdventureAttributeSet = CastChecked<UAdventureAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AdventureAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		});
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AdventureAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		});
}
