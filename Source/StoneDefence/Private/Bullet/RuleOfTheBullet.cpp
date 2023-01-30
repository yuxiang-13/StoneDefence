// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet/RuleOfTheBullet.h"

#include "EngineUtils.h"
#include "Character/CharacterCore/Towers.h"
#include "Character/Core/RuleOfTheAIController.h"
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

	// 默认直线
	BulletType = EBulletType::BULLET_DIRECT_LINE;
}

// Called when the game starts or when spawned
void ARuleOfTheBullet::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovement = Cast<UProjectileMovementComponent>(GetComponentByClass(UProjectileMovementComponent::StaticClass()));
	BoxDamage->OnComponentBeginOverlap.AddUniqueDynamic(this, &ARuleOfTheBullet::BeginOverlap);

	switch (BulletType)
	{
	case EBulletType::BULLET_DIRECT_LINE:
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
			break;
		}
	case EBulletType::BULLET_LINE:
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
			break;
		}
	case EBulletType::BULLET_TRACK_LINE: // 跟踪
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OpenFireParticle, GetActorLocation());
			// 打开跟踪
			if (ProjectileMovement) ProjectileMovement->bIsHomingProjectile = true;
			// 旋转方向跟随速度（速度向哪 旋转到哪）
			if (ProjectileMovement) ProjectileMovement->bRotationFollowsVelocity = true;

			
			// 获取 施法对象
			if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(GetInstigator())) // GetInstigator() 就是 AnimNotify中SpawnActor时传的
			{
				if (ARuleOfTheAIController* InstigatorControll = Cast<ARuleOfTheAIController>(InstigatorCharacter->GetController()))
				{
					if (ARuleOfTheCharacter* TargetCharacter = InstigatorControll->Target.Get())
					{
						// 归位加速度 大小
						if (ProjectileMovement) ProjectileMovement->HomingAccelerationMagnitude = 4000.0f;
						// 设置跟踪的物体
						if (ProjectileMovement) ProjectileMovement->HomingTargetComponent = TargetCharacter->GetHomingPoint();
					}
				}
			}
			
			break;
		}
		
	case EBulletType::BULLET_RANGE_LINE: // 范围 自身抛手雷
		{
			if (ProjectileMovement) ProjectileMovement->StopMovementImmediately();
			
			if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(GetInstigator()))
			{
				if (ARuleOfTheAIController *InstigatorController = Cast<ARuleOfTheAIController>(InstigatorCharacter->GetController()))
				{
					if (ARuleOfTheCharacter * TargetCharacter = InstigatorController->Target.Get())
					{
						ProjectileMovement->ProjectileGravityScale = 1.f;
						// 算出距离
						FVector TargetFormOwnerVector = TargetCharacter->GetActorLocation() - GetActorLocation();
						// 算出时间
						float InTime = (TargetFormOwnerVector.Size() / ProjectileMovement->InitialSpeed);
						float Y = ProjectileMovement->GetGravityZ() * InTime;
						float X = ProjectileMovement->InitialSpeed * InTime;
						float V = FMath::Sqrt(X * X + Y * Y);

						float CosRadian = FMath::Acos(TargetFormOwnerVector.Size() / V * (InTime * (PI * 0.1f)));
						FRotator Rot = GetActorRotation();
						// 把弧度转化成角度  只设置pitch(上下抬头  Yaw是左右看  Roll是旋转)
						Rot.Pitch = CosRadian * (180 / PI);
						SetActorRotation(Rot);

						// 设置速度，只设置水平速度
						ProjectileMovement->SetVelocityInLocalSpace(FVector(1.f, 0.f, 0.f) * ProjectileMovement->InitialSpeed);
					}
				}
			}
			break;
		}
	case EBulletType::BULLET_RANGE: // 范围 手雷
		{
			if (ARuleOfTheCharacter * InstigatorCharacter= Cast<ARuleOfTheCharacter>(GetInstigator()))
			{
				if (ProjectileMovement) ProjectileMovement->StopMovementImmediately();
				RadialDamage(GetActorLocation(), Cast<ARuleOfTheCharacter>(GetInstigator()));
			}
			break;
		}
	case EBulletType::BULLET_CHAIN: // 链击
		{
			if (ProjectileMovement) ProjectileMovement->StopMovementImmediately();
			BoxDamage->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			
			// 获取 施法对象
			if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(GetInstigator())) // GetInstigator() 就是 AnimNotify中SpawnActor时传的
			{
				if (ARuleOfTheAIController* InstigatorControll = Cast<ARuleOfTheAIController>(InstigatorCharacter->GetController()))
				{
					if (ARuleOfTheCharacter* TargetCharacter = InstigatorControll->Target.Get())
					{
						UGameplayStatics::SpawnEmitterAttached(DamgageParticle, TargetCharacter->GetHomingPoint());
					}
				}
			}
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
					// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamgageParticle, SweepResult.Location);
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamgageParticle, GetActorLocation());

					
					// 碰撞玩尽兴子弹自身销毁
					switch (BulletType)
					{
						case EBulletType::BULLET_DIRECT_LINE:
						case EBulletType::BULLET_LINE:
						case EBulletType::BULLET_TRACK_LINE:
							{
								UGameplayStatics::ApplyDamage(
									OtherCharacter,
									100.f,
									InstigatorCharacter->GetController(),
									InstigatorCharacter,
									UDamageType::StaticClass()
								);
								Destroy();
								break;
							}
						case EBulletType::BULLET_RANGE_LINE:
								{
									RadialDamage(OtherCharacter->GetActorLocation(), InstigatorCharacter);
									Destroy();
									break;
								}
					}

					
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

