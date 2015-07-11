#pragma once

class GameWindow
{
public:
    GameWindow(int w, int h, int bpp);
    ~GameWindow();
    SDL_Surface* GetScreen() {
        return _screen;
    }
    void Flip();
private:
    int _width;
    int _height;
    int _bpp;
    SDL_Surface* _screen;
};

