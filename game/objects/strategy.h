#include <memory>
#include "direction.h"
#include "gameField.h"

class Strategy {
 public:
  virtual Direction ResolveNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& field,
                                    int x_from,
                                    int y_from,
                                    int x_to,
                                    int y_to) = 0;
};

class NormalStrategy : public Strategy {
 public:
  Direction ResolveNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& field,
                            int x_from,
                            int y_from,
                            int x_to,
                            int y_to) override;
};

class HardStrategy : public Strategy {
 private:

 public:
  Direction ResolveNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& field,
                            int x_from,
                            int y_from,
                            int x_to,
                            int y_to) override;
};