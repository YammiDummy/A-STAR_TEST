// Fill out your copyright notice in the Description page of Project Settings.


#include "GridTile.h"
#include <Engine/StreamableManager.h>
#include <Engine/AssetManager.h>

// Sets default values
AGridTile::AGridTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>("Scene");
	//Scene->SetupAttachment(RootComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Scene);

}

// Called when the game starts or when spawned
void AGridTile::BeginPlay()
{
	Super::BeginPlay();

	Material1 = TEXT("/Game/Import/phong1.phong1");
	Material2 = TEXT("/Game/Import/lambert2.lambert2");

	StaticMesh->SetStaticMesh(LoadBodyMesh());
	StaticMesh->SetMaterial(0, LoadMaterial(Material1));
	StaticMesh->SetMaterial(1, LoadMaterial(Material2));
}

UStaticMesh* AGridTile::LoadBodyMesh()
{
	if (StaticMeshRef.IsPending())
	{
		const FSoftObjectPath& AssetRef = StaticMeshRef.ToStringReference();
		FStreamableManager& StreamableManager = UAssetManager::Get().GetStreamableManager();
		StaticMeshRef = Cast<UStaticMesh>(StreamableManager.LoadSynchronous(AssetRef));
	}

	return StaticMeshRef.Get();
}

UMaterial* AGridTile::LoadMaterial(FString Material)
{
	UMaterial* NewMaterial = LoadObject<UMaterial>(NULL, *Material, NULL, LOAD_None, NULL);
	return NewMaterial;
}
