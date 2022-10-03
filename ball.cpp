#include "ball.hpp"
#include <iostream>
#include <thread>
#include <chrono>

Ball::Ball(SDL_Renderer *m_renderer, Player *p, Stars *s)
{
    renderer = m_renderer;
    player = p;
    stars = s;

    ballWidth = 10;
    ballHeight = 10;

    initBall();
}

void Ball::initBall()
{
    ball.w = ballWidth;
    ball.h = ballHeight;
    ball.x = player->calcHorizontalCenterPosition();
    ball.y = player->calcVerticalCenterPosition();
}

void Ball::action(SDL_Event event)
{
    switch(event.key.keysym.sym)
    {
    case SDLK_SPACE:
        shoot();
        break;
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

    while( !s->findStarInPosition(b->x, b->y) && b->y >= 0 )
    {
        std::cout << "Atirou\n";

        b->y -= BALL_VEL;

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

     b->x = p->getBarRect().x + 37;
     b->y = p->getBarRect().y;
}

void Ball::prepareToRender()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &ball);
}

SDL_Rect Ball::getBallRect()
{
    return ball;
}
