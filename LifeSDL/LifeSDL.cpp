// LifeSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

void draw(SDL_Surface &screen, SDL_Surface &canvas);

int _tmain(int argc, _TCHAR* argv[]) {
    SDL_Surface* screen = NULL;
    SDL_Surface* canvas = NULL;
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

    if (NULL == (canvas = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, 0, 0, 0, 0))) {
        printf("SDL create canvas failed\n");
        return EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Game of Life", NULL);

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            quit = (event.type == SDL_QUIT || event.type == SDL_KEYDOWN);
        }

        draw(*screen, *canvas);
        if (-1 == SDL_Flip(screen)) {
            printf("SDL flip screen failed\n");
            return EXIT_FAILURE;
        }
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}

void draw(SDL_Surface &screen, SDL_Surface &canvas) {
    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;
    SDL_FillRect(&screen, &screen.clip_rect, SDL_MapRGB(screen.format, 0xFF, 0xFF, 0xFF));
    SDL_BlitSurface(&canvas, &rect, &screen, &rect);
}
