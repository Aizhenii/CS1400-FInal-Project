#ifndef SQUARE_HPP 
#define SQUARE_HPP

#include <SDL2/SDL.h>
#include "Shape.hpp"

class Square : public Shape {
    public:
        Square(SDL_Renderer* gRenderer, int gridSize);

        void drawSquare();

    private:
        int sideLength;

};

#endif 
