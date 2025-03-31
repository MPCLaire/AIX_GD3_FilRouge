// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindRow.h"

#include "MastermindSphere.h"

// Sets default values
AMastermindRow::AMastermindRow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMastermindRow::BeginPlay()
{
	Super::BeginPlay();
	Manager->OnSolutionChecked.AddDynamic(this, &AMastermindRow::ApplySolution);
}

// Called every frame
void AMastermindRow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMastermindRow::Clicked()
{
	TArray<uint8> Answer;
	Answer.SetNum(4);
	for(int i = 0; i < 4; i++)
	{
		Answer[i] = PlayerSpheres[i]->GetComponentByClass<UMastermindSphere>()->GetSphereColor();
	}
	Manager->CheckAnswer(Answer);
}

void AMastermindRow::ApplySolution(uint8 GoodPlaces, uint8 WrongPlaces)
{
}

