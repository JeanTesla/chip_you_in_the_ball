#include "iostream"
#include "frame.hpp"

int Frame::width = 800;
int Frame::height = 600;

void Frame::rightMove(SDL_Rect &rect, int moveTo)
{
    const int rectWidth = rect.x + rect.w;

    if((rectWidth + moveTo) <= width)
    {
        rect.x += moveTo;
    }
    else
    {
        rect.x = width - rect.w;
    }
}

void Frame::leftMove(SDL_Rect &rect, int moveTo)
{
    const int rectWidth = rect.x - rect.w;

    if(rectWidth >= 0)
    {
        rect.x -= moveTo;
    }
    else
    {
        rect.x = 0;
    }
}

void Frame::upMove(SDL_Rect &rect, int moveTo)
{
    const int rectHeigth = rect.y - rect.h;

    if(rectHeigth >= 0)
    {
        rect.y -= moveTo;
    }
    else
    {
        rect.y = 0;
    }
}

void Frame::downMove(SDL_Rect &rect, int moveTo)
{
    const int rectHeigth = rect.y + rect.h;

    if((rectHeigth + moveTo) <= height)
    {
        rect.y += moveTo;
    }
    else
    {
        rect.y = height - rect.h;
    }
}
