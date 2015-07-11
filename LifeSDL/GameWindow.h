#pragma once

class GameWindow
{
public:
    GameWindow(int w, int h, int bpp, float pixelSize);
    ~GameWindow();
    SDL_Surface* GetScreen() {
        return _screen;
    }
    void PreRender();
    void Flip();
    void Draw(int x, int y, bool state);
private:
    int _width;
    int _height;
    int _bpp;
    SDL_Surface* _screen;
    Uint32 _deadColor;
    Uint32 _aliveColor;
    float _pixelSize;
};

