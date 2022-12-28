#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;
 
class GameView 
{
    private:
        float bottomBorder;
        float topBorder;
        float rightBorder;
        float leftBorder;
        View g_View;
    public:
        GameView(Vector2f& resolution) :
            g_View(FloatRect(0,0,resolution.x,resolution.y)),
            bottomBorder(resolution.y - (resolution.y*.2)),
            topBorder((resolution.y*.2)),
            rightBorder((resolution.x - (resolution.x*.2))),
            leftBorder((resolution.x*.2))
            {
                
            };
        View getView() { return g_View;};
        void moveView(Player& player);
};
