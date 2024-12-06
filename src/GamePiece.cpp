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
    auto t1 = make_unique<Triangle>(renderer, gridSize);
    t1->setPos(t1->getX(), s->getY() + gridSize); // sets the triangle position above the square
    shapes.push_back(std::move(s));
    shapes.push_back(std::move(t1));
}
