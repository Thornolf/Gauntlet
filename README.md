# Gauntlet

A 3D Gauntlet-like game for up to 4 players made with Ogre3D, OIS and SFML
(Epitech Indie Studio project, 2017).

## Download (Windows)

Every push builds the game on GitHub: open the **Actions** tab, pick the
latest *Build* run and download the **Gauntlet-windows** artifact. It contains:

- `Gauntlet-Setup.exe`: installer (no admin rights needed), adds Start menu
  and desktop shortcuts.
- `Gauntlet-portable.zip`: unzip anywhere and run `Gauntlet.exe`.

Pushing a tag such as `v1.0.0` also publishes both files on the
repository's **Releases** page.

## Building

You need CMake ≥ 3.16 and a C++17 compiler. Boost is **not** needed anymore.

### Linux (Debian / Ubuntu)

```bash
sudo apt install build-essential cmake libogre-1.12-dev libois-dev libsfml-dev
```

```bash
cmake --preset linux
```

```bash
cmake --build --preset linux -j
```

```bash
./build/Gauntlet
```

Other distributions: install Ogre (1.12 or newer, with the Bites and Overlay
components), OIS and SFML 2 from your package manager, or use vcpkg as below.

### Windows

1. Install **Visual Studio 2022** with the *Desktop development with C++*
   workload (this includes CMake).
2. Install [vcpkg](https://learn.microsoft.com/vcpkg/get_started/get-started)
   and set the `VCPKG_ROOT` environment variable to its folder
   (the vcpkg shipped with Visual Studio works too).
3. From a *Developer PowerShell for VS 2022* in this folder:

```powershell
cmake --preset windows
```

```powershell
cmake --build --preset windows
```

```powershell
.\build\Release\Gauntlet.exe
```

The first configure builds Ogre, OIS and SFML through vcpkg (see
`vcpkg.json`), which takes a while. You can also simply open the folder in
Visual Studio and pick the *Windows (vcpkg)* preset.

## Packaging

```bash
cmake --install build --config Release --prefix my-game-folder
```

```bash
cd build && cpack -C Release
```

On Windows this produces `build/release/Gauntlet-Setup.exe` (needs
[NSIS](https://nsis.sourceforge.io)) and `build/release/Gauntlet-portable.zip`.

## Running

The game can be started from any directory: it switches to the repository
root to find `dist/media`, `resources.cfg`, `ogre.cfg` and `myKeyboard.cnf`.
Delete `ogre.cfg` to get the Ogre settings dialog back (resolution,
full screen, ...).

Key bindings are in `myKeyboard.cnf` (`<OIS key code> <player> <action>`).
