// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterMindGM.h"
#include "GameFramework/Actor.h"
#include "MastermindRow.generated.h"

UCLASS()
class AIX_GD3_FILROUGE_API AMastermindRow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMastermindRow();

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AMasterMindGM* Manager;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMeshComponent*> AnswerSpheres;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> PlayerSpheres;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void Clicked();

	UFUNCTION(BlueprintCallable)
	void ApplySolution(uint8 GoodPlaces, uint8 WrongPlaces);
};
