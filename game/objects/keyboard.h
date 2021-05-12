#include <cstdio>
#include <sys/ioctl.h>
#include <termios.h>
#include "direction.h"
#define STDIN_FILENO 0
//без этих импортов никуда

#pragma once

class Keyboard {
 public:
  char GetKey();
  Direction SetDirection(char key);
  bool kbhit();
  int mygetch();

};

