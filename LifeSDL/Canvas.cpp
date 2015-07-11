#include "stdafx.h"
#include "Canvas.h"


Canvas::Canvas(int w, int h, int bpp, int pixelSize) : _pixelSize(pixelSize) {
    if (NULL == (_canvas = SDL_CreateRGBSurface(0, w, h, bpp, 0, 0, 0, 0))) {
        printf("SDL create canvas failed\n");
        throw EXIT_FAILURE;
    }

    _deadColor = SDL_MapRGB(_canvas->format, 0x00, 0x00, 0x00);
    _aliveColor = SDL_MapRGB(_canvas->format, 0xFF, 0x00, 0xFF);
    SDL_FillRect(_canvas, NULL, _deadColor);
}


Canvas::~Canvas() {
    SDL_FreeSurface(_canvas);
}


void Canvas::DrawOn(GameWindow &window, int x, int y, bool state) {
    SDL_Surface* screen = window.GetScreen();
    SDL_Rect rect;
    rect.x = x * _pixelSize;
    rect.y = y * _pixelSize;
    rect.w = _pixelSize;
    rect.h = _pixelSize;
    
    SDL_FillRect(screen, &rect, state ? _aliveColor : _deadColor);
    
    //SDL_FillRect(_canvas, &rect, state ? _aliveColor : _deadColor);
    //SDL_BlitSurface(_canvas, &rect, screen, &rect);

    //SDL_FillRect(_canvas, &rect, state ? _aliveColor : _deadColor);
    //SDL_BlitSurface(_canvas, NULL, screen, NULL);
}
