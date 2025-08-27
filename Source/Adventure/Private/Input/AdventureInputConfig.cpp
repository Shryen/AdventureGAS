#include "Input/AdventureInputConfig.h"

const UInputAction* UAdventureInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound)
{
	for(const FAdventureInputAction& Action : AbilityInputActions)
	{
		if(Action.InputAction && Action.Tag == InputTag)
		{
			return Action.InputAction;
		}
		bLogNotFound = true;
	}
	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s], on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}
	return nullptr;
}
