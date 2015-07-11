#include "stdafx.h"
#include "Canvas.h"


Canvas::Canvas(int w, int h, int bpp) {
    if (NULL == (_canvas = SDL_CreateRGBSurface(0, w, h, bpp, 0, 0, 0, 0))) {
        printf("SDL create canvas failed\n");
        throw EXIT_FAILURE;
    }
}


Canvas::~Canvas() {
    SDL_FreeSurface(_canvas);
}


void Canvas::DrawOn(SDL_Surface &screen) {
    SDL_Rect rect;
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;
    SDL_FillRect(&screen, &screen.clip_rect, SDL_MapRGB(screen.format, 0xFF, 0xFF, 0xFF));
    SDL_BlitSurface(_canvas, &rect, &screen, &rect);
}
