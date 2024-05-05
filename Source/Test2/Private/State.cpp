// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

State::State(UStateMachineComponent* StateMachineComponentParameter)
{
	StateMachineComponent = StateMachineComponentParameter;
	if(StateMachineComponent)
		UE_LOG(LogTemp, Warning, TEXT("SM INIT"));
}

State::~State()
{
}
