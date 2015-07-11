// LifeSDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[]) {
    try {
        Game game;
        return game.Loop();
    }
    catch (int error) {
        return error;
    }
}
