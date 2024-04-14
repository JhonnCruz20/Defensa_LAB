// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomba.generated.h"

class UStaticMeshComponent;

UCLASS()
class GALAGA_USFX_DEFENSA_API ABomba : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaBomba;
	
public:	
	// Sets default values for this actor's properties
	ABomba();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void MoverBomba(float DeltaTime); // función para mover la bomba
	UPROPERTY(EditAnywhere, Category = "Movimiento") // EditAnywhere para que se pueda modificar desde el editor
	float VelocidadBombaX;
};
