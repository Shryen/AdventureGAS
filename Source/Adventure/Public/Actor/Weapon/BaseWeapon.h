#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USphereComponent;

UCLASS(Abstract)
class ADVENTURE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABaseWeapon();

	UFUNCTION()
	void OnPickupOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& HitResult);


	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Stats")
	float MinDamage = 0;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Stats")
	float MaxDamage = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Collision")
	TObjectPtr<USphereComponent> PickupCollision;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Collision")
	TObjectPtr<USphereComponent> CombatCollision;

	UPROPERTY(EditDefaultsOnly, Category= "Weapon")
	FName SocketName;
};
