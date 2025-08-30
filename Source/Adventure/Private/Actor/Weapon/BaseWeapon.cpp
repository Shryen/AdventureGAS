#include "Actor/Weapon/BaseWeapon.h"

#include "Components/SphereComponent.h"


ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon Mesh");
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetRootComponent(WeaponMesh);
	
	PickupCollision = CreateDefaultSubobject<USphereComponent>("Item Pickup Collision");
	PickupCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	PickupCollision->SetupAttachment(GetRootComponent());

	CombatCollision = CreateDefaultSubobject<USphereComponent>("Combat Collision");
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CombatCollision->SetupAttachment(GetRootComponent());
}

void ABaseWeapon::OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	if(OtherActor != nullptr && OtherActor != this)
	{
		UE_LOG(LogTemp, Warning, TEXT("OtherActor's name: %s"), *OtherActor->GetName());
	}
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();

	PickupCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseWeapon::OnPickupOverlap);
}
