#pragma once

#include "GameWindow.h"

class Canvas
{
public:
    Canvas(int w, int h, int bpp);
    ~Canvas();
    void DrawOn(GameWindow &window);
private:
    SDL_Surface* _canvas;
};

