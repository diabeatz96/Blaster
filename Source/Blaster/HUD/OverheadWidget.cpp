// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverheadWidget::SetDisplayText(FString Role, FString Name)
{
	DisplayText->SetText(FText::FromString(Role));
	NameText->SetText(FText::FromString(Name));
}

void UOverheadWidget::ShowPlayerOverHead(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch(RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	}
	
	FString RemoteRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);

	if(InPawn)
	{
		SetDisplayText(RemoteRoleString, "InPawnExists");
	} else
	{
		SetDisplayText(RemoteRoleString, "Name Not Found");

	}
	
}


void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
}
