#pragma once

#include <iostream>
#include <string.h>

#include "SDL_include.h"

//#include "SDL_include.h"

using namespace std;

class Game
{

private:
    Game(string title, int window_W, int window_H);

    inline static Game* instance = nullptr;

    SDL_Window* window;
    SDL_Renderer* renderer;


    bool isRunning; //Temp variable

public:
    ~Game();
    static Game& Instance();

    void Run();
};