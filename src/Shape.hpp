#ifndef SHAPE_HPP 
#define SHAPE_HPP

#include <SDL2/SDL.h> 

class Shape {
    public:
        // Constructor
        Shape(SDL_Renderer* gRenderer, int gSize);

        void setColor(SDL_Color c);

        virtual ~Shape() = default;
        virtual void drawShape() = 0; // = 0 since there is nothing declared in the base drawShape function
        virtual void moveShape(int dir);
        virtual void setPos(int xPos, int yPos);

        int getX();
        int getY();

    protected:
        SDL_Renderer* renderer;
        SDL_Color color;
        int gridSize;
        int x;
        int y;
};

#endif 
