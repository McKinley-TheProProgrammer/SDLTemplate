
#include <iostream>
#include "Game.hpp"

int main(int argv, char** args)
{
    std::cout << "Hello World!" << std::endl;
    Game::Instance().Run();

    return 0;
}