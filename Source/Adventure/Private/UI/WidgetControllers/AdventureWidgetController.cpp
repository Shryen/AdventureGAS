#include "UI/WidgetControllers/AdventureWidgetController.h"

void UAdventureWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAdventureWidgetController::BroadcastInitialValues()
{
	
}

void UAdventureWidgetController::BindCallbacksToDependencies()
{
	
}
