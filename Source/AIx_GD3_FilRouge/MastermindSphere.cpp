// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindSphere.h"

#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UMastermindSphere::UMastermindSphere()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	
	// ...
}


// Called when the game starts
void UMastermindSphere::BeginPlay()
{
	Super::BeginPlay();
	if (Mesh)
	{
		Mesh->OnClicked.AddDynamic(this,&UMastermindSphere::Clicked);
		UMaterialInterface* BaseMat = Mesh->GetMaterial(0);
		DynamicMat = UMaterialInstanceDynamic::Create(BaseMat, this);
		Mesh->SetMaterial(0, DynamicMat);
	}
	ChangeColor(BlockedColor);
	// ...
	
}


// Called every frame
void UMastermindSphere::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMastermindSphere::Clicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	if (CanInteract == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Composant cliqué !"));
		ActualColorNumber ++;
		if (ActualColorNumber >= 6)
		{
			ActualColorNumber = 0;
		}
		if(Manager)
		{
			ChangeColor(Manager->GetColor(ActualColorNumber));
		}	
	}
}

void UMastermindSphere::Unblock()
{
}

void UMastermindSphere::Block()
{
}

void UMastermindSphere::ChangeColor(FLinearColor NewColor)
{
	if (DynamicMat)
	{
		DynamicMat->SetVectorParameterValue("Color", NewColor);
	}
	
}

int UMastermindSphere::GetSphereColor()
{
	return ActualColorNumber;
	
}

