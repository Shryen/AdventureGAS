#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AdventureAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTURE_API UAdventureAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static UAdventureAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
