#pragma once
class Canvas
{
public:
    Canvas(int w, int h, int bpp);
    ~Canvas();
    void DrawOn(SDL_Surface &canvas);
private:
    SDL_Surface* _canvas;
};

