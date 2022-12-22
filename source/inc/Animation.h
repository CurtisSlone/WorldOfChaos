#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;
class Animation {
  public:
  Animation(const std::vector<IntRect>& frames, float duration, bool cycles = true) : frames(frames), frameTime(duration / frames.size()), cycles(cycles) { reset(); }

  void reset() {
    currentFrame = 0;
    currentFrameTime = 0;
  }
  void update(float dt);
  const sf::IntRect& getCurrentRect() const { return frames[currentFrame]; }

  private:
  const std::vector<sf::IntRect>& frames;
  const float frameTime;
  bool cycles;
  int currentFrame;
  float currentFrameTime;
};