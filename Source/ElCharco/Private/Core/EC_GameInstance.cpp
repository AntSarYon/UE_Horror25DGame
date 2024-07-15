// This project is created for entertainment and is totally free.

#include "Core/EC_GameInstance.h"
#include "SaveSystem/EC_SaveGame.h"
#include "Kismet/GameplayStatics.h"


UEC_GameInstance::UEC_GameInstance()
{
	//Inicializamos nombre del Slot de Guardado de datos
	SaveSlotName = "EC_SaveData";

	//Inicializamos el nombre de Ultimo Nivel
	LastLevelName = "Playground";

	//Inicializamos el porcentaje de la Luz del Alma
	LightCurrentPercentage = 100;

}

//-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+

void UEC_GameInstance::SaveData()
{
	//Inicializamos un SaveObject en Nulo
	USaveGame* SaveGameObject = nullptr;

	//Revisamos si existe Data ya guardada con el SlotName que definimos al comienzo
	bool bExistData = UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0);

	//Si existe Data
	if (bExistData)
	{
		//Le cargamos al SaveObject la Data ya existente en el Slot...
		SaveGameObject = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0);
	}

	//En caso aun no haya Datos
	else
	{
		//Creamos un SaveObject que sea de la CLase de SaveGame creada
		SaveGameObject = UGameplayStatics::CreateSaveGameObject(UEC_SaveGame::StaticClass());
	}

	//Si el paso anterior salio bien, ya sea que el SaveObject es nuevo, o cargado...
	if (IsValid(SaveGameObject)) 
	{
		//Casteamos el SaveGameObject a nuestra clase de SaveObject creadA
		// (Recuerda que inicio como un SaveObject Estandar)
		UEC_SaveGame* SaveFile = Cast<UEC_SaveGame>(SaveGameObject);

		//Si el Casteo fue exitoso...
		if (IsValid(SaveFile)) 
		{
			//Actualizamos toda la Data (Del GameInstance al Save)
			SaveFile->Set_Saved_LastLevelName(LastLevelName);
			SaveFile->Set_Saved_LightCurrentPercentage(LightCurrentPercentage);
			// (...Poner aqui mas variables cuando sea necesario ...)
			// (...)

			//GUARDAMOS LA DATA FINAL en el Slot
			UGameplayStatics::SaveGameToSlot(SaveFile, SaveSlotName, 0);

		}
	}
}

//-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+

void UEC_GameInstance::LoadData()
{
	//Inicializamos un SaveObject en Nulo
	USaveGame* SaveGameObject = nullptr;

	//Revisamos si existe Data ya guardada con el SlotName que definimos al comienzo
	bool bExistData = UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0);

	//Si existe Data
	if (bExistData)
	{
		//Le cargamos al SaveObject la Data ya existente en el Slot...
		SaveGameObject = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0);
	}
	//En caso aun no haya Datos
	else
	{
		//Creamos un SaveObject que sea de la CLase de SaveGame creada
		SaveGameObject = UGameplayStatics::CreateSaveGameObject(UEC_SaveGame::StaticClass());
	}

	if (IsValid(SaveGameObject)) 
	{
		//Casteamos el SaveGameObject a nuestra clase de SaveObject creadA
		UEC_SaveGame* SaveFile = Cast<UEC_SaveGame>(SaveGameObject);

		//Si el casteo salio bien
		if (IsValid(SaveFile)) 
		{
			//Actualizamos las variables del GameInstance en base a los datos del SaveFile
			SetCurrentLevelName(SaveFile->Get_Saved_LastLevelName());
			SetLightCurrentPercentage(SaveFile->Get_Saved_LightCurrentPercentage());
			// (...Poner aqui mas variables cuando sea necesario ...)
			// (...)
		}
	}
}

//-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+

void UEC_GameInstance::ResetData()
{
	//Reiniciamos los Valores de las variables

	SetCurrentLevelName("Playground");
	SetLightCurrentPercentage(100);
}
