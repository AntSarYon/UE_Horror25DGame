
#include "SoulLight/EC_SoulLight.h"

#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Core/EC_GameInstance.h"
#include "Kismet/GameplayStatics.h"

AEC_SoulLight::AEC_SoulLight()
{
	PrimaryActorTick.bCanEverTick = true;

	//Inicializamos los datos de las Luces de Alma
	SpotLightOriginalIntensity = 20000.00f;
	SpotLightOriginalAttenuationRadius = 1000.00f;
	SpotLightOriginalInnerConeAngle = 50.00f;
	SpotLightOriginalOuterConeAngle = 70.00f;

	PointLightOriginalIntensity = 500.00f;
	PointLightOriginalAttenuationRadius = 1000.00f;
	PointLightOriginalSourceRadius = 500.00f;

	//Inicializamos escala de Reduccion de Luz
	DecreaseSpeedScale = 500.00f;
}

//----------------------------------------------------------------------------

void AEC_SoulLight::BeginPlay()
{
	Super::BeginPlay();

	//Obtenemos referencia a Componentes
	SpotLightComponent = Cast<USpotLightComponent>(GetDefaultSubobjectByName(TEXT("SpotLight")));
	PointLightComponent = Cast<UPointLightComponent>(GetDefaultSubobjectByName(TEXT("PointLight")));
	

	//Obtenemos referencia al GameInstance
	UEC_GameInstance* GInstance = Cast<UEC_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	//Revisamos que la variable sea válida
	if(IsValid(GInstance))
	{
		//Obtenemos el ultimo Porcentaje del PointLight
		CurrentPercentage = GInstance->GetLightCurrentPercentage();

		//Actualizamos los valores Iniciales de las Luces
		if(IsValid(PointLightComponent))
		{
			PointLightComponent->Intensity = PointLightOriginalIntensity * (CurrentPercentage/100);
			PointLightComponent->AttenuationRadius = PointLightOriginalAttenuationRadius * (CurrentPercentage / 100);
			PointLightComponent->SourceRadius = PointLightOriginalSourceRadius * (CurrentPercentage / 100);
		}

		if(IsValid(SpotLightComponent))
		{
			SpotLightComponent->Intensity = SpotLightOriginalIntensity * (CurrentPercentage / 100);
			SpotLightComponent->AttenuationRadius = SpotLightOriginalAttenuationRadius * (CurrentPercentage / 100);
			SpotLightComponent->InnerConeAngle = SpotLightOriginalInnerConeAngle * (CurrentPercentage / 100);
			SpotLightComponent->OuterConeAngle = SpotLightOriginalOuterConeAngle * (CurrentPercentage / 100);
		}
	}
}

//----------------------------------------------------------------------------

void AEC_SoulLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//----------------------------------------------------------------------------

float AEC_SoulLight::GetActualPercentage()
{
	//Obtenemos el Porcentaje Actual a partir de una de las propiedades de la Luz...
	CurrentPercentage = (SpotLightComponent->Intensity * 100) / SpotLightOriginalIntensity;

	//Retonramos el Porcentaje obtenido.
	return CurrentPercentage;
}

//----------------------------------------------------------------------------

void AEC_SoulLight::DecreasePointLight(float DeltaTime)
{
	PointLightComponent->Intensity -= ((PointLightComponent->Intensity / DecreaseSpeedScale) * DeltaTime);
	PointLightComponent->AttenuationRadius -= ((PointLightComponent->AttenuationRadius / DecreaseSpeedScale) * DeltaTime);
	PointLightComponent->SourceRadius -= ((PointLightComponent->SourceRadius / DecreaseSpeedScale) * DeltaTime);
}

void AEC_SoulLight::DecreaseSpotLight(float DeltaTime)
{
	SpotLightComponent->Intensity -= ((SpotLightComponent->Intensity / DecreaseSpeedScale) * DeltaTime);
	SpotLightComponent->AttenuationRadius -= ((SpotLightComponent->AttenuationRadius / DecreaseSpeedScale) * DeltaTime);
	SpotLightComponent->InnerConeAngle -= ((SpotLightComponent->InnerConeAngle / DecreaseSpeedScale) * DeltaTime);
	SpotLightComponent->OuterConeAngle -= ((SpotLightComponent->OuterConeAngle / DecreaseSpeedScale) * DeltaTime);
}
