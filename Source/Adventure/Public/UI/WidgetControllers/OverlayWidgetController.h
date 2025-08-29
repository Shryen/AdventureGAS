#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/AdventureWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChanged, float, NewValue);

/**
 * Overlay widget controller for Overlay widget that's going to be the base of everything visible on the screen.
 */
UCLASS(Blueprintable, BlueprintType)
class ADVENTURE_API UOverlayWidgetController : public UAdventureWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

private:
	UPROPERTY(BlueprintAssignable, Category = "WidgetController")
	FOnAttributeChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "WidgetController")
	FOnAttributeChanged OnMaxHealthChanged;
};
