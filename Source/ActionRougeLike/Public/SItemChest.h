// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROUGELIKE_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	// The reason this isn't "void Interact(APawn* InstigatorPawn) override" and has "_Implementation" in the name is because of-
	// -the UFUNCTION(BlueprintNativeEvent) inside of the declaration of the "ISGameplayInterface" 

public:
	UPROPERTY(EditAnywhere, Category="Chest Functionality")
	float TargetPitch;

	void Interact_Implementation(APawn* InstigatorPawn) override;

	
	
protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;	

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Sets default values for this actor's properties
	ASItemChest();

};
