#include <SDL2/SDL.h>
#include <iostream>

void drawGrid(SDL_Renderer* gRenderer, int screenWidth, int screenHeight);

int main(int argc, char* argv[]) {
    // Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Test Window",         // Title of the window
        SDL_WINDOWPOS_CENTERED,     // Initial X position
        SDL_WINDOWPOS_CENTERED,     // Initial Y position
        SCREEN_WIDTH,               // Width
        SCREEN_HEIGHT,              // Height
        SDL_WINDOW_SHOWN            // Window behavior flags
    );

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Game loop
    bool running = true;
    SDL_Event event;

    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Set background color to white
        SDL_RenderClear(renderer);

        // Draw the grid
        drawGrid(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Present the renderer
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawGrid(SDL_Renderer* gRenderer, int screenWidth, int screenHeight) {
    const int gridDivisions = 20; // Number of cells in the grid
    const int cellSize = screenHeight / gridDivisions;

    // Set draw color for the grid lines
    SDL_SetRenderDrawColor(gRenderer, 150, 150, 150, 255); 

    // Horizontal lines
    for (int i = 0; i <= gridDivisions; ++i) {
        int y = i * cellSize;
        SDL_RenderDrawLine(gRenderer, 0, y, screenHeight, y);
    }

    // Vertical lines
    for (int i = 0; i <= gridDivisions; ++i) {
        int x = i * cellSize;
        SDL_RenderDrawLine(gRenderer, x, 0, x, screenHeight);
    }

    //draws a seperating line in the middle
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); 
    SDL_RenderDrawLine(gRenderer, 0, screenHeight/2, screenHeight, screenHeight/2);
}
