// This project is created for entertainment and is totally free.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EC_SoulLight.generated.h"

class USpotLightComponent;
class UPointLightComponent;

UCLASS()
class ELCHARCO_API AEC_SoulLight : public AActor
{
	GENERATED_BODY()

protected:
	//Referencia a POINT LIGHT
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	UPointLightComponent* PointLightComponent = {nullptr};

	//Referencia a SPOT LIGHT
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	USpotLightComponent* SpotLightComponent ={nullptr};


	//DATOS INICIALES DEL POINTLIGHT DEL ALMA
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float PointLightOriginalIntensity;

	//DATOS INICIALES DEL POINTLIGHT DEL ALMA
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float PointLightOriginalAttenuationRadius;

	//DATOS INICIALES DEL POINTLIGHT DEL ALMA
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float PointLightOriginalSourceRadius;


	//DATOS INICIALES DEL SPOTLIGHT DEL ALMA
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float SpotLightOriginalIntensity;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float SpotLightOriginalAttenuationRadius;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float SpotLightOriginalInnerConeAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "LightsData")
	float SpotLightOriginalOuterConeAngle;



	//Velocidad de Disminucion de la Luz | Mientras menor el numero, mas rapido desciende
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	float DecreaseSpeedScale;

	//Porcentaje actual de la Luz
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LightPercentaje")
	float CurrentPercentage;


public:	
	// Sets default values for this actor's properties
	AEC_SoulLight();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	//FUNCION - DISMINUIR POINTLIGHT
	UFUNCTION(BlueprintCallable)
	void DecreasePointLight(float DeltaTime);

	//FUNCION - Disminuir SPOTLIGHT
	UFUNCTION(BlueprintCallable)
	void DecreaseSpotLight(float DeltaTime);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//FUNCION: Obtener Porcentaje de Luz actual
	UFUNCTION(BlueprintCallable)
	float GetActualPercentage();

};
