using UnrealBuildTool;

public class TarinoiQuickstartTarget : TargetRules
{
	public TarinoiQuickstartTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("TarinoiQuickstart");
	}
}
