#include "Shape.hpp"
#include <iostream>

Shape::Shape(SDL_Renderer* gRenderer, int gSize) {
    renderer = gRenderer;
    gridSize = gSize;
    // lets color originally be white
    color.r = 255;
    color.g = 255;
    color.b = 255;

    // set original posiiton to 0, 0
    setPos(0, 0);
}

void Shape::setPos(int xPos, int yPos) {
    x = xPos;
    y = yPos;
}

void Shape::setColor(SDL_Color c) {
    color = c;
}

void Shape::moveShape(int dir) {
    //int movementSize = numGrids//when to use pointers? 

    switch(dir) {
        case 0:
            y += gridSize;
            break;
        case 1:
            y -= gridSize;
            break;
        case 2:
            x -= gridSize;
            break;
        case 3:
            x += gridSize;
            break;
    }

}

