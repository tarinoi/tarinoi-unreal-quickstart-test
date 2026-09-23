// An example of the quickstart with your own bindings registered.

#pragma once

#include "CoreMinimal.h"
#include "Ui/TarinoiQuickstartGameMode.h"

#include "MyQuickstartGameMode.generated.h"

/**
 * The quickstart, with this game's bindings registered. To use it, set it as the GameMode Override
 * in the level's World Settings, or as the Default GameMode in Project Settings > Maps & Modes.
 *
 * You can do the same from Blueprint: create a Blueprint class based on TarinoiQuickstartGameMode
 * and implement the Setup Bindings event.
 */
UCLASS()
class AMyQuickstartGameMode : public ATarinoiQuickstartGameMode
{
	GENERATED_BODY()

protected:
	/**
	 * Called once the runtime is configured and before any dialogue plays.
	 *
	 * "global" is the collection's machine identifier in Tarinoi, not its display label: authored
	 * expressions say Fn.global..., so that is what the binding is registered under. A mismatch
	 * shows up as an unbound-collection error when the dialogue runs.
	 *
	 * Tarinoi's own core functions (Fn.tarinoi.*) are not bound here: once you have synced and
	 * regenerated bindings, the scaffolded UTarinoiCoreFunctions is bound automatically, along with
	 * any generated variables class you leave unbound.
	 */
	virtual void SetupBindings_Implementation(UTarinoiRuntime* Runtime) override;
};
