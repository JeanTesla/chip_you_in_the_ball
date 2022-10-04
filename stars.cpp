#include <iostream>
#include "stars.hpp"
#include "frame.hpp"

Stars::Stars(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;

    quantity = 100;
    starWidth = 30;
    starHeight = 20;
    distanceBetweenStars = 5;

    SDL_Surface *imgStar = SDL_LoadBMP("star.bmp");
    starTexture = SDL_CreateTextureFromSurface(renderer, imgStar);

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

        if((nextStarPosition + starWidth) >= Frame::width)
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
        SDL_RenderCopy(renderer, starTexture, NULL, &star);
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

bool Stars::findStarInPosition(int xBallPosition, int yBallPosition)
{
    bool finded = false;
    int counter = 0;

    for(int i = 0; i< starVector.size(); i++)
    {
        SDL_Rect currentStar = starVector[i];
        int negativePositionContactStar = currentStar.x - (currentStar.w / 2);
        int positivePositionContactStar = currentStar.x + (currentStar.w / 2);

        if( (xBallPosition >= negativePositionContactStar && xBallPosition <= positivePositionContactStar)
           && currentStar.y == yBallPosition)
        {
            finded = true;
            starVector.erase(starVector.begin() + i);
            break;
        }
        counter++;
    }
    return finded;
}
