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
	float Saved_LightCurrentPercentage;



public: //GETTERS Y SETTERS

	// NOMBRE DE ULTIMO NIVEL
	UFUNCTION(BlueprintCallable)
	FName Get_Saved_LastLevelName() { return Saved_LastLevelName; };

	UFUNCTION(BlueprintCallable)
	void Set_Saved_LastLevelName(FName NewLevelName) { Saved_LastLevelName = NewLevelName; };

	
	//PORCENTAJE DE LA LUZ 
	UFUNCTION(BlueprintCallable)
	float Get_Saved_LightCurrentPercentage() { return Saved_LightCurrentPercentage; };

	UFUNCTION(BlueprintCallable)
	void Set_Saved_LightCurrentPercentage(float NewLightPercentage) { Saved_LightCurrentPercentage = NewLightPercentage; };
	
};
