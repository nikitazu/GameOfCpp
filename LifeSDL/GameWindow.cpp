#include "stdafx.h"
#include "GameWindow.h"

// Init
// ====

GameWindow::GameWindow(int w, int h, int bpp, int pixelSize) {
    _width = w;
    _height = h;
    _bpp = bpp;
    _pixelSize = pixelSize;

    if (-1 == SDL_Init(SDL_INIT_EVENTTHREAD)) {
        printf("SDL init failed\n");
        throw EXIT_FAILURE;
    }

    if (NULL == (_screen = SDL_SetVideoMode(_width, _height, _bpp, SDL_SWSURFACE))) {
        printf("SDL set video mode failed\n");
        throw EXIT_FAILURE;
    }

    _deadColor = SDL_MapRGB(_screen->format, 0x00, 0x22, 0x00);
    _aliveColor = SDL_MapRGB(_screen->format, 0x00, 0xFF, 0x00);
    SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0x00, 0x00, 0x00));
    SDL_WM_SetCaption("Game of Life", NULL);
}

GameWindow::~GameWindow() {
    SDL_Quit();
}


// Public
// ======

void GameWindow::Flip() {
    if (-1 == SDL_Flip(_screen)) {
        printf("SDL flip screen failed\n");
        throw EXIT_FAILURE;
    }
}


void GameWindow::Draw(int x, int y, bool state) {
    SDL_Rect rect;
    rect.x = x * _pixelSize;
    rect.y = y * _pixelSize;
    rect.w = _pixelSize;
    rect.h = _pixelSize;

    SDL_FillRect(_screen, &rect, state ? _aliveColor : _deadColor);
}

