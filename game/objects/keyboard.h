#include <cstdio>
#include <sys/ioctl.h>
#include <termios.h>
#include "direction.h"
#define STDIN_FILENO 0
//без этих импортов никуда

#pragma once

class Keyboard {
 public:
  static char GetKey();
  static Direction SetDirection(char key);
  static bool kbhit();
  static int mygetch();

};

