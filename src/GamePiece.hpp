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
        void selectGamePiece(bool sel);
        void checkCollision(GamePiece& gp);
        bool getAlive(); // checks if the base (or square in this case is hit) in collision, gp dies if base is erased
        void setAlive(bool a);
        std::vector<std::unique_ptr<Shape>>& getShapeVector();
        
    
    private:
        SDL_Renderer* renderer;
        std::vector<std::unique_ptr<Shape>> shapes;

        SDL_Rect horizontalBorder;
        SDL_Rect verticalBorder;
   
        int gridSize;
        bool mouseOver = false;
        bool selected = false;
        bool alive = true;

        int moveLimit = 2;
        
        enum ShapeDirection {
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };

        void calculateBorder();
};

#endif 
