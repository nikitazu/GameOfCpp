#pragma once

struct CellVertex
{
    GLfloat x;
    GLfloat y;
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

class GameWindow
{
public:
    GameWindow(int size, int w, int h, int bpp, float pixelSize);
    ~GameWindow();
    SDL_Surface* GetScreen() {
        return _screen;
    }
    void PreRender();
    void Flip();
    void Draw(int x, int y, bool state, long idx);
private:
    const int _size;
    int _width;
    int _height;
    int _bpp;
    SDL_Surface* _screen;
    Uint32 _deadColor;
    Uint32 _aliveColor;
    float _pixelSize;
    CellVertex* _brush;
    long _brushIndex;
    const long _brushSize;

    inline void CellColor(bool state, long idx);
    inline void CellColor2(bool state, long idx);
};

