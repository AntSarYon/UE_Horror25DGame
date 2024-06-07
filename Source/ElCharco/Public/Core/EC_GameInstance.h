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


public: //GETTERS Y SETTERS

	UFUNCTION(BlueprintCallable)
	FName GetCurrentLevelName() { return LastLevelName; };

	UFUNCTION(BlueprintCallable)
	void SetCurrentLevelName(FName NewLevelName) { LastLevelName = NewLevelName; };


public: // METODOS - ALMACENAMIENTO DE DATA

	UFUNCTION(BlueprintCallable)
	void SaveData();

	UFUNCTION(BlueprintCallable)
	void LoadData();

	UFUNCTION(BlueprintCallable)
	void ResetData();

};
