// LifeSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

int _tmain(int argc, _TCHAR* argv[])
{
    SDL_Surface* screen = NULL;
    SDL_Event event;
    bool quit = false;

    if (-1 == SDL_Init(SDL_INIT_EVENTTHREAD)) {
        printf("SDL init failed\n");
        return EXIT_FAILURE;
    }

    if (NULL == (screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE))) {
        printf("SDL set video mode failed\n");
        return EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Game of Life", NULL);

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit = (event.type == SDL_QUIT || event.type == SDL_KEYDOWN);
        }
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}

