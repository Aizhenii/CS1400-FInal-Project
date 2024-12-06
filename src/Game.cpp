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