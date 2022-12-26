#pragma once
#include <SFML/Graphics.hpp>

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
        void moveView();
};


        //Conditional View Move
        // Move view down
        // if(player.getPosition().y >= bottomBorder)
        // {
        //     bottomBorder+=4;
        //     topBorder+=4;
        //     mainView.move(0,4.0f);
        //     mainView.move(0,0);        
            
        // }
        // // Move view up
        // if(player.getPosition().y <= topBorder)
        // {
        //     topBorder-=4;
        //     bottomBorder-=4;
        //     mainView.move(0,-4.0f);
        //     mainView.move(0,0); 

        // }
        // // Move view right
        // if(player.getPosition().x == rightBorder)
        // {
        //     rightBorder+=4;
        //     leftBorder+=4;
        //     mainView.move(4.0f,0);
        //     mainView.move(0,0); 
        // }
        // // Move view up
        // if(player.getPosition().x == leftBorder)
        // {
        //     leftBorder-=4;
        //     rightBorder-=4;
        //     mainView.move(-4.0f,0);
        //     mainView.move(0,0); 
        // }
