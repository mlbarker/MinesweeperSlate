// Copyright Epic Games, Inc. All Rights Reserved.


#include "MenuGameModeBase.h"
#include "MenuPlayerController.h"
#include "MenuHUD.h"

AMenuGameModeBase::AMenuGameModeBase()
{
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}

