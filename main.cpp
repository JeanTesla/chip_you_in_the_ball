#include <iostream>
#include <SDL.h>
#include "player.hpp"
#include "stars.hpp"
#include "ball.hpp"
#include "frame.hpp"

int main(int argc, char * argv[])
{

    SDL_Init(SDL_INIT_VIDEO);

    //main window
    SDL_Window *m_window = SDL_CreateWindow("Te lasca nas estrelas", 400, 60, Frame::width, Frame::height, SDL_WINDOW_SHOWN);
    //main renderer
    SDL_Renderer *m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;

    std::cout << "Iniciando execução\n";

    Player player(m_renderer);
    Stars stars(m_renderer);
    Ball ball(m_renderer, &player, &stars);

    while(!quit)
    {
        SDL_Event event;
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        while(SDL_PollEvent(&event) == 1)
        {
            if(event.type == SDL_QUIT)
                quit = true;
        }

        player.action(keystates);
        ball.action(keystates);

        stars.prepareToRender();
        player.prepareToRender();
        ball.prepareToRender();

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderPresent(m_renderer);
        SDL_RenderClear(m_renderer);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();

    return 0;
}
