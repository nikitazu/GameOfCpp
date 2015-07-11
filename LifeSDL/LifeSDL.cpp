// LifeSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int _tmain(int argc, _TCHAR* argv[])
{
    SDL_Surface* screen = NULL;

    if (-1 == SDL_Init(SDL_INIT_EVENTTHREAD)) {
        printf("SDL init failed\n");
        return EXIT_FAILURE;
    }

    if (NULL == (screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE))) {
        printf("SDL set video mode failed\n");
        return EXIT_FAILURE;
    }

    SDL_Delay(2000);

    SDL_Quit();
    return EXIT_SUCCESS;
}

