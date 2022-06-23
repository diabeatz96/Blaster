// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta=(BindWidget))
	UTextBlock* DisplayText;

	
	UPROPERTY(meta=(BindWidget))
	UTextBlock* NameText;

	void SetDisplayText(FString Role, FString Name);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerOverHead(APawn* InPawn);

	/*
	FString UserName = "Adam";

	[[nodiscard]] FString& GetUserName()
	{
		return UserName;
	}

	void SetUserName(const FString& Name)
	{
		this->UserName = UserName;
	}
*/

protected:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	
};
