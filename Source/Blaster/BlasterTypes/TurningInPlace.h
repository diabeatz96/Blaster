#pragma once

UENUM(BluePrintType)
enum class ETurningInPlace : uint8
{
	ETIP_Left UMETA(DisplayName = "Turning Left"),
	ETIP_Right UMETA(DisplayName = "Turning Right"),
	ETIP_NotTurning UMETA(DisplaName = "Not Turning"),
	ETIP_MAX UMETA(DisplayName = "DefaultMAX")
};
