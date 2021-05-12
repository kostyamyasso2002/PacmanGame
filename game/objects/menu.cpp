#include "menu.h"
#include <iostream>
#include "keyboard.h"
#include <chrono>
#include <thread>

void Menu::Start() {
  std::cout << "Choose the item you want:\n";
  std::cout << "1 - start the game this current settings\n";
  std::cout << "2 - settings\n";
  std::cout << "3 - exit\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      Game();
      break;
    case 2:
      Settings();
      break;
    case 3:
      exit(0);
      break;
    default:
      std::cout << "Try again\n";
  }
  Start();
}

std::vector<std::vector<std::shared_ptr<Cell>>> Menu::CreateField(int height, int width) {
  std::vector<std::vector<std::shared_ptr<Cell>>> ans;
  ans.assign(height, std::vector<std::shared_ptr<Cell>>(width));
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
        ans[i][j] = std::make_shared<Wall>();
      } else {
        ans[i][j] = std::make_shared<Food>();
      }
    }
  }
  return ans;
}

void Menu::Game() {
  system("clear");
  GameParameters parameters(pacman_color_, ghost_color_, complexity_);
  PacManControllerCreator creator(parameters);
  GhostControllerCreator creator1(parameters);
  std::shared_ptr<GhostGroup> group = std::make_shared<GhostGroup>();
  group->AddGhost(std::dynamic_pointer_cast<GhostController>(creator1.CreateObjectController()));
  std::shared_ptr<PacManController> pac = std::dynamic_pointer_cast<PacManController>(creator.CreateObjectController());
  GameField game_field(CreateField(10, 20), group, pac);
  std::shared_ptr<SimpleDrawer> drawer = std::make_shared<BasicSimpleDrawer>();
  drawer = std::make_shared<SimpleDrawerDecoratorTitle>(drawer);
  drawer = std::make_shared<SimpleDrawerDecoratorHealth>(drawer, pac);
  game_field.print(drawer);
  Keyboard keyboard;
  while (true) {
    Direction dir = Direction::NONE;
    for (int j = 0; j < 200; ++j) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      Direction new_dir = keyboard.SetDirection(keyboard.GetKey());
      if (new_dir != Direction::NONE) {
        dir = new_dir;
      }
    }
    int type = game_field.DoNextStep(dir);
    game_field.print(drawer);
    switch (type) {
      case 0:
        break;
      case 1:
        std::cout << "Good Job! You are winner!!!\n";
        Start();
      case 2:
        std::cout << "You are looser:(\n";
        Start();
    }
  }
}

void Menu::Settings() {
  system("clear");
  std::cout << "Choose the item you want:\n";
  std::cout << "1 - choose PacMan color\n";
  std::cout << "2 - choose Ghosts color\n";
  std::cout << "3 - return\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      SetPacmanColor();
      break;
    case 2:
      SetGhostColor();
      break;
    case 3:
      return;
    default:
      std::cout << "Try again\n";
  }
  Settings();
}

void Menu::SetPacmanColor() {
  system("clear");
  std::cout << "Current color of pacman: " << pacman_color_->GetName() << "\n";
  std::cout << "Choose color you want:\n";
  std::cout << "1 - White\n";
  std::cout << "2 - Red\n";
  std::cout << "3 - Green\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      pacman_color_ = std::make_shared<White>();
      break;
    case 2:
      pacman_color_ = std::make_shared<Red>();
      break;
    case 3:
      pacman_color_ = std::make_shared<Green>();
      break;
    default:
      std::cout << "Try again\n";
      SetPacmanColor();
  }
}

void Menu::SetGhostColor() {
  system("clear");
  std::cout << "Current color of ghost: " << pacman_color_->GetName() << "\n";
  std::cout << "Choose color you want:\n";
  std::cout << "1 - White\n";
  std::cout << "2 - Red\n";
  std::cout << "3 - Green\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      ghost_color_ = std::make_shared<White>();
      break;
    case 2:
      ghost_color_ = std::make_shared<Red>();
      break;
    case 3:
      ghost_color_ = std::make_shared<Green>();
      break;
    default:
      std::cout << "Try again\n";
      SetGhostColor();
  }
}