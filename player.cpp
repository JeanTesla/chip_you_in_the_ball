#include <iostream>
#include "player.hpp"
#include "frame.hpp"
#include "ball.hpp"
#include <SDL.h>

#define P_VEL 20

Player::Player(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;

    bar.h = 60;
    bar.w = 100;
    bar.x = calcVerticalCenterPosition();
    bar.y = calcHorizontalCenterPosition();

    SDL_Surface *imgSpaceShip = SDL_LoadBMP("spaceShip.bmp");
    spaceShipTexture = SDL_CreateTextureFromSurface(renderer, imgSpaceShip);
}

void Player::prepareToRender()
{
     SDL_RenderCopy(renderer, spaceShipTexture, NULL, &bar);
}

void Player::action(const Uint8 *keyStates)
{
    if(keyStates[SDL_SCANCODE_DOWN]) Frame::downMove(bar, P_VEL);
    if(keyStates[SDL_SCANCODE_UP]) Frame::upMove(bar, P_VEL);
    if(keyStates[SDL_SCANCODE_LEFT]) Frame::leftMove(bar, P_VEL);
    if(keyStates[SDL_SCANCODE_RIGHT]) Frame::rightMove(bar, P_VEL);
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

