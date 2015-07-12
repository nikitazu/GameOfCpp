#pragma once
#include "Brush.h"

class GameWindow
{
public:
    GameWindow(int size, int w, int h, int bpp, float pixelSize);
    ~GameWindow();
    void Render(Brush& brush);
private:
    const int _size;
    int _width;
    int _height;
    int _bpp;
    SDL_Surface* _screen;
    Uint32 _deadColor;
    Uint32 _aliveColor;
    float _pixelSize;
};

