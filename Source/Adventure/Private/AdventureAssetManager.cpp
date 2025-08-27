#include "AdventureAssetManager.h"

#include "AdventureGameplayTags.h"

UAdventureAssetManager& UAdventureAssetManager::Get()
{
	check(GEngine);

	UAdventureAssetManager* AdventureAssetManager = Cast<UAdventureAssetManager>(GEngine->AssetManager);
	return *AdventureAssetManager;
}

void UAdventureAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAdventureGameplayTags::InitializeNativeGameplayTags();
}


