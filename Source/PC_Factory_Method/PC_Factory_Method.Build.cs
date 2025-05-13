// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PC_Factory_Method : ModuleRules
{
	public PC_Factory_Method(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" ,"HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
