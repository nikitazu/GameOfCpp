#pragma once

#include "GameWindow.h"
#include "Matrix.h"
#include "Cell.h"

class Game
{
public:
    Game(const int size);
    ~Game();
    int Loop();
    void Step();
private:
    const int _size;
    Matrix* _matrix;
    Matrix* _oldMatrix;
    GameWindow* _window;
};

