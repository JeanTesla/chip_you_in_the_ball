#pragma once

#include <SDL.h>

class Player
{

private:
    SDL_Renderer *renderer;
    SDL_Rect bar;
    SDL_Texture *spaceShipTexture;
public:
    Player(SDL_Renderer *m_renderer);
    void prepareToRender();
    void action(const Uint8 *keyStates);
    int calcVerticalCenterPosition();
    int calcHorizontalCenterPosition();
    SDL_Rect getBarRect();
};
