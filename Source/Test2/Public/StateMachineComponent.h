// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "StateMachineComponent.generated.h"

UENUM(BlueprintType)
enum class EState : uint8
{
	INIT		 UMETA(DisplayName = "INIT"),
	BALL		 UMETA(DisplayName = "BALL"),
	NEUTRAL      UMETA(DisplayName = "NEUTRAL"),
	SPEAR		 UMETA(DisplayName = "SPEAR")
};

class State;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEST2_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()
	
	TUniquePtr<State> CurrentState = nullptr;

	UPROPERTY(EditAnywhere)
	EState DefaultState;

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();

	void UpdateState(EState NewState);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void InitializeState(EState State);
};
