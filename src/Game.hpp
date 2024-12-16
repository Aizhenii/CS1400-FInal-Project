#ifndef GAME_HPP 
#define GAME_HPP

#include <SDL2/SDL.h> 
#include "GamePiece.hpp"

class Game {
    public: 
        Game(SDL_Renderer* gRenderer, int screenWidth, int screenHeight);

        // draw the grid into the texture
        void drawGrid();
        void showGrid();
        int getGridSize();

        // write most of the game logic here
        void moveGamePieceVector(int dir); 
        void selectGamePieceVector();
        void drawGamePieceVector();
        void highlightGamePieceVector();
        void handleMouseClick();
        void createGamePieceArray();

        void switchTurns();
        void drawButtons();

    private:
        SDL_Renderer* renderer;
        SDL_Texture* gridTexture; // Creating a grid texture that we can reuse
        int sWidth;
        int sHeight;
        int gridSize;

        int numGamePieces = 3;

        bool player1 = true;

        std::vector<std::unique_ptr<GamePiece>> player1Vector;
        std::vector<std::unique_ptr<GamePiece>> player2Vector;

        GamePiece* selectedGamePiece = nullptr;

        SDL_Rect endButton1;
        SDL_Rect endButton2;

        void createButtons();



};

#endif 
