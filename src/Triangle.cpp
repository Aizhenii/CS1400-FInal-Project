#include "Triangle.hpp"

Triangle::Triangle(SDL_Renderer* gRenderer, int gridSize) : Shape(gRenderer, gridSize) {
    sideLength = gridSize;
}

// drawing a triangle in sdl is so complicated
void Triangle::drawTriangle() {
    triangleVertices[0].position.x = x + sideLength/2;
    triangleVertices[0].position.y = y;
    setColorVertex(0);

    triangleVertices[1].position.x = x;
    triangleVertices[1].position.y = y + sideLength;
    setColorVertex(1);

    triangleVertices[2].position.x = x + sideLength;
    triangleVertices[2].position.y = y + sideLength;
    setColorVertex(2);

    SDL_RenderGeometry(renderer, NULL, triangleVertices, 3, NULL, 3);
}

//x, y pos of shape is that top right corner it seems
void Triangle::setColorVertex(int vIndex) {
    triangleVertices[vIndex].color.r = color.r;
    triangleVertices[vIndex].color.g = color.g;
    triangleVertices[vIndex].color.b = color.b;
    triangleVertices[vIndex].color.a = color.a;
}