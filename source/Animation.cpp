#include "inc/Animation.h"

//Reset
void Animation::reset ()
{
    currentFrame = 0;
    frameTime = 0;
}
//Update
void Animation::updateFrame(float dt)
{

}

//return frame
IntRect Animation::getCurrentFrame()
{
    return currentSequence[currentFrame];
}