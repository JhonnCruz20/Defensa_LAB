// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));

	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;
	VelocidadY = 200.0f; // se mover� constantemente en Y
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemiga::Mover(float DeltaTime)
{
	//Obtenemos la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Generamos nueva coordenada X
	float NuevaX = 0.0f; // No se mueve en el eje X

	// Calculamos la nueva posici�n en el eje Y
	float NuevaPosicionY = PosicionActual.Y + (VelocidadY * DeltaTime);

if (NuevaPosicionY >= 1800.0f)
 {
     // Cambiamos la direcci�n multiplicando por -1
     VelocidadY *= -1.0f;
 }
 else if (NuevaPosicionY <= -1800.0f)
 {
     // Cambiamos la direcc	�n multiplicando por -1
     VelocidadY *= -1.0f;
 }
	// Establecemos la nueva posici�n del actor
	SetActorLocation(FVector(PosicionActual.X + NuevaX, NuevaPosicionY, PosicionActual.Z));
}

