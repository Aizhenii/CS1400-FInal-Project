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

int Shape::getX() {
    return x;
}

int Shape::getY() {
    return y;
}

void Shape::setColor(SDL_Color c) {
    color = c;
}

void Shape::moveShape(int dir) {

    switch(dir) {
        case 0: // up
            y += gridSize;
            break;
        case 1: // down
            y -= gridSize;
            break;
        case 2: // left
            x -= gridSize;
            break;
        case 3: // right
            x += gridSize;
            break;
    }

}

