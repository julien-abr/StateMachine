// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineComponent.h"
#include "State.h"
#include "Init.h"

UStateMachineComponent::UStateMachineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	//Default State
	InitializeState(DefaultState);
}

void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CurrentState)
	{
		CurrentState->Tick();
	}
}

void UStateMachineComponent::UpdateState(EState NewState)
{
	if(CurrentState)
	{
		delete CurrentState;
		CurrentState = nullptr;
	}

	InitializeState(NewState);
}

void UStateMachineComponent::InitializeState(EState State)
{
	switch(State)
	{
		case EState::INIT:
			{
				Init* init = new Init(this);
				CurrentState = init;
				CurrentState->Begin();	
			}
			break;
		case EState::BALL:
			break;
		case EState::NEUTRAL:
			break;
		case EState::SPEAR:
			break;
		default:
			break;
	}	

	if(CurrentState)
		CurrentState->Begin();
}

