// Fill out your copyright notice in the Description page of Project Settings.

#include "ImpactEffect.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Types/Types.h"

// Sets default values
AImpactEffect::AImpactEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bAutoDestroyWhenFinished = true;
}



void AImpactEffect::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UPhysicalMaterial* HitPhysMat = SurfaceHit.PhysMaterial.Get();
	EPhysicalSurface HitSurfaceType = UPhysicalMaterial::DetermineSurfaceType(HitPhysMat);

	// show particles
	UParticleSystem* ImpactFX = GetImpactFX(HitSurfaceType);
	if (ImpactFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactFX, GetActorLocation(), GetActorRotation());
	}

	// play sound
	USoundCue* ImpactSound = GetImpactSound(HitSurfaceType);
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), FRotator::ZeroRotator);
	}

	//if (DefaultDecal.DecalMaterial)
	//{
	//	FRotator RandomDecalRotation = SurfaceHit.ImpactNormal.Rotation();
	//	RandomDecalRotation.Roll = FMath::FRandRange(-180.0f, 180.0f);

	//	UGameplayStatics::SpawnDecalAttached(DefaultDecal.DecalMaterial, FVector(1.0f, DefaultDecal.DecalSize, DefaultDecal.DecalSize),
	//		SurfaceHit.Component.Get(), SurfaceHit.BoneName,
	//		SurfaceHit.ImpactPoint, RandomDecalRotation, EAttachLocation::KeepWorldPosition,
	//		DefaultDecal.LifeSpan);
	//}
}

UParticleSystem* AImpactEffect::GetImpactFX(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	UParticleSystem* ImpactFX = NULL;

	switch (SurfaceType)
	{
	case SHOOTER_SURFACE_Concrete:	ImpactFX = ConcreteFX; break;
	case SHOOTER_SURFACE_Dirt:		ImpactFX = DirtFX; break;
	case SHOOTER_SURFACE_Water:		ImpactFX = WaterFX; break;
	case SHOOTER_SURFACE_Metal:		ImpactFX = MetalFX; break;
	case SHOOTER_SURFACE_Wood:		ImpactFX = WoodFX; break;
	case SHOOTER_SURFACE_Grass:		ImpactFX = GrassFX; break;
	case SHOOTER_SURFACE_Glass:		ImpactFX = GlassFX; break;
	case SHOOTER_SURFACE_Flesh:		ImpactFX = FleshFX; break;
	}

	return ImpactFX ? ImpactFX : DefaultFX;
}

USoundCue* AImpactEffect::GetImpactSound(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	USoundCue* ImpactSound = NULL;

	switch (SurfaceType)
	{
	case SHOOTER_SURFACE_Concrete:	ImpactSound = ConcreteSound; break;
	case SHOOTER_SURFACE_Dirt:		ImpactSound = DirtSound; break;
	case SHOOTER_SURFACE_Water:		ImpactSound = WaterSound; break;
	case SHOOTER_SURFACE_Metal:		ImpactSound = MetalSound; break;
	case SHOOTER_SURFACE_Wood:		ImpactSound = WoodSound; break;
	case SHOOTER_SURFACE_Grass:		ImpactSound = GrassSound; break;
	case SHOOTER_SURFACE_Glass:		ImpactSound = GlassSound; break;
	case SHOOTER_SURFACE_Flesh:		ImpactSound = FleshSound; break;
	}

	return ImpactSound ? ImpactSound : DefaultSound;
}

void AImpactEffect::LogSurfaceType(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{

	FString Str = FString("Default");

	switch (SurfaceType)
	{
	case SHOOTER_SURFACE_Concrete:	Str = FString("Concrete"); break;
	//case SHOOTER_SURFACE_Dirt:		Str = DirtSound; break;
	//case SHOOTER_SURFACE_Water:		Str = WaterSound; break;
	//case SHOOTER_SURFACE_Metal:		Str = MetalSound; break;
	//case SHOOTER_SURFACE_Wood:		Str = WoodSound; break;
	//case SHOOTER_SURFACE_Grass:		Str = GrassSound; break;
	//case SHOOTER_SURFACE_Glass:		Str = GlassSound; break;
	case SHOOTER_SURFACE_Flesh:		Str = FString("Flesh"); break;
	}
	auto Test = SurfaceType.GetValue();
	UE_LOG(LogTemp, Warning, TEXT("HitXYZ LogSurfaceType -> %s"), *Str)
}