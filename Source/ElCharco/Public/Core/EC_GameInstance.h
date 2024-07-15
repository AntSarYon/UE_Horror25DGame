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

	//PORCENTAJE DE INTENSIDAD DEL SPOTLIGHT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightsData")
	float LightCurrentPercentage;


public: //GETTERS Y SETTERS

	//NOMBRE DEL ULTIMO NIVEL
	UFUNCTION(BlueprintCallable)
	FName GetCurrentLevelName() { return LastLevelName; };

	UFUNCTION(BlueprintCallable)
	void SetCurrentLevelName(FName NewLevelName) { LastLevelName = NewLevelName; };


	//Porcentaje actual del SpotLight
	UFUNCTION(BlueprintCallable)
	float GetLightCurrentPercentage() { return LightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void SetLightCurrentPercentage(float NewLightPercentage) { LightCurrentPercentage = NewLightPercentage; };


public: // METODOS - ALMACENAMIENTO DE DATA

	UFUNCTION(BlueprintCallable)
	void SaveData();

	UFUNCTION(BlueprintCallable)
	void LoadData();

	UFUNCTION(BlueprintCallable)
	void ResetData();

};
