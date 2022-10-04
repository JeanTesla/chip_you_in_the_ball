#pragma once

#include <SDL.h>
#include <vector>

class Stars{
    private:
        SDL_Renderer *renderer;
        SDL_Texture *starTexture;
        std::vector<SDL_Rect> starVector;
        int calcNextStarPosition(int currentStarColumn);
        void distributeStars();
    public:
        Stars(SDL_Renderer *m_renderer);
        void prepareToRender();
        int quantity;
        int starWidth;
        int starHeight;
        int distanceBetweenStars;
        std::vector<SDL_Rect> getStarVector();
        bool findStarInPosition(int x, int y);
};
