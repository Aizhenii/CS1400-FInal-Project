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
        void createGamePiece(int x, int y);
        bool mouseOverGamePiece();
        void highlightGamePiece();
    
    private:
        SDL_Renderer* renderer;
        std::vector<std::unique_ptr<Shape>> shapes;

        SDL_Rect horizontalBorder;
        SDL_Rect verticalBorder;
   
        int gridSize;
        bool mouseOver = false;
        
        enum ShapeDirection {
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };

        void calculateBorder();
};

#endif 
