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


public: //GETTERS Y SETTERS

	UFUNCTION(BlueprintCallable)
	FName Get_Saved_LastLevelName();

	UFUNCTION(BlueprintCallable)
	void Set_Saved_LastLevelName(FName NewLevelName) { Saved_LastLevelName = NewLevelName; };


};
