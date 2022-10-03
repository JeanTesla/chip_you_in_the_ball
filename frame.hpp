#pragma once

#include <SDL.h>

class Frame
{
    public:
        static int width;
        static int height;
        static void rightMove(SDL_Rect &rect, int valueToIncrement);
        static void leftMove(SDL_Rect &rect, int valueToIncrement);
        static void upMove(SDL_Rect &rect, int valueToIncrement);
        static void downMove(SDL_Rect &rect, int valueToIncrement);
};
