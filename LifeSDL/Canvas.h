#pragma once

#include "GameWindow.h"

class Canvas
{
public:
    Canvas(int w, int h, int bpp, int pixelSize);
    ~Canvas();
    void DrawOn(GameWindow &window, int x, int y, bool state);
private:
    SDL_Surface* _canvas;
    Uint32 _deadColor;
    Uint32 _aliveColor;
    int _pixelSize;
};

