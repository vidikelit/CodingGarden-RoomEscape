#ifndef INCLUDE_GAME_MINIMAP_H_
#define INCLUDE_GAME_MINIMAP_H_

#include <vector>
#include "game/miniRooms.h"
#include "game/gameMap.h"

class MiniMap {
 private:
  GameMap* gameMap;
  std::vector<MiniRooms> miniRooms{{0, 0}};
  int pos_render_x_ = 2;
  int pos_render_y_ = 2;

 public:
  void generatorMiniMap();
  void mapMove(int i);
  void render();
  void setRoomsCoords(int x_, int y_);
  explicit MiniMap(GameMap* gameMap);
  MiniMap();
};

#endif  // INCLUDE_GAME_MINIMAP_H_
