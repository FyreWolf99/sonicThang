# Sonic Thing

## Dependancies
- GIT <https://git-scm.com/>
- SDL2 <https://www.libsdl.org/>
- CMAKE <https://cmake.org/>

## Build Directions

### Linux
1. Install dependancies
	- If on debian/ubuntu derivitave, run `sudo apt install libsdl2-dev cmake git g++`
	- If on Arch derivative, run `sudo pacman -S sdl2 cmake git base-devel`
2. Clone the project with `git clone --recursive https://github.com/FyreWolf99/sonicThang`
3. `cd sonicThang`
4. `mkdir build; cd build`
5. `cmake ..`
6. `make -j4`

### Windows
**This will be a rough guide, as I haven't a clue how windows works**

1. Download and install CMAKE from <https://cmake.org/>
2. Download and install SDL2 from <https://www.libsdl.org/>
3. Download and install GIT from <https://git-scm.com/>
4. Open git bash and run `git clone --recursive https://github.com/FyreWolf99/sonicThang`
5. Run the following:
	- `cd sonicThang/`
	- `mkdir build`
	- `cd build/`
	- `cmake ..` **This may be wrong**
6. Open the resulting .vsproj file in Visual Studio

### OSX
**Again, I haven't a clue**

1. Download and install CMAKE from <https://cmake.org/>
2. Download and install SDL2 from <https://www.libsdl.org/>
3. Download and install GIT from <https://git-scm.com/>
4. Open a terminal and run `git clone --recursive https://github.com/FyreWolf99/sonicThang`
4. Run the following:
	- `cd sonicThang/`
	- `mkdir build`
	- `cd build/`
	- `cmake ..` **This may be wrong**
5. Open the resulting .xcodeproj file in xcode