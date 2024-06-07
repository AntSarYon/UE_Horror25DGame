// This project is created for entertainment and is totally free.

using UnrealBuildTool;
using System.Collections.Generic;

public class ElCharcoEditorTarget : TargetRules
{
	public ElCharcoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "ElCharco" } );
	}
}
