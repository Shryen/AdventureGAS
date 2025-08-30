#pragma once

#include "CoreMinimal.h"
#include "Actor/Weapon/BaseWeapon.h"
#include "OneHandSword.generated.h"

UCLASS()
class ADVENTURE_API AOneHandSword : public ABaseWeapon
{
	GENERATED_BODY()

public:
	AOneHandSword();

protected:
	virtual void BeginPlay() override;
	
};
