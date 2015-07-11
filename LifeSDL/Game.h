#pragma once

#include "GameWindow.h"
#include "Canvas.h"
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
    Canvas* _canvas;
    bool Game::IsQuitEvent(SDL_Event& event);
    void Step();
};

