// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include"Engine.h"
//#include"App.h
// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent * SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootConponent"));
	SphereComponent->InitSphereRadius(40.0f);
	RootComponent = SphereComponent;

	UStaticMeshComponent* VisualComponent = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Component"));
	VisualComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>VisualComponentAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (VisualComponentAsset.Succeeded())
	{
		VisualComponent->SetStaticMesh(VisualComponentAsset.Object);
		//VisualComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		//VisualComponent->SetWorldScale3D(FVector(0.8f));
	}
	
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
FVector V;
float speed= 500.0f;
FVector displacement;
//static double GetDeltaTime();
// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	ACharacter* MyProjectCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	V = MyProjectCharacter->GetActorLocation() - GetActorLocation();
    displacement = V.Normalize()* speed;
	SetActorLocation(displacement, true);
	Super::Tick(DeltaTime);

}

