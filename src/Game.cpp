#include "Game.hpp"

Game::Game(string windowString, int windowWidth, int windowHeight)
{
    SDL_SetMainReady();
    
    int gameInit = SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(windowString.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,

    windowWidth,windowHeight, 0);

    renderer = SDL_CreateRenderer(window,-1,0);

    isRunning = true;
    // Event serves for Inputs

}

Game& Game::Instance(){
    if(instance == nullptr)
        instance = new Game("SDL_Template",800,660);

    return *instance;
}

void Game::Run(){

    SDL_Event event;


    while (isRunning)
    {
        while(SDL_PollEvent(&event)){

            switch (event.type)
            {
            case SDL_QUIT:
                // Stops the game
                isRunning = false;
                break;
            
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isRunning = false;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,200,0,242,255);
        SDL_RenderPresent(renderer);
    }

}

Game::~Game(){

    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}