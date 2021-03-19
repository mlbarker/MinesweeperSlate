// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
    
}

void AMenuPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UE_LOG(LogTemp, Warning, TEXT("SetupInputComponent()"));

    if (InputComponent)
    {
        InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
    }
}

void AMenuPlayerController::OpenMenu()
{
    AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD());

    if (MenuHUD)
    {
        MenuHUD->ShowHUD();
        UE_LOG(LogTemp, Warning, TEXT("Show the Menu"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("MenuHUD is nullptr"));
    }
}

