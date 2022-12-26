#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation {
  private:
    //Private
    float duration;    
    float frameTime;
    int currentFrame;
    int numFrames;
  public:
    //Constructor
    Animation(float duration, int numFrames):  
    duration(duration),
    numFrames(numFrames),
    frameTime(duration/numFrames)
    { reset(); };
    void reset();
    void updateFrame(float dt);
};