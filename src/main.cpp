
#define SDL_MAIN_HANDLED

#include <iostream>
#include "Game.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Game::Instance().Run();

    return 0;
}