// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"

/**
 * 
 */
class TEST2_API Init : public State
{
public:
	Init(UStateMachineComponent* StateMachineComponent);
	virtual ~Init() override;
	
	virtual void Begin() override;
	virtual void Tick() override;
	virtual void End() override;
};
