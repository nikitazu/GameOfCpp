#include "stdafx.h"
#include "GameWindow.h"
#include "Canvas.h"

GameWindow::GameWindow(int w, int h, int bpp) {
    _width = w;
    _height = h;
    _bpp = bpp;

    if (-1 == SDL_Init(SDL_INIT_EVENTTHREAD)) {
        printf("SDL init failed\n");
        throw EXIT_FAILURE;
    }

    if (NULL == (_screen = SDL_SetVideoMode(_width, _height, _bpp, SDL_SWSURFACE))) {
        printf("SDL set video mode failed\n");
        throw EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Game of Life", NULL);
}

GameWindow::~GameWindow() {
    SDL_Quit();
}

void GameWindow::Flip() {
    if (-1 == SDL_Flip(_screen)) {
        printf("SDL flip screen failed\n");
        throw EXIT_FAILURE;
    }
}