// This project is created for entertainment and is totally free.

using UnrealBuildTool;
using System.Collections.Generic;

public class ElCharcoTarget : TargetRules
{
	public ElCharcoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "ElCharco" } );
	}
}
