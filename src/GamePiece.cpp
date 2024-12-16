#include "GamePiece.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Shape.hpp"

using namespace std;

GamePiece::GamePiece(SDL_Renderer* gRenderer, int gSize) {
    renderer = gRenderer;
    gridSize = gSize;
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

    calculateBorder();
}

void GamePiece::createGamePiece(int x, int y) {
    //this is the default game piece
    auto s = make_unique<Square>(renderer, gridSize); // a game piece base piece will also be at index 0
    auto t1 = make_unique<Triangle>(renderer, gridSize, UP);
    auto t2 = make_unique<Triangle>(renderer, gridSize, RIGHT);
    auto t3 = make_unique<Triangle>(renderer, gridSize, DOWN);
    auto t4 = make_unique<Triangle>(renderer, gridSize, LEFT);

    SDL_Color pink = {255, 186, 181};
    s->setColor(pink);

    s->setPos(x * gridSize, y * gridSize);

    //triangles surrounds the square
    t1->setPos(s->getX(), s->getY() - gridSize); // above
    t2->setPos(s->getX() + gridSize, s->getY()); // right
    t3->setPos(s->getX(), s->getY() + gridSize); // below
    t4->setPos(s->getX() - gridSize, s->getY()); //left

    //calculate border
    horizontalBorder.x = s->getX() - gridSize;   
    horizontalBorder.y = s->getY();           
    horizontalBorder.w = 3 * gridSize;                     
    horizontalBorder.h = gridSize;

    verticalBorder.x = s->getX();   
    verticalBorder.y = s->getY() - gridSize;           
    verticalBorder.w = gridSize;                     
    verticalBorder.h = 3 * gridSize;


    shapes.push_back(std::move(s));
    shapes.push_back(std::move(t1));
    shapes.push_back(std::move(t2));
    shapes.push_back(std::move(t3));
    shapes.push_back(std::move(t4));
}

bool GamePiece::mouseOverGamePiece() {
    // check if mouse position is inside the game piece
\
    //Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);

    //SDL_Color highlightColor = {71, 151, 222, 50};

    // make it so that the border is made of like 2 rectangles

    if ((x > verticalBorder.x && x < verticalBorder.x + verticalBorder.w) 
        && (y > verticalBorder.y && y < verticalBorder.y + verticalBorder.h)) {
        //vertical rectangle
        mouseOver = true;
    }
    else if ((x > horizontalBorder.x && x < horizontalBorder.x + horizontalBorder.w) 
        && (y > horizontalBorder.y && y < horizontalBorder.y + horizontalBorder.h)) {
        //horizontal rectangle
        mouseOver = true;
    }
    else {
        mouseOver = false;

    }

    return mouseOver;
        
}

void GamePiece::highlightGamePiece() {
    for (const auto& s: shapes) {
        SDL_Color highlightColor = {153, 214, 255};
        SDL_Color ogColor = s->getOriginalColor();

        highlightColor.r += ogColor.r;
        highlightColor.g += ogColor.g;
        highlightColor.b += ogColor.b;

        if (mouseOver || selected) {
            s->setColor(highlightColor);
        }
        else {
            s->setColor(ogColor);
            //std::cout<< "out" << endl;
        }

    }
}

void GamePiece::calculateBorder() {
    //calculate border
    const auto& s = shapes.at(0);

    horizontalBorder.x = s->getX() - gridSize;   
    horizontalBorder.y = s->getY();           
    horizontalBorder.w = 3 * gridSize;                     
    horizontalBorder.h = gridSize;

    verticalBorder.x = s->getX();   
    verticalBorder.y = s->getY() - gridSize;           
    verticalBorder.w = gridSize;                     
    verticalBorder.h = 3 * gridSize;
}

void GamePiece::selectGamePiece(bool sel) {
    selected = sel;
}

std::vector<std::unique_ptr<Shape>>& GamePiece::getShapeVector() {
    return shapes;
}

void GamePiece::checkCollision(GamePiece& gp) {

    // using a reference to the vector
    auto& gpShapes = gp.getShapeVector();

    for (auto i = shapes.begin(); i != shapes.end(); ) {
        bool shapeRemoved = false;

        // check if selected triangle hits the other gp square

        for (auto j = gpShapes.begin(); j != gpShapes.end(); ) {
            if ((*i)->collides(**j)) {
                //If the selected square hits other square
                if (i == shapes.begin() && j == gpShapes.begin()) {
                    //retrict movement, set movement limit
                    break;
                }

                // check if selected triangle hits the other gp square
                else if (j == gpShapes.begin()) {
                    gp.setAlive(false);
                    // set the other game piece to not alive
                    break;
                }

                // Check if the selected square hits other triangle 
                else if (i == shapes.begin()) {
                    // set this game piece to not alive
                    alive = false;
                    break;
                }

                i = shapes.erase(i); 
                j = gpShapes.erase(j);
                shapeRemoved = true;
                break; 

            } else {
                ++j; 
            }
        }

        if (!shapeRemoved) {
            ++i; 
        }
    }

}

bool GamePiece::getAlive() {
    return alive;
}

void GamePiece::setAlive(bool a) {
    alive = a;
}