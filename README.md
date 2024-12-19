This is a simple two player stategy game and my first time ever using C++.

### Rules
You have a set of game pieces on your side. Each turn you can only move each piece 2 grids. 
You can end your turn any time by pressing the red button on the side. 
When triangles collide with each other, both of them will disappear. When a triangle hits a square, then the game piece will disappear. 

You lose if all your game pieces are gone.

Have fun :)

### Mac set up for VS Code
Install CMake and SDL2 via homebrew in the terminal using these commands. 
```
brew install cmake
brew install sdl2
```
Install nessary extensions. (C/C++, CMake Tools)
Create a build directory. 
```
mkdir build
cd build
```
Generate build files.
```
cmake ..
```
Build the project.
```
cmake --build .
```

You can run the project by clicking the run button at the very bottom or running this in the terminal in the build directory. 
```
./finalproject
```
### Windows set up for Visual Studio
Install [SDL2](https://github.com/libsdl-org/SDL/releases).
Visual Studio natively supports [CMake](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) with Desktop development with C++. 

In CMakeLists.txt, update the following lines to your SDL2 paths. Replace file path inside the quotations that are BEFORE the CACHE PATH and CACHE FILEPATH.
Note that the directory ends with an include folder and the library ends with and SDL2.lib file.
```
set(SDL2_INCLUDE_DIR "C:/libs/SDL2/include" CACHE PATH "Set path to SDL2 include directory (e.g., C:/libs/SDL2/include)")
set(SDL2_LIBRARY "C:/libs/SDL2/lib/x64/SDL2.lib" CACHE FILEPATH "Set path to SDL2 library (e.g., C:/libs/SDL2/lib/x64/SDL2.lib)")
```
Open Developer Command Prompt for Visual Studio. Run the following command to generate a solution file (.sln). 
```
cmake -S . -B build -G "Visual Studio 16 2019"
```

Build the proect by selecting Build > Build Solution (or press Ctrl + Shift + B).
Run the project by selecting Debug > Start Without Debugging (or press Ctrl + F5).


