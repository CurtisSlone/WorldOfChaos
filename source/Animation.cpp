#include "inc/Animation.h"

void Animation::update(float dt) {
  currentFrameTime += dt;
  // TODO: take `cycles` into account.
  while (currentFrameTime >= frameTime) {
    currentFrameTime -= frameTime;
    currentFrame = (currentFrame + 1) % frames.size();
  }
}