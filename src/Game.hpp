#ifndef GAME_HPP 
#define GAME_HPP

#include <SDL2/SDL.h> 

class Game {
    public: 
        Game(SDL_Renderer* gRenderer, int screenWidth, int screenHeight);

        // draw the grid into the texture
        void drawGrid();

        // display the grid texture
        void showGrid(); 

    private:
        SDL_Renderer* renderer;
        int sWidth;
        int sHeight;
        SDL_Texture* gridTexture; // Creating a grid texture that we can reuse

};

#endif 
