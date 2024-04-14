// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_DefensaGameMode.h"
#include "Galaga_USFX_DefensaPawn.h"
#include "NaveEnemiga.h"
#include "Bomba.h"


AGalaga_USFX_DefensaGameMode::AGalaga_USFX_DefensaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_DefensaPawn::StaticClass();

}

void AGalaga_USFX_DefensaGameMode::BeginPlay()
{
	Super::BeginPlay();
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_DefensaPawn::StaticClass();

	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	FVector ubicacionNaveInicial = FVector(600.0f, 0.0f, 180.0f);
	FVector ubicacionNaveActual = ubicacionNaveInicial;

	UWorld* const world = GetWorld(); 
	
	if (world != nullptr)
	{
		// crear naves enemigas
		for (int i = 0; i < 7; i++)
		{
			ANaveEnemiga* naveEnemiga = world->SpawnActor<ANaveEnemiga>(ubicacionNaveActual, rotacionNave);
			TNavesEnemigas.Add(naveEnemiga);
			//ubicacionNaveActual.X += 200.0f;
			ubicacionNaveActual.Y += 200.0f;
		}

	}

	// Establece la frecuencia de lanzamiento de bombas aleatorias en 5 segundos
	GetWorldTimerManager().SetTimer(BombasAleatorias, this, &AGalaga_USFX_DefensaGameMode::LanzarBombasAleatorias, 5.0f, true);
}


void AGalaga_USFX_DefensaGameMode::LanzarBombasAleatorias()
{
	UWorld* const World = GetWorld();
	if (World != nullptr && TNavesEnemigas.Num() > 0)
	{
		// Obtener una nave enemiga aleatoria
		int32 Index = FMath::RandRange(0, TNavesEnemigas.Num() - 1);
		ANaveEnemiga* NaveEnemiga = TNavesEnemigas[Index];

		// Verificar si la nave enemiga es v�lida
		if (NaveEnemiga != nullptr)
		{
			// Obtener la posici�n de la nave enemiga
			FVector PosicionNave = NaveEnemiga->GetActorLocation();

			// Definir la cantidad aleatoria de bombas a lanzar
			int32 CantidadBombas = FMath::RandRange(1, 5); // Puedes ajustar el rango seg�n tus necesidades

			// Bucle para crear y lanzar varias bombas
			for (int32 i = 0; i < CantidadBombas; ++i)
			{
				// Calcular una posici�n aleatoria en Y con un espacio de 200 unidades entre bombas
				float AleatorioY = PosicionNave.Y + FMath::RandRange(-500.0f, 300.0f); // Ajusta el rango seg�n tus necesidades

				// Definir la posici�n de la bomba
				FVector PosicionBomba = FVector(PosicionNave.X, AleatorioY, PosicionNave.Z);

				// Rotaci�n por defecto (puedes ajustarla seg�n tus necesidades)
				FRotator RotacionBomba = FRotator::ZeroRotator;

				// Spawnear la bomba en la posici�n aleatoria calculada
				ABomba* Bomba = World->SpawnActor<ABomba>(PosicionBomba, RotacionBomba);
			}
		}
	}
}