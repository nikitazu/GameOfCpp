#include "stdafx.h"
#include "GameWindow.h"

// Init
// ====

GameWindow::GameWindow(int size, int w, int h, int bpp, float pixelSize)
    : _size(size),
    _brushSize(size*size*4) {
    _width = w;
    _height = h;
    _bpp = bpp;
    _pixelSize = pixelSize;

    if (SDL_Init(SDL_INIT_EVENTTHREAD) < 0) {
        printf("SDL init failed\n");
        throw EXIT_FAILURE;
    }

    if (NULL == (_screen = SDL_SetVideoMode(_width, _height, _bpp, SDL_OPENGL))) {
        printf("SDL set video mode failed\n");
        throw EXIT_FAILURE;
    }

    _brush = new CellVertex[_brushSize]();
    _brushIndex = 0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _width, _height, 0, 0, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("OPENGL init failed: %s\n", gluErrorString(error));
        SDL_Quit();
        throw EXIT_FAILURE;
    }

    SDL_WM_SetCaption("Game of Life", NULL);
}

GameWindow::~GameWindow() {
    delete[] _brush;
    SDL_Quit();
}


// Public
// ======

void GameWindow::PreRender() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GameWindow::Flip() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, sizeof(CellVertex), _brush);
    glColorPointer(3, GL_FLOAT, sizeof(CellVertex), &_brush[0].r);

    glDrawArrays(GL_QUADS, 0, _brushSize);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    SDL_GL_SwapBuffers();
}

void GameWindow::Draw(int x, int y, bool state) {
    GLfloat x0 = x * _pixelSize;
    GLfloat y0 = y * _pixelSize;
    GLfloat x1 = x0 + _pixelSize;
    GLfloat y1 = y0 + _pixelSize;

    _brush[_brushIndex].x = x0;
    _brush[_brushIndex].y = y0;
    CellColor(state);
    _brushIndex++;

    _brush[_brushIndex].x = x1;
    _brush[_brushIndex].y = y0;
    CellColor(state);
    _brushIndex++;

    _brush[_brushIndex].x = x1;
    _brush[_brushIndex].y = y1;
    CellColor(state);
    _brushIndex++;

    _brush[_brushIndex].x = x0;
    _brush[_brushIndex].y = y1;
    CellColor2(state);
    _brushIndex++;

    if (_brushIndex >= _brushSize) {
        _brushIndex = 0;
    }
}

inline void GameWindow::CellColor(bool state) {
    if (state) {
        GLfloat c = (_brushSize - _brushIndex) / (GLfloat)_brushSize;
        _brush[_brushIndex].r = c * 1.5f;
        _brush[_brushIndex].g = c;
        _brush[_brushIndex].b = c * 0.5f;
    }
    else {
        GLfloat c = _brushIndex / (GLfloat)_brushSize * 0.5f;
        _brush[_brushIndex].r = c;
        _brush[_brushIndex].g = c;
        _brush[_brushIndex].b = c;
    }
}

inline void GameWindow::CellColor2(bool state) {
    if (state) {
        GLfloat c = (_brushSize - _brushIndex) / (GLfloat)_brushSize;
        _brush[_brushIndex].r = c;
        _brush[_brushIndex].g = c;
        _brush[_brushIndex].b = c * 1.3f;
    } else {
        GLfloat c = _brushIndex / (GLfloat)_brushSize * 0.3f;
        _brush[_brushIndex].r = c;
        _brush[_brushIndex].g = c;
        _brush[_brushIndex].b = c;
    }
}

