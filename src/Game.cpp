#include "Game.hpp"
#include <iostream>

Game::Game(SDL_Renderer* gRenderer, int screenWidth, int screenHeight) {
    renderer = gRenderer;
    sWidth = screenWidth;
    sHeight = screenHeight;
    gridTexture = nullptr;  // Initialize gridTexture as null initially
}

void Game::drawGrid() {
    // Create an offscreen surface to draw the grid
    SDL_Surface* gridSurface = SDL_CreateRGBSurface(0, sWidth, sHeight, 32, 0, 0, 0, 0);
    if (!gridSurface) {
        std::cerr << "Failed to create surface: " << SDL_GetError() << std::endl;
        return;
    }

    // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"); // Disable linear filtering

    SDL_Renderer* tempRenderer = SDL_CreateSoftwareRenderer(gridSurface);
    if (!tempRenderer) {
        std::cerr << "Failed to create temporary renderer: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(gridSurface);
        return;
    }

    const int gridDivisions = 20; 
    const int cellSize = sHeight / gridDivisions;
    gridSize = cellSize;

    SDL_SetRenderDrawColor(tempRenderer, 150, 150, 150, 255); // Grayish lines

    // Horizontal lines
    for (int i = 0; i <= gridDivisions; ++i) {
        int y = i * cellSize;
        SDL_RenderDrawLine(tempRenderer, 0, y, sHeight, y);
    }

    // Vertical lines
    for (int i = 0; i <= gridDivisions; ++i) {
        int x = i * cellSize;
        SDL_RenderDrawLine(tempRenderer, x, 0, x, sHeight);
    }

    // Draw separating line in the middle
    SDL_SetRenderDrawColor(tempRenderer, 255, 255, 255, 255); 
    SDL_RenderDrawLine(tempRenderer, 0, sHeight / 2, sHeight, sHeight / 2);

    gridTexture = SDL_CreateTextureFromSurface(renderer, gridSurface);
    if (!gridTexture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }

    SDL_DestroyRenderer(tempRenderer);
    SDL_FreeSurface(gridSurface);
}

void Game::showGrid() {
    if (gridTexture) {
        SDL_RenderCopy(renderer, gridTexture, NULL, NULL);
    }
}

int Game::getGridSize() {
    return gridSize;
} 

void Game::createGamePieceArray() {
    int xPos = 3;
    int yPos = 2;
    int offset = 6;

    for (int i = 0; i < numGamePieces; ++i) {
        // new game piece for player 1
        auto g1 = std::make_unique<GamePiece>(renderer, gridSize);
        g1->createGamePiece(xPos + (i*offset), yPos); 
        player1Vector.push_back(std::move(g1));

        // new game piece for player 2
        auto g2 = std::make_unique<GamePiece>(renderer, gridSize);
        g2->createGamePiece(xPos + (i*offset), sHeight/gridSize - yPos - 1); 
        player2Vector.push_back(std::move(g2));
    }

    std::cout << "Player 1 vector size: " << player1Vector.size() << std::endl;
    std::cout << "Player 2 vector size: " << player2Vector.size() << std::endl;

}

void Game::moveGamePieceVector(int dir) {
    // write an if else statement here and assign a reference to to vector based on it 
    //select the OTHER player's game piece vector
    auto& gamePieces = player1 ? player2Vector : player1Vector;

    if (selectedGamePiece) {
            selectedGamePiece->moveGamePiece(dir);

            // Check collisions with other game pieces
            for (auto i = gamePieces.begin(); i != gamePieces.end(); ++i) {
                if ((*i).get() != selectedGamePiece) {
                    selectedGamePiece->checkCollision(**i);
                    if (!(*i)->getAlive()) {
                        i = gamePieces.erase(i); 
                        break;
                    }
                }
            }
    }

}

void Game::drawGamePieceVector() {
    for (const auto& gp1: player1Vector) {
        gp1->displayGamePiece();
    }

    for (const auto& gp2: player2Vector) {
        gp2->displayGamePiece();
    }
}

void Game::highlightGamePieceVector() {
    auto& gamePieces = player1 ? player1Vector : player2Vector;

    for (const auto& gp: gamePieces) {
        gp->mouseOverGamePiece(); // highlights when mouse is over the game piece
        gp->highlightGamePiece(); // keeps the selected piece highlighted even when it moves
    }
}

void Game::handleMouseClick() {

    auto& gamePieces = player1 ? player1Vector : player2Vector;

    for (const auto& gp: gamePieces) {
        if (gp->mouseOverGamePiece()) {
            gp->selectGamePiece(true);
            selectedGamePiece = gp.get();  
            //std::cout << "click" << std::endl;
        }
        else {
            gp->selectGamePiece(false);
        }
    }
    
}