// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "Blaster/HUD/OverheadWidget.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

	APlayerState *PlayerState= NewPlayer->GetPlayerState<APlayerState>();
	FString Name = PlayerState->GetPlayerName();
	
	if (NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		
		if (World)
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
		}
	}
}

