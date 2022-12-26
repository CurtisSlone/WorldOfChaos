#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation {
  private:
    //Private
    float duration;    
    float frameTime;
    float ellapsedTime;
    int currentFrame;
    Vector2f a_frame;
    int numFrames;
  public:
    //Constructor
    Animation(float duration, int numFrames):  
    duration(duration),
    numFrames(numFrames),
    frameTime(duration/numFrames),
    ellapsedTime(0.0)
    { reset(); };
    void reset();
    int updateFrame(int spriteWidth, float dt);
};