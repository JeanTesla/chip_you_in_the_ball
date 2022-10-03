#include <iostream>
#include "player.hpp"
#include "frame.hpp"
#include "ball.hpp"
#include <SDL.h>

#define P_VEL 10

Player::Player(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;

    bar.h = 10;
    bar.w = 75;
    bar.x = calcVerticalCenterPosition();
    bar.y = calcHorizontalCenterPosition();
}

void Player::prepareToRender()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderFillRect(renderer, &bar);
}

void Player::action(SDL_Event event)
{
    switch(event.key.keysym.sym)
    {
    case SDLK_DOWN:
        //Frame::downMove(bar, P_VEL);
        break;
    case SDLK_UP:
        //Frame::upMove(bar, P_VEL);
        break;
    case SDLK_RIGHT:
        Frame::rightMove(bar,P_VEL);
        break;
    case SDLK_LEFT:
        Frame::leftMove(bar,P_VEL);
        break;
    }
}

int Player::calcVerticalCenterPosition(){
    return (int) (Frame::width / 2) - (bar.w / 2);
}

int Player::calcHorizontalCenterPosition(){
    return (int) Frame::height - (Frame::height / 4);
}

SDL_Rect Player::getBarRect(){
    return bar;
}

