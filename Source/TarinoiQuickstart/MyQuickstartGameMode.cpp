#include "MyQuickstartGameMode.h"

#include "Bindings/TarinoiBindings.h"
#include "MyBindings.h"
#include "TarinoiRuntime.h"

void AMyQuickstartGameMode::SetupBindings_Implementation(UTarinoiRuntime* Runtime)
{
	Runtime->GetBindings()->BindVariables(TEXT("global"), NewObject<UMyVariables>(this));
	Runtime->GetBindings()->BindFunctions(TEXT("global"), NewObject<UMyFunctions>(this));
}
