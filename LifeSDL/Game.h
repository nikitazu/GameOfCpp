#pragma once

#include "GameWindow.h"
#include "Matrix.h"
#include "Cell.h"

class Game
{
public:
    Game();
    ~Game();
    int Loop();
private:
    const int _size;
    Matrix* _matrix;
    Matrix* _oldMatrix;
    GameWindow* _window;

    bool Game::IsQuitEvent(SDL_Event& event);
    void Step();
};

