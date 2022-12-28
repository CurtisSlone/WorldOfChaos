#include "inc/GameView.h"

void GameView::moveView(Player& player)
{
    //Conditional View Move
        //Move view down
        if(player.getPos().y >= bottomBorder)
        {
            bottomBorder+=4;
            topBorder+=4;
            g_View.move(0,4.0f);
            g_View.move(0,0);        
            
        }
        // Move view up
        if(player.getPos().y <= topBorder)
        {
            topBorder-=4;
            bottomBorder-=4;
            g_View.move(0,-4.0f);
            g_View.move(0,0); 

        }
        // Move view right
        if(player.getPos().x == rightBorder)
        {
            rightBorder+=4;
            leftBorder+=4;
            g_View.move(4.0f,0);
            g_View.move(0,0); 
        }
        // Move view up
        if(player.getPos().x == leftBorder)
        {
            leftBorder-=4;
            rightBorder-=4;
            g_View.move(-4.0f,0);
            g_View.move(0,0); 
}
}