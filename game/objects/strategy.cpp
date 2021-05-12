#include "strategy.h"
#include <cassert>
#include <queue>

Direction NormalStrategy::ResolveNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& field, int x_from, int y_from, int x_to, int y_to) {
  return GetRandomDirection();
}


Direction HardStrategy::ResolveNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& field, int x_from, int y_from, int x_to, int y_to) {
  std::vector<std::pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  std::vector<std::vector<bool>>
      used(field.size(), std::vector<bool>(field[0].size(), false));
  std::queue<std::pair<int, int>> bfs_queue;
  std::vector<std::vector<Direction>> dir_to_cell
      (field.size(), std::vector<Direction>(field[0].size(), Direction::NONE));
  bfs_queue.push({x_from, y_from});
  used[x_from][y_from] = true;

  while (!bfs_queue.empty()) {
    std::pair<int, int> cur = bfs_queue.front();
    bfs_queue.pop();
    for (auto& it: move) {
      std::pair<int, int> new_cell = {it.first + cur.first, it.second + cur.second};
      if (!field[new_cell.first][new_cell.second]->CanMove()
          || used[new_cell.first][new_cell.second]) {
        continue;
      }
      used[new_cell.first][new_cell.second] = true;
      if (dir_to_cell[cur.first][cur.second] == Direction::NONE) {
        dir_to_cell[new_cell.first][new_cell.second] = CoordsToDirection(it);
      } else {
        dir_to_cell[new_cell.first][new_cell.second] = dir_to_cell[cur.first][cur.second];
      }
      bfs_queue.push(new_cell);
    }
  }
  return dir_to_cell[x_to][y_to];
  //assert(false);
}
