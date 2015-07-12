#include "stdafx.h"
#include "GameWindow.h"

// Init
// ====

GameWindow::GameWindow(int size, int w, int h, int bpp, float pixelSize)
    : _size(size) {
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
    SDL_Quit();
}


// Public
// ======

void GameWindow::PreRender() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void GameWindow::Flip(Brush& brush) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, sizeof(BrushVertex), brush.GetVertsHandle());
    glColorPointer(3, GL_FLOAT, sizeof(BrushVertex), brush.GetColorsHandle());

    glDrawArrays(GL_QUADS, 0, brush.GetSize());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    SDL_GL_SwapBuffers();
}

