#pragma once

#include "GameWindow.h"
#include "Brush.h"
#include "Matrix.h"
#include "Cell.h"
#include "Timer.h"

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
    Brush* _brush;

    bool IsQuitEvent(SDL_Event& e);
    bool IsFpsToggleEvent(SDL_Event& e);
    void FirstStep();
    void Step();
};

