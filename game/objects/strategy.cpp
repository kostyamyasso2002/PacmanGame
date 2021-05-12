#include "strategy.h"
#include <random>

std::mt19937 Generate;

Direction EasyStrategy::ResolveNextStep(int x_from, int y_from, int x_to, int y_to) {
  int rnd = (Generate() % 5 + 5) % 5;
  if (rnd == 0) {
    return Direction::NONE;
  }
  if (rnd == 1) {
    return Direction::RIGHT;
  }
  if (rnd == 2) {
    return Direction::UP;
  }
  if (rnd == 3) {
    return Direction::DOWN;
  }
  if (rnd == 4) {
    return Direction::LEFT;
  }
  return Direction::NONE;
}


HardStrategy::HardStrategy(const std::shared_ptr<GameField>& field) : field_(field) {

}

Direction HardStrategy::ResolveNextStep(int x_from, int y_from, int x_to, int y_to) {
  return Direction::LEFT;
}
