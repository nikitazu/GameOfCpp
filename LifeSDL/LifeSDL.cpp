// LifeSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameWindow.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

int _tmain(int argc, _TCHAR* argv[]) {
    try {
        GameWindow game(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
        return game.Loop();
    }
    catch (int error) {
        return error;
    }
}
