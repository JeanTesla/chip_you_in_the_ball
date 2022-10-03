#pragma once

#include <SDL.h>

class Player
{

private:
    SDL_Renderer *renderer;
    SDL_Rect bar;
public:
    Player(SDL_Renderer *m_renderer);
    void prepareToRender();
    void action(SDL_Event event);
    int calcVerticalCenterPosition();
    int calcHorizontalCenterPosition();
    SDL_Rect getBarRect();
};
