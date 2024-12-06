#ifndef TRIANGLE_HPP 
#define TRIANGLE_HPP

#include <SDL2/SDL.h>
#include "Shape.hpp"

class Triangle : public Shape {
    public:
        Triangle(SDL_Renderer* gRenderer, int gridSize, int dir);

        void drawShape() override;
        void moveShape(int dir) override;
        void setPos(int xPos, int yPos) override;


    private:
        int sideLength;
        int direction;
        SDL_Vertex triangleVertices[3];

        void setColorVertex(int vIndex);
        void setVertexPosition(int vIndex, int x, int y);
        void rotateTriangle(int dir);

};

#endif 