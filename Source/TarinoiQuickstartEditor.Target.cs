using UnrealBuildTool;

public class TarinoiQuickstartEditorTarget : TargetRules
{
	public TarinoiQuickstartEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("TarinoiQuickstart");
	}
}
