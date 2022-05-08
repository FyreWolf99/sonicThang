# Sonic Thing

## Prerequesites
- SDL2 <https://www.libsdl.org/>
- CMAKE <https://cmake.org/>

## Build Directions

1. Download the project with `git clone --recursive https://github.com/FyreWolf99/sonicThang`
2. OS specific instructions below

### Linux
1. Install SDL2 and CMAKE
	- If on debian/ubuntu derivitave, run `sudo apt install libsdl2-dev cmake g++`
	- If on Arch derivative, run `sudo pacman -S sdl2 cmake base-devel`
2. `mkdir build; cd build`
3. `cmake ..`
4. `make -j4`

### Windows
**This will be a rough guide, as I haven't a clue how windows works**

1. Download and install CMAKE from <https://cmake.org/>
2. Download and install SDL2 from <https://www.libsdl.org/>
3. Open the project in cmd
4. Run the following:
	- `mkdir build`
	- `cd build\`
	- `cmake ..` I think, but I have no clue from this point
5. Then open the resulting .vsproj file in visual studio *I think*