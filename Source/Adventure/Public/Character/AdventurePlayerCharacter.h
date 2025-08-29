#pragma once

#include "CoreMinimal.h"
#include "AdventureBaseCharacter.h"
#include "Player/AdventurePlayerState.h"
#include "AdventurePlayerCharacter.generated.h"

UCLASS()
class ADVENTURE_API AAdventurePlayerCharacter : public AAdventureBaseCharacter
{
	GENERATED_BODY()

public:
	AAdventurePlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	void InitOverlay(AAdventurePlayerState* AdventurePlayerState);

protected:
	virtual void InitAbilityActorInfo() override;
};
