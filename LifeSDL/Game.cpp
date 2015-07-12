#include "stdafx.h"
#include "Game.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = SCREEN_WIDTH;
const int SCREEN_BPP = 32;
const int CELLS_COUNT = 512/2;
const float CELL_SIZE = SCREEN_WIDTH / CELLS_COUNT;
const int FRAMES_PER_SECOND = 30;

// Init
// ====

Game::Game()
    : _size(CELLS_COUNT) {
    _matrix = new Matrix(CELLS_COUNT);
    _oldMatrix = new Matrix(CELLS_COUNT);
    _window = new GameWindow(CELLS_COUNT, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, CELL_SIZE);

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
    int frame = 0;
    bool cap = true;
    Timer fps;

    while (!quit) {
        fps.Start();

        while (!quit && SDL_PollEvent(&event)) {
            quit = IsQuitEvent(event);
            if (IsFpsToggleEvent(event)) {
                cap = !cap;
            }
        }

        _matrix->CopyTo(*_oldMatrix);
        Step();
        _window->PreRender();
        _window->Flip();

        frame++;
        if (cap && fps.GetTicks() < 1000 / FRAMES_PER_SECOND) {
            SDL_Delay(1000 / FRAMES_PER_SECOND - fps.GetTicks());
        }
    }

    return EXIT_SUCCESS;

}


// Private
// =======

void Game::Step() {
    long idx = 0;
    for (int x = 0; x < _size; x++) {
        for (int y = 0; y < _size; y++) {
            Cell& c = _oldMatrix->GetCell(x, y);
            if (!c.IsStable()) {
                bool newState = c.UpdateState(*_matrix, x, y);
            }
            _window->Draw(x, y, c.GetState(), idx++);
        }
    }
}

bool Game::IsQuitEvent(SDL_Event& e) {
    return e.type == SDL_QUIT 
        || e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE;
}

bool Game::IsFpsToggleEvent(SDL_Event& e) {
    return e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN;
}

