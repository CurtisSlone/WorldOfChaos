#include "inc/Animation.h"
//Reset
void Animation::reset ()
{
    currentFrame = 0;
}
//Update
int Animation::updateFrame(int spriteWidth, float dt)
{
    ellapsedTime+=dt;
    bool timetruth = ellapsedTime > frameTime;
    if(ellapsedTime>=frameTime)
    {
        if(currentFrame>=(numFrames-1))
        {
            reset();
        }
        currentFrame++;
        ellapsedTime=0;
    }
    return currentFrame*spriteWidth;
}

