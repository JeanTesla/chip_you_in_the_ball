#include <iostream>
#include "stars.hpp"
#include "frame.hpp"

Stars::Stars(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;

    quantity = 390;
    starWidth = 10;
    starHeight = 10;
    distanceBetweenStars = 5;

    distributeStars();
}

void Stars::distributeStars()
{
    int currentStarRow = 1;
    int currentStarColumn = 1;

    for(int i = 0; i < quantity; i++)
    {
        SDL_Rect star;

        star.h = starHeight;
        star.w = starWidth;

        int nextStarPosition = calcNextStarPosition(currentStarColumn);

        if(nextStarPosition >= Frame::width)
        {
            currentStarRow += (starHeight + (2 * distanceBetweenStars));
            currentStarColumn = 1;
            nextStarPosition = calcNextStarPosition(currentStarColumn);
        }

        star.x = nextStarPosition;
        star.y = currentStarRow;

        starVector.push_back(star);

        currentStarColumn++;
    }
}

void Stars::prepareToRender()
{
    for(SDL_Rect star: starVector)
    {
        SDL_SetRenderDrawColor(renderer,255,255,0,255);
        SDL_RenderFillRect(renderer, &star);
    }
}

int Stars::calcNextStarPosition(int currentStarColumn)
{
    return currentStarColumn * (starWidth + (2 * distanceBetweenStars));
}

std::vector<SDL_Rect> Stars::getStarVector()
{
    return starVector;
}

bool Stars::findStarInPosition(int x, int y)
{
    std::cout << "x: " << x << " y: " << y << '\n';
    bool finded = false;
    int counter = 0;

    for(int i = 0; i< starVector.size(); i++)
    {
        SDL_Rect currentStar = starVector[i];
        //std::cout << "x: " << star.x << " y: " << star.y << '\n';
        if(currentStar.x == x && currentStar.y == y)
        {
            //std::cout << "Encontrou\n";
            finded = true;
            starVector.erase(starVector.begin() + i);
            break;
        }
        counter++;
    }
    return finded;
}

