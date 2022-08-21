// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet/RuleOfTheBullet.h"

#include "Character/Core/RuleOfTheCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARuleOfTheBullet::ARuleOfTheBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxDamage = CreateDefaultSubobject<USphereComponent>(TEXT("BulletNoxDamage"));
	RootBullet = CreateDefaultSubobject<USceneComponent>(TEXT("BulletRootBullet"));
	RootComponent = RootBullet;
	BoxDamage->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
 
	InitialLifeSpan = 4.0f;

	ProjectileMovement = Cast<UProjectileMovementComponent>(GetComponentByClass(UProjectileMovementComponent::StaticClass()));

	// 默认直线
	BulletType = EBulletType::BULLET_DIRECT_LINE;
}

// Called when the game starts or when spawned
void ARuleOfTheBullet::BeginPlay()
{
	Super::BeginPlay();
	BoxDamage->OnComponentBeginOverlap.AddUniqueDynamic(this, &ARuleOfTheBullet::BeginOverlap);

	switch (BulletType)
	{
	case EBulletType::BULLET_DIRECT_LINE:
		{
			break;
		}
	case EBulletType::BULLET_LINE:
		{
			break;
		}
	case EBulletType::BULLET_TRACK_LINE: // 跟踪
		{
			// 打开跟踪
			if (ProjectileMovement) ProjectileMovement->bIsHomingProjectile = true;
			// 旋转方向跟随速度（速度向哪 旋转到哪）
			if (ProjectileMovement) ProjectileMovement->bRotationFollowsVelocity = true;
			
			break;
		}
	case EBulletType::BULLET_RANGE: // 范围
		{
			if (ProjectileMovement) ProjectileMovement->StopMovementImmediately();
			break;
		}
	case EBulletType::BULLET_CHAIN: // 链击
		{
			if (ProjectileMovement) ProjectileMovement->StopMovementImmediately();
			BoxDamage->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			break;
		}
		
	case EBulletType::BULLET_RANGE_LINE:
		{
			break;
		}
	case EBulletType::BULLET_NONE:
		{
			break;
		}
	case EBulletType::BULLET_TRACK_LINE_SP:
		{
			break;
		}
	}
}

void ARuleOfTheBullet::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 获取 施法对象
	if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(GetInstigator())) // GetInstigator() 就是 AnimNotify中SpawnActor时传的
	{
		// 碰撞的那个 对方
		if (ARuleOfTheCharacter * OtherCharacter = Cast<ARuleOfTheCharacter>(OtherActor))
		{
			if (InstigatorCharacter->IsTeam() != OtherCharacter->IsTeam())
			{
				if (OtherCharacter->IsActive())
				{
					// 创建特效
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamgageParticle, SweepResult.Location);

					// 伤害数据
					UGameplayStatics::ApplyDamage(OtherCharacter, 100.f, InstigatorCharacter->GetController(), InstigatorCharacter, UDamageType::StaticClass());
					/*
					 * // 会激活 ARuleOfTheCharacter 的 TakeDamage
					 * 
					 *	protected:
						// 承伤
						virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent) override;
					 */
				}
			}
		}
	}
}

// Called every frame
void ARuleOfTheBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

