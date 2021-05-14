#include "keyboard.h"
#include <iostream>

bool Keyboard::kbhit()
{
  termios term;
  tcgetattr(0, &term);

  termios term2 = term;
  term2.c_lflag &= ~ICANON;
  tcsetattr(0, TCSANOW, &term2);

  int byteswaiting;
  ioctl(0, FIONREAD, &byteswaiting);

  tcsetattr(0, TCSANOW, &term);
  return (byteswaiting > 0);
}

int Keyboard::mygetch() {
  struct termios oldt,
      newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

char Keyboard::GetKey() {
  char key = 'n';
  if(kbhit()){
    key = mygetch();
  }
  return key;
}

Direction Keyboard::SetDirection(char key) {
  switch(std::tolower(key)){
    case 'a':
      return Direction::LEFT;
    case 'w':
      return Direction::UP;
    case 'd':
      return Direction::RIGHT;
    case 's':
      return Direction::DOWN;
  }
  return Direction::NONE;
}