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



