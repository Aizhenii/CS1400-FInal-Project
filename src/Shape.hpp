#ifndef SHAPE_HPP 
#define SHAPE_HPP

#include <SDL2/SDL.h> 

class Shape {
    public:
        // Constructor
        Shape(SDL_Renderer* gRenderer, int gSize);

        void setPos(int xPos, int yPos);
        void setColor(SDL_Color c);
        void moveShape(int dir);

    protected:
        SDL_Renderer* renderer;
        SDL_Color color;
        int gridSize;
        int x;
        int y;
};

#endif 
