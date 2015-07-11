#pragma once

class GameWindow
{
public:
    GameWindow(int w, int h, int bpp);
    ~GameWindow();
    int Loop();
private:
    int _width;
    int _height;
    int _bpp;
    SDL_Surface* _screen;
};

