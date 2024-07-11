// This project is created for entertainment and is totally free.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EC_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ELCHARCO_API UEC_SaveGame : public USaveGame
{
	GENERATED_BODY()
	
public: //VARIABLES DE ALMACENAMIENTO DE DATOS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Data")
	FName Saved_LastLevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Data")
	float Saved_SpotLightCurrentPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saved Data")
	float Saved_PointLightCurrentPercentage;


public: //GETTERS Y SETTERS

	// NOMBRE DE ULTIMO NIVEL
	UFUNCTION(BlueprintCallable)
	FName Get_Saved_LastLevelName() { return Saved_LastLevelName; };

	UFUNCTION(BlueprintCallable)
	void Set_Saved_LastLevelName(FName NewLevelName) { Saved_LastLevelName = NewLevelName; };

	
	//PORCENTAJE DE LA SPOT LIGHT 
	UFUNCTION(BlueprintCallable)
	float Get_Saved_SpotLightCurentPercentage() { return Saved_SpotLightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void Set_Saved_SpotLightCurrentPercentage(float NewSpotLightPercentage) { Saved_SpotLightCurrentPercentage = NewSpotLightPercentage; };


	//PORCENTAJE DE LA POINT LIGHT
	UFUNCTION(BlueprintCallable)
	float Get_Saved_PointLightCurrentPercentage() { return Saved_PointLightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void Set_Saved_PointLightCurrentPercentage(float NewPointLightPercentage) { Saved_PointLightCurrentPercentage = NewPointLightPercentage; };

	
};
