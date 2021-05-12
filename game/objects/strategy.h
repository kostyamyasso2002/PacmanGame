#include <memory>
#include "direction.h"
#include "gameField.h"

class Strategy {
 public:
  virtual Direction ResolveNextStep(int x_from, int y_from, int x_to, int y_to) = 0;
};

class EasyStrategy: public Strategy {
 public:
  Direction ResolveNextStep(int x_from, int y_from, int x_to, int y_to) override;
};

class HardStrategy: public Strategy {
 private:
  std::shared_ptr<GameField> field_;
 public:
  HardStrategy(const std::shared_ptr<GameField>& field);
  Direction ResolveNextStep(int x_from, int y_from, int x_to, int y_to) override;
};