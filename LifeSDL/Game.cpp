#include "stdafx.h"
#include "Game.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

// Init
// ====

Game::Game(const int size) : _size(size) {
    _matrix = new Matrix(size);
    _oldMatrix = new Matrix(size);
    _window = new GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    _canvas = new Canvas(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
}


Game::~Game() {
    delete _matrix;
    delete _oldMatrix;
    delete _window;
}


// Public
// ======

int Game::Loop() {
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        _matrix->CopyTo(*_oldMatrix);

        while (!quit && SDL_PollEvent(&event)) {
            quit = IsQuitEvent(event);
        }

        _canvas->DrawOn(*_window);
        _window->Flip();
    }

    return EXIT_SUCCESS;

}


// Private
// =======

void Step() {
    // todo
}

bool Game::IsQuitEvent(SDL_Event& event) {
    return event.type == SDL_QUIT || event.type == SDL_KEYDOWN;
}

