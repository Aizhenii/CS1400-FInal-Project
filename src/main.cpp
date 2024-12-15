#include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Game.hpp" 
#include "Square.hpp"
#include "Triangle.hpp"
#include "GamePiece.hpp"

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

    // if (TTF_Init() == -1) {
    //     std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
    //     return 1;
    // }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "C++ Game",         // Title of the window
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

    bool running = true;
    SDL_Event event;

    Game newGame = Game(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    newGame.drawGrid();
    int gridSize = newGame.getGridSize();
    // std::cout<< gridSize << std::endl;
    newGame.createGamePieceArray();

    // std::vector<std::unique_ptr<Shape>> shapes;
    // shapes.push_back(std::make_unique<Square>(renderer, gridSize)); 

    //Square s = Square(renderer, gridSize);
    //Triangle t = Triangle(renderer, gridSize);

    // GamePiece g1 = GamePiece(renderer, gridSize);
    // g1.createGamePiece(2, 2); 

    // GamePiece g2 = GamePiece(renderer, gridSize);
    // g2.createGamePiece(8, 5); 


    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    bool selected = false;
    bool player1 = true;

    // Game loop
    while (running) {
        int dir = 0;

        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if ( event.type == SDL_KEYDOWN) {
                //std::cout << "Key!" << std::endl;
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        dir = UP;
                        //std::cout << "Key up!" << std::endl;
                        break;
                    case SDLK_DOWN:
                        dir = DOWN;
                        //std::cout << "Key down!" << std::endl;
                        break;
                    case SDLK_LEFT:
                        dir = LEFT;
                        break;
                    case SDLK_RIGHT:
                        dir = RIGHT;
                        break;
                }

                newGame.moveGamePieceVector(dir);
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                newGame.handleMouseClick();
            }
        }   



        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Set background color
        SDL_RenderClear(renderer);

        newGame.showGrid();

        newGame.drawGamePieceVector();
        newGame.highlightGamePieceVector(); 
        
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS

    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
