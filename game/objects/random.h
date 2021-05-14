#pragma once
#include <random>
#include <memory>

class Random {
 private:
  static std::shared_ptr<std::mt19937> gen_ptr;
 public:

  static int GetNextNumber();
};


