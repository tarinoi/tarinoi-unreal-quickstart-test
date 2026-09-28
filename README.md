# Tarinoi for Unreal Engine: Quickstart

A minimal Unreal Engine project that plays dialogue authored in [Tarinoi](https://tarinoi.com),
using the [Tarinoi Unreal plugin](https://github.com/tarinoi/tarinoi-unreal-plugin).

Clone it, point it at your Tarinoi project, and press Play. To add Tarinoi to a project you
already have, install the plugin directly and follow the
[Unreal plugin guide](https://tarinoi.app/docs/plugins/unreal.html).

Requires **Unreal Engine 5.8** and a C++ toolchain (Xcode on macOS, Visual Studio on Windows).

> **Status: early development.** Version 0.2.0, matching the plugin. The API is not yet stable
> and will change before 1.0.

## Running it

1. Clone the plugin **next to** this repository, so the two folders are siblings:

   ```
   git clone https://github.com/tarinoi/tarinoi-unreal-plugin.git
   git clone https://github.com/tarinoi/tarinoi-unreal-quickstart-test.git
   ```

   The project finds it there (`AdditionalPluginDirectories` in `TarinoiQuickstart.uproject`).
   Check out the same tag in both, e.g. `v0.2.0`.
   Or clone the plugin into this project's `Plugins/` folder instead, and delete that line.
2. Open `TarinoiQuickstart.uproject` and let it build.
3. **Edit > Project Settings > Plugins > Tarinoi**: paste your project's documents endpoint into
   **API Path**, then click **Set...** next to API Token and paste a token from your Tarinoi
   project's Integrations page.
4. **Tools > Tarinoi > Sync**, then **Tools > Tarinoi > Regenerate Bindings**.
5. Close the editor and build the project from your IDE (or reopen it and let it rebuild):
   Live Coding cannot add the new classes codegen wrote.
6. Press **Play**.

You get a list of every entry point in your content. Pick one and it plays: **Space**
continues, number keys choose, **Esc** ends the dialogue. If the list is empty, the Output
Log and the Tarinoi message log say why; the
[troubleshooting table](https://tarinoi.app/docs/plugins/unreal.html#troubleshooting) covers the
usual causes.

## What is in here

Almost nothing, deliberately. There is no level and no Blueprint: the project's default game
mode is the plugin's `TarinoiQuickstartGameMode`, which builds its interface at runtime, so any
level plays as the quickstart. That keeps this repository about *using* Tarinoi rather than
about a particular UI.

`Source/TarinoiQuickstart` holds one example: `MyQuickstartGameMode` registers hand-written
bindings (`MyBindings.h`) in its `SetupBindings`. To try it, set it as the default game mode
under **Project Settings > Maps & Modes**. Everything you leave unbound that codegen supplies,
such as the generated variables classes and the core functions scaffold, is bound
automatically.

## Not in version control

Three things are local to your checkout, and gitignored:

- `Config/DefaultTarinoi.ini`: points at a specific Tarinoi project.
- `Source/TarinoiQuickstart/Tarinoi/`: bindings generated from that project's content, and the
  core functions scaffold.
- `Content/Tarinoi/`: the exported offline snapshot.

Your API token is never in the project at all: it is stored in your user folder, so it cannot
be committed or packaged.

## Documentation

- **[Unreal plugin guide](https://tarinoi.app/docs/plugins/unreal.html)**: the full guide
- [What the plugins do and don't do](https://tarinoi.app/docs/plugins/)
- [Writing your own integration](https://tarinoi.app/docs/plugins/writing_your_own.html)

## License

MIT; see [`LICENSE.md`](LICENSE.md).
