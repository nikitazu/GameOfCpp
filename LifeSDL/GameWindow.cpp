#include "stdafx.h"
#include "GameWindow.h"

// Init
// ====

GameWindow::GameWindow(int w, int h, int bpp, float pixelSize) {
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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("OPENGL init failed: %s\n", gluErrorString(error));
        SDL_Quit();
        throw EXIT_FAILURE;
    }

    //_deadColor = SDL_MapRGB(_screen->format, 0x00, 0x22, 0x00);
    //_aliveColor = SDL_MapRGB(_screen->format, 0x00, 0xFF, 0x00);
    //SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0x00, 0x00, 0x00));
    SDL_WM_SetCaption("Game of Life", NULL);
}

GameWindow::~GameWindow() {
    SDL_Quit();
}


// Public
// ======

void GameWindow::PreRender() {
    //Clear color buffer
    //glClear(GL_COLOR_BUFFER_BIT);

    //Reset modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Move to center of the screen
    glTranslatef(-1.f, 1.0f, 0.0f);

}

void GameWindow::Flip() {
    SDL_GL_SwapBuffers();
}

inline void CellColor(bool state);
inline void CellColor2(bool state);

void GameWindow::Draw(int x, int y, bool state) {
    GLfloat relativePixel = 2.0f * _pixelSize / _width;
    GLfloat x0 = x * relativePixel;
    GLfloat y0 = y * relativePixel;
    GLfloat x1 = x0 + relativePixel;
    GLfloat y1 = y0 + relativePixel;

    glBegin(GL_QUADS);
        CellColor(state);
        glVertex2f(x0, -y0); // tl
        glVertex2f(x1, -y0); // tr
        glVertex2f(x1, -y1); // br
        CellColor2(state);
        glVertex2f(x0, -y1); // bl
    glEnd();
}

inline void CellColor(bool state) {
    if (state)
        glColor3f(0.3f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);
}

inline void CellColor2(bool state) {
    if (state)
        glColor3f(0.7f, 0.6f, 0.3f);
    else
        glColor3f(0.1f, 0.1f, 0.1f);
}

