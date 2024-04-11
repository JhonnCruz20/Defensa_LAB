// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_DefensaGameMode.h"
#include "Galaga_USFX_DefensaPawn.h"
#include "NaveEnemiga.h"

AGalaga_USFX_DefensaGameMode::AGalaga_USFX_DefensaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_DefensaPawn::StaticClass();
	NaveEnemiga = nullptr;
}

void AGalaga_USFX_DefensaGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing

}