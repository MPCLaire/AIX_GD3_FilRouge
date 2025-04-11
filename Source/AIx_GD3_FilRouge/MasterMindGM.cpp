// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterMindGM.h"

// Sets default values
AMasterMindGM::AMasterMindGM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterMindGM::BeginPlay()
{
	Super::BeginPlay();
	CreateSolution();
}

// Called every frame
void AMasterMindGM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FLinearColor AMasterMindGM::GetColor(uint8 ColorNumber)
{
	if(ColorNumber < Colors.Num())
	{
		return Colors[ColorNumber];
	}

	return FLinearColor::Black;
	
}


void AMasterMindGM::CreateSolution()
{
	Solution.SetNum(4);
	for(uint8 i = 0; i < 4; i++)
	{
		Solution[i] = FMath::RandRange(0,5);
		UE_LOG(LogTemp, Warning, TEXT("Solution [%d]"), i);
	}
}

bool AMasterMindGM::CheckAnswer(TArray<uint8> Answer)
{

	bool result = true;
	uint8 GoodPlaces = 0;
	uint8 WrongPlaces = 0;
	TArray<bool> SolutionAllowed {true, true, true, true};
	TArray<bool> AnswersAllowed {true, true, true, true};
	
	// trouve les réponses bien placées et les stock dans GoodPlaces
	for (uint8 i = 0; i < 4; i++)
	{
		if (Answer[i] == Solution[i])
		{
			SolutionAllowed[i] = false;
			AnswersAllowed[i] = false;
			UE_LOG(LogTemp, Warning, TEXT("CheckAnswer [%d]: Oui"), i);
			GoodPlaces++;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CheckAnswer [%d]: Non"), i);
			result = false;
		}
	}
	
	//Vérifie les cases qui ne sont pas bien placées et les compare à la solution 1 par 1
	for (uint8 i = 0; i < 4; i++)
	{
		if (AnswersAllowed[i])
		{
			for (uint8 j = 0; j < 4; j++)
			{
				if (SolutionAllowed[j] && Answer[i] == Solution[j])
				{
					WrongPlaces++;
					SolutionAllowed[j] = false;
					break;
				}
			}
		}
	}

	OnSolutionChecked.Broadcast(GoodPlaces,WrongPlaces);
	return result;
	
}





