#include "GamePiece.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Shape.hpp"

using namespace std;

GamePiece::GamePiece(SDL_Renderer* gRenderer, int gSize) {
    renderer = gRenderer;
    gridSize = gSize;

    createGamePiece();
}

void GamePiece::displayGamePiece() {
    for (const auto& s: shapes) {
        s->drawShape(); 
    }
}

void GamePiece::moveGamePiece(int dir) {
    for (const auto& s: shapes) {
        s->moveShape(dir); 
    }
}


void GamePiece::createGamePiece() {
    //this is the default game piece
    auto s = make_unique<Square>(renderer, gridSize);
    auto t1 = make_unique<Triangle>(renderer, gridSize, UP);
    auto t2 = make_unique<Triangle>(renderer, gridSize, RIGHT);
    auto t3 = make_unique<Triangle>(renderer, gridSize, LEFT);
    auto t4 = make_unique<Triangle>(renderer, gridSize, DOWN);

    SDL_Color pink = {255, 186, 181};
    s->setColor(pink);

    s->setPos(5*gridSize, 5*gridSize);
    //triangles surrounds the square
    t1->setPos(s->getX(), s->getY() - gridSize); // above
    t2->setPos(s->getX() + gridSize, s->getY()); // right
    t3->setPos(s->getX() - gridSize, s->getY()); //left
    t4->setPos(s->getX(), s->getY() + gridSize); // below

    shapes.push_back(std::move(s));
    shapes.push_back(std::move(t1));
    shapes.push_back(std::move(t2));
    shapes.push_back(std::move(t3));
    shapes.push_back(std::move(t4));
}
