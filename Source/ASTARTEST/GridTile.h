// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridTile.generated.h"

UCLASS()
class ASTARTEST_API AGridTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> StaticMeshRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Material1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Material2;

	UFUNCTION(BlueprintCallable)
	UStaticMesh* LoadBodyMesh();

	UFUNCTION(BlueprintCallable)
	UMaterial* LoadMaterial(FString Material);
};
