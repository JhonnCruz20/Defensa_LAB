// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_DefensaGameMode.generated.h"

class ANaveEnemiga;

UCLASS(MinimalAPI)
class AGalaga_USFX_DefensaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_DefensaGameMode();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemiga* NaveEnemiga;
};



