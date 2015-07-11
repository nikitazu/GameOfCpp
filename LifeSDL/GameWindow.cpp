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

int GameWindow::Loop() {
    Canvas canvas(_width, _height, _bpp);
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit = (event.type == SDL_QUIT || event.type == SDL_KEYDOWN);
        }

        canvas.DrawOn(*_screen);

        if (-1 == SDL_Flip(_screen)) {
            printf("SDL flip screen failed\n");
            throw EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
