#pragma once

namespace DebugHelper
{
	static void Log(const FString& Message, const FColor& Color = FColor::MakeRandomColor(), int Key = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, 7.0f, Color, Message);
			UE_LOG(LogTemp, Log, TEXT("%s"), *Message);
		}
	}
}
