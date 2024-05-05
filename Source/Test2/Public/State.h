// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateMachineComponent.h"

/**
 * 
 */
class TEST2_API State
{
protected:
	TObjectPtr<class UStateMachineComponent> StateMachineComponent = nullptr;
public:
	
	State(class UStateMachineComponent* StateMachineComponentParameter);
	virtual ~State();

	virtual void Begin() = 0;
	virtual void Tick() = 0;
	virtual void End() = 0;
};
