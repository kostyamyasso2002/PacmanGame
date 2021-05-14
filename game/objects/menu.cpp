#include "menu.h"
#include <iostream>
#include "keyboard.h"
#include "gameState.h"
#include "constants.h"
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
  PacManControllerCreator creator(parameters_);
  GhostControllerCreator creator1(parameters_);
  std::shared_ptr<GhostGroup> group = std::make_shared<GhostGroup>(parameters_.complexity_);
  group->AddGhost(std::dynamic_pointer_cast<GhostController>(creator1.CreateObjectController(3, 3)));
  std::shared_ptr<PacManController> pac = std::dynamic_pointer_cast<PacManController>(creator.CreateObjectController(2, 2));
  std::shared_ptr<GameField> game_field = std::make_shared<GameField>(CreateField(10, 20), group, pac);
  std::shared_ptr<SimpleDrawer> drawer = std::make_shared<BasicSimpleDrawer>();
  drawer = std::make_shared<SimpleDrawerDecoratorTitle>(drawer);
  drawer = std::make_shared<SimpleDrawerDecoratorHealth>(drawer, pac);
  game_field->print(drawer);
  //Keyboard keyboard;
  while (true) {
    Direction dir = Direction::NONE;
    for (int j = 0; j < Constants::amount_ticks; ++j) {
      int tick_duration = Constants::tick_duration;
      std::this_thread::sleep_for(std::chrono::milliseconds(tick_duration));
      Direction new_dir = Keyboard::SetDirection(Keyboard::GetKey());
      if (new_dir != Direction::NONE) {
        dir = new_dir;
      }
    }
    GameState type = game_field->DoNextStep(dir);
    game_field->print(drawer);
    switch (type) {
      case GameState::CONTINUE:
        break;
      case GameState::WIN:
        std::cout << "Good Job! You are winner!!!\n";
        Start();
      case GameState::LOSE:
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
  std::cout << "3 - change complexity\n";
  std::cout << "4 - return\n";
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
      ChangeComplexity();
      break;
    case 4:
      system("clear");
      return;
    default:
      std::cout << "Try again\n";
  }
  Settings();
}

void Menu::ChangeComplexity() {
  system("clear");
  std::cout << "Choose complexity you want:\n";
  std::cout << "1 - Normal\n";
  std::cout << "2 - Hard\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      parameters_.complexity_ = Complexity::NORMAL;
      break;
    case 2:
      parameters_.complexity_ = Complexity::HARD;
      break;
    default:
      ChangeComplexity();
  }
}

void Menu::SetPacmanColor() {
  system("clear");
  std::cout << "Current color of pacman: " << parameters_.pacman_color->GetName() << "\n";
  std::cout << "Choose color you want:\n";
  std::cout << "1 - White\n";
  std::cout << "2 - Red\n";
  std::cout << "3 - Green\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      parameters_.pacman_color = std::make_shared<White>();
      break;
    case 2:
      parameters_.pacman_color = std::make_shared<Red>();
      break;
    case 3:
      parameters_.pacman_color = std::make_shared<Green>();
      break;
    default:
      std::cout << "Try again\n";
      SetPacmanColor();
  }
}

void Menu::SetGhostColor() {
  system("clear");
  std::cout << "Current color of ghost: " << parameters_.ghost_color->GetName() << "\n";
  std::cout << "Choose color you want:\n";
  std::cout << "1 - White\n";
  std::cout << "2 - Red\n";
  std::cout << "3 - Green\n";
  int type;
  std::cin >> type;
  switch (type) {
    case 1:
      parameters_.ghost_color = std::make_shared<White>();
      break;
    case 2:
      parameters_.ghost_color = std::make_shared<Red>();
      break;
    case 3:
      parameters_.ghost_color = std::make_shared<Green>();
      break;
    default:
      std::cout << "Try again\n";
      SetGhostColor();
  }
}