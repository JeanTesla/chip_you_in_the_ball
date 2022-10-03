#include <SDL.h>
#include "player.hpp"
#include "stars.hpp"
#include "frame.hpp"

#define BALL_VEL 1

class Ball{
    private:
        SDL_Renderer *renderer;
        Player *player;
        Stars *stars;
        SDL_Rect ball;

        int ballWidth;
        int ballHeight;

        void shoot();
        void initBall();
        static void shootTask(Player *p, Stars *s, SDL_Rect *ball);
    public:
        Ball(SDL_Renderer *m_renderer, Player *p, Stars *s);
        void action(SDL_Event event);
        void prepareToRender();
        SDL_Rect getBallRect();
};
