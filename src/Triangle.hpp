#ifndef TRIANGLE_HPP 
#define TRIANGLE_HPP

#include <SDL2/SDL.h>
#include "Shape.hpp"

class Triangle : public Shape {
    public:
        Triangle(SDL_Renderer* gRenderer, int gridSize);

        void drawTriangle();

    private:
        int sideLength;
        SDL_Vertex triangleVertices[3];

        void setColorVertex(int vIndex);

};

#endif 