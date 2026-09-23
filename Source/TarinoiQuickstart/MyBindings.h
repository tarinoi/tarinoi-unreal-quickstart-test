// An example of registering your own game's bindings with Tarinoi.

#pragma once

#include "Bindings/TarinoiBindings.h"
#include "CoreMinimal.h"

#include "MyBindings.generated.h"

/**
 * The game state an author reads and writes as Var.global.*
 *
 * Written by hand, so this example builds before you have synced anything. Tarinoi reads and writes
 * these properties by the authored name (met_the_narrator finds MetTheNarrator). With real content,
 * run Tools > Tarinoi > Regenerate Bindings instead and use the generated UTarinoiGlobalVariables:
 * it has a typed property for every variable your authors declared, and stays in step with them.
 */
UCLASS()
class UMyVariables : public UTarinoiVariableCollection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Example")
	bool MetTheNarrator = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Example")
	double Courage = 1.0;
};

/**
 * The functions an author calls as Fn.global.*
 *
 * Tarinoi finds these UFUNCTIONs by name. That suits a prototype; the generated
 * UTarinoiGlobalFunctions is better for real work, because a function renamed in Tarinoi becomes a
 * compile error rather than a runtime one.
 *
 * Note SetFlag: a Var.* argument arrives as a reference, not a value, which is what lets a function
 * write back to it. Reading with ToBool/ToNumber goes through the reference either way.
 */
UCLASS()
class UMyFunctions : public UTarinoiFunctionCollection
{
	GENERATED_BODY()

public:
	/** Fn.global.CheckFlag(Var.global.met_the_narrator) */
	UFUNCTION()
	bool CheckFlag(const FTarinoiValue& Flag) { return Flag.ToBool(); }

	/** Fn.global.SetFlag(Var.global.met_the_narrator) */
	UFUNCTION()
	void SetFlag(const FTarinoiValue& Flag) { Flag.Write(FTarinoiValue::MakeBool(true)); }

	/** Fn.global.AdjustCounter(Var.global.courage, 1) */
	UFUNCTION()
	void AdjustCounter(const FTarinoiValue& Counter, double Delta)
	{
		Counter.Write(FTarinoiValue::MakeNumber(Counter.ToNumber() + Delta));
	}
};
