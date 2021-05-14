#include "random.h"
int Random::GetNextNumber() {
  if (gen_ptr == nullptr) {
    gen_ptr = std::make_shared<std::mt19937>();
  }
  return std::abs(static_cast<int>(gen_ptr->operator()()));
}

std::shared_ptr<std::mt19937> Random::gen_ptr = nullptr;