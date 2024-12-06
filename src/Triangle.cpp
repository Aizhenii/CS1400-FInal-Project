#include "Triangle.hpp"

Triangle::Triangle(SDL_Renderer* gRenderer, int gridSize, int dir) : Shape(gRenderer, gridSize) {
    sideLength = gridSize;
    direction = dir;

    rotateTriangle(dir);

}

// drawing a triangle in sdl is so complicated
//maybe it would be better to create a texture for tiranlge
void Triangle::drawShape() {

    SDL_RenderGeometry(renderer, NULL, triangleVertices, 3, NULL, 3);
}

//x, y pos of shape is that top right corner it seems
void Triangle::setColorVertex(int vIndex) {
    triangleVertices[vIndex].color.r = color.r;
    triangleVertices[vIndex].color.g = color.g;
    triangleVertices[vIndex].color.b = color.b;
    triangleVertices[vIndex].color.a = color.a;
}

void Triangle::setVertexPosition(int vIndex, int x, int y) {
    triangleVertices[vIndex].position.x = x;
    triangleVertices[vIndex].position.y = y;
}

void Triangle::rotateTriangle(int dir) {

    // ugly code idk how to make it better :(
    switch (dir) {
        case DOWN:
            setVertexPosition(0, x + sideLength/2, sideLength);
            setColorVertex(0);

            setVertexPosition(1, x, y);
            setColorVertex(1);

            setVertexPosition(2, x + sideLength, y);
            setColorVertex(2);
            break;

        case UP:
            setVertexPosition(0, x + sideLength/2, y);
            setColorVertex(0);

            setVertexPosition(1, x, y + sideLength);
            setColorVertex(1);

            setVertexPosition(2, x + sideLength, y + sideLength);
            setColorVertex(2);
            break;

        case LEFT:
            setVertexPosition(0, x, y + sideLength/2);
            setColorVertex(0);

            setVertexPosition(1, x + sideLength, y);
            setColorVertex(1);

            setVertexPosition(2, x + sideLength,  y + sideLength);
            setColorVertex(2);
            break;

        case RIGHT:
            setVertexPosition(0, x + sideLength, y + sideLength/2);
            setColorVertex(0);

            setVertexPosition(1, x, y);
            setColorVertex(1);

            setVertexPosition(2, x, y + sideLength);
            setColorVertex(2);
            break;

    }
}

void Triangle::moveShape(int dir) {
    Shape::moveShape(dir); 
    
    rotateTriangle(direction);
}

void Triangle::setPos(int xPos, int yPos) {
    Shape::setPos(xPos, yPos); 

    // Recalculate vertex positions
    rotateTriangle(direction);
}