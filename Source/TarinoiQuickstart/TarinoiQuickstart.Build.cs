using UnrealBuildTool;

public class TarinoiQuickstart : ModuleRules
{
	public TarinoiQuickstart(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "Tarinoi" });
	}
}