void ARuleOfTheBullet::RadialDamage(const FVector& Origin, ARuleOfTheCharacter* InstigatorCharacter)
{
	if (InstigatorCharacter)
	{
		TArray<AActor*> IgnoreActors;
		// TArray<ARuleOfTheCharacter*> TargetActors;
			
		for (TActorIterator<ARuleOfTheCharacter>it(GetWorld(), ARuleOfTheCharacter::StaticClass()); it; ++it)
		{
			if (ARuleOfTheCharacter* TheCharacter = *it)
			{
				FVector VDistance = TheCharacter->GetActorLocation() - InstigatorCharacter->GetActorLocation();
				if (VDistance.Size() <= 1400)
				{
					if (TheCharacter->IsTeam() == InstigatorCharacter->IsTeam())
					{
						IgnoreActors.Add(TheCharacter);
					} else
					{
						// 生成伤害特效
						UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DamgageParticle, TheCharacter->GetActorLocation());
						// TargetActors.Add(TheCharacter);
					}
				}
			}
		}
		UGameplayStatics::ApplyRadialDamageWithFalloff(GetWorld(), 100.f, 10.f, Origin, 400.f, 1000.f, 1.0f, UDamageType::StaticClass(), IgnoreActors, GetInstigator());
	}
}

// Called every frame
void ARuleOfTheBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	
	if (ARuleOfTheCharacter* InstigatorCharacter = Cast<ARuleOfTheCharacter>(GetInstigator())) // GetInstigator() 就是 AnimNotify中SpawnActor时传的
		{
			if (ARuleOfTheAIController* InstigatorControll = Cast<ARuleOfTheAIController>(InstigatorCharacter->GetController()))
			{
				if (ARuleOfTheCharacter* TargetCharacter = InstigatorControll->Target.Get())
				{
					TArray<USceneComponent*> SceneComponent;
					RootComponent->GetChildrenComponents(true, SceneComponent);
					for(auto & Tmp: SceneComponent)
					{
						if (UParticleSystemComponent *ParticleSystem = Cast<UParticleSystemComponent>(Tmp))
						{
							// 设置粒子 起点、终点
							ParticleSystem->SetBeamSourcePoint(0, TargetCharacter->GetHomingPoint()->GetComponentLocation(), 0);
							ParticleSystem->SetBeamEndPoint(0, InstigatorCharacter->GetFirePoint()->GetComponentLocation());
						}
					}
				}
			}
		}
}

