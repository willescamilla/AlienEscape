// Copyright Epic Games, Inc. All Rights Reserved.

#include "AlienEscapeGameMode.h"
#include "AlienEscapeCharacter.h"

AAlienEscapeGameMode::AAlienEscapeGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AAlienEscapeCharacter::StaticClass();	
}
