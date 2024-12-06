#ifndef GAMEPIECE_HPP 
#define GAMEPIECE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "Shape.hpp"


class GamePiece {
    public:
        GamePiece(SDL_Renderer* gRenderer, int gSize);

        void displayGamePiece();
        void moveGamePiece(int dir);
    
    private:
        SDL_Renderer* renderer;
        std::vector<std::unique_ptr<Shape>> shapes;
        int gridSize;

        void createGamePiece();

        enum ShapeDirection {
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };
};

#endif 
