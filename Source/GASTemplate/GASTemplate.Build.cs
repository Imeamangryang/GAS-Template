// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GASTemplate : ModuleRules
{
	public GASTemplate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 모듈의 기본 경로를 설정합니다. (나중에 C++ 파일들을 폴더에 추가할 때 경로를 자동적으로 인식하도록 합니다.)
        PublicIncludePaths.AddRange(new string[] { "GASTemplate" });

        // Gameplay Ability System에 필요한 모듈을 추가합니다. ("GameplayAbilities", "GameplayTags", "GameplayTasks")
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput"});

        PrivateDependencyModuleNames.AddRange(new string[] {
            "GameplayAbilities",
            "GameplayTasks",
            "GameplayTags"
        });
    }
}
