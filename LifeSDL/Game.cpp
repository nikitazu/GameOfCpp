#include "stdafx.h"
#include "Game.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = SCREEN_WIDTH;
const int SCREEN_BPP = 32;
const int CELLS_COUNT = 500;
const int CELL_SIZE = SCREEN_WIDTH / CELLS_COUNT;

// Init
// ====

Game::Game() : _size(CELLS_COUNT) {
    _matrix = new Matrix(CELLS_COUNT);
    _oldMatrix = new Matrix(CELLS_COUNT);
    _window = new GameWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    _canvas = new Canvas(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, CELL_SIZE);

    for (int x = 0; x < _size; x++) {
        for (int y = 0; y < _size; y++) {
            _matrix->GetCell(x, y).InitCounters(*_matrix, x, y);
        }
    }
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
        while (!quit && SDL_PollEvent(&event)) {
            quit = IsQuitEvent(event);
        }

        _matrix->CopyTo(*_oldMatrix);
        Step();
        _window->Flip();
    }

    return EXIT_SUCCESS;

}


// Private
// =======

void Game::Step() {
    for (int x = 0; x < _size; x++) {
        for (int y = 0; y < _size; y++) {
            Cell& c = _oldMatrix->GetCell(x, y);
            if (!c.IsStable()) {
                bool newState = c.UpdateState(*_matrix, x, y);
                _canvas->DrawOn(*_window, x, y, newState);
            }
        }
    }
}

bool Game::IsQuitEvent(SDL_Event& event) {
    return event.type == SDL_QUIT || event.type == SDL_KEYDOWN;
}

