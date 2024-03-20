
#include <iostream>
#include <SDL2/SDL.h>

int main(int argv, char** args)
{
    std::cout << "Hello World!" << std::endl;


    int gameInit = SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("This window",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800,600, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);

    bool isRunning;
    // Event serves for Inputs
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

    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

  
    return 0;
}