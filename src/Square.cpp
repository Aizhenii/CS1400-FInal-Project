#include "Square.hpp"
#include <iostream>

Square::Square(SDL_Renderer* gRenderer, int gridSize) : Shape(gRenderer, gridSize) {
    sideLength = gridSize;
}

void Square::drawSquare() {
    SDL_Rect rect = { x, y, sideLength, sideLength };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
}
