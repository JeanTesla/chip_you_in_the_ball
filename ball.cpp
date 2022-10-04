#include "ball.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <SDL.h>

Ball::Ball(SDL_Renderer *m_renderer, Player *p, Stars *s)
{
    renderer = m_renderer;
    player = p;
    stars = s;

    SDL_Surface *imgShoot = SDL_LoadBMP("shootfire.bmp");
    shootTexture = SDL_CreateTextureFromSurface(renderer, imgShoot);

    ballWidth = 25;
    ballHeight = 25;

    initBall();
}

void Ball::initBall()
{
    ball.w = ballWidth;
    ball.h = ballHeight;
    ball.x = player->calcHorizontalCenterPosition();
    ball.y = player->calcVerticalCenterPosition();
}

void Ball::action(const Uint8 *keystates)
{
    if(keystates[SDL_SCANCODE_SPACE]){
        if((ball.x == 5000 && ball.y == 5000)
           || (ball.x == player->calcHorizontalCenterPosition() && ball.y == player->calcVerticalCenterPosition() )){
            shoot();
        }
    }
}

void Ball::shoot()
{
    std::thread t(&Ball::shootTask, player, stars, &ball);
    t.detach();
}

void Ball::shootTask(Player *p, Stars *s, SDL_Rect *b)
{
    b->x = p->getBarRect().x + 37;
    b->y = p->getBarRect().y;

    while(!s->findStarInPosition(b->x, b->y) && b->y >= 0)
    {
        b->y -= BALL_VEL;
        std::this_thread::sleep_for(std::chrono::nanoseconds(400000));
    }

    b->x = 5000; //Força posicionamento fora do frame
    b->y = 5000; //Força posicionamento fora do frame
}

void Ball::prepareToRender()
{
        SDL_RenderCopy(renderer, shootTexture, NULL, &ball);
}

SDL_Rect Ball::getBallRect()
{
    return ball;
}
