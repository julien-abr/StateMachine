// Fill out your copyright notice in the Description page of Project Settings.


#include "Init.h"

Init::Init(UStateMachineComponent* StateMachineComponent) :  State(StateMachineComponent)
{
}

Init::~Init()
{
}

void Init::Begin()
{
	UE_LOG(LogTemp, Warning, TEXT("Begin INIT"));
	End();
}

void Init::Tick()
{
	UE_LOG(LogTemp, Warning, TEXT("Tick INIT"));
}

void Init::End()
{
	EState State = EState::INIT;

	if(StateMachineComponent)
		StateMachineComponent->UpdateState(State);
}
