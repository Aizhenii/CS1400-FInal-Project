#include "Shape.hpp"
#include <iostream>

Shape::Shape(SDL_Renderer* gRenderer, int gSize) {
    renderer = gRenderer;
    gridSize = gSize;

    // lets color originally be white
    setColor(originalColor);

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

SDL_Color Shape::getColor() {
    return color;
}

SDL_Color Shape::getOriginalColor() {
    return originalColor;
}

void Shape::moveShape(int dir) {

    switch(dir) {
        case UP: // up
            y -= gridSize;
            break;
        case DOWN: // down
            y += gridSize;
            break;
        case LEFT: // left
            x -= gridSize;
            break;
        case RIGHT: // right
            x += gridSize;
            break;
    }

}

bool Shape::collides(Shape& s) {
    if (x == s.getX() && y == s.getY()) {
        return true;
    }
    
    return false;
}

