#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation {
  private:
    //Private
    std::vector<IntRect> currentSequence;
    float duration;
  public:
    //Constructor
    Animation(std::vector<IntRect>& frames, float duration): currentSequence(frames), duration(duration) { reset(); };
    void reset();
    void updateFrame(float dt);
    IntRect getCurrentFrame();
};