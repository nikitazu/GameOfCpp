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
}


Game::~Game() {
    delete _matrix;
    delete _oldMatrix;
    delete _window;
}


// Public
// ======

int Game::Loop() {
    return _window->Loop();
}

void Step() {
    // todo
}

