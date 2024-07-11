// This project is created for entertainment and is totally free.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EC_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ELCHARCO_API UEC_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public: //CONSTRUCTOR
	UEC_GameInstance();


protected: //PROPIEDADES

	// NOMBRE DE SLOT DE GUARDADO
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SaveSystem")
	FString SaveSlotName;

	// NOMBRE DE NIVEL ACTUAL
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelData")
	FName LastLevelName;


	//INTENSIDAD INICIAL DEL SPOTLIGHT DEL ALMA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightsData")
	float SpotLightOriginalIntensity;

	//INTENSIDAD INICIAL DEL POINTLIGHT DEL ALMA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightsData")
	float PointLightOriginalIntensity;


	//PORCENTAJE DE INTENSIDAD DEL SPOTLIGHT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightsData")
	float SpotLightCurrentPercentage;

	//PORCENTAJE DE INTENSIDAD DEL POINTLIGHT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightsData")
	float PointLightCurrentPercentage;


public: //GETTERS Y SETTERS

	//NOMBRE DEL ULTIMO NIVEL
	UFUNCTION(BlueprintCallable)
	FName GetCurrentLevelName() { return LastLevelName; };

	UFUNCTION(BlueprintCallable)
	void SetCurrentLevelName(FName NewLevelName) { LastLevelName = NewLevelName; };


	//Porcentaje actual del SpotLight
	UFUNCTION(BlueprintCallable)
	float GetSpotLightCurrentPercentage() { return SpotLightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void SetSpotLightCurrentPercentage(float NewSpotLightPercentage) { SpotLightCurrentPercentage = NewSpotLightPercentage; };


	//Porcentaje actual del PointLight
	UFUNCTION(BlueprintCallable)
	float GetPointLightCurrentPercentage() { return PointLightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void SetPointLightCurrentPercentage(float NewPointLightPercentage) { PointLightCurrentPercentage = NewPointLightPercentage; };


public: // METODOS - ALMACENAMIENTO DE DATA

	UFUNCTION(BlueprintCallable)
	void SaveData();

	UFUNCTION(BlueprintCallable)
	void LoadData();

	UFUNCTION(BlueprintCallable)
	void ResetData();

};
