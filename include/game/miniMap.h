#ifndef INCLUDE_GAME_MINIMAP_H_
#define INCLUDE_GAME_MINIMAP_H_

#include <vector>
#include "game/gameMap.h"
#include "game/miniRooms.h"

class MiniMap {
 private:
  GameMap* gameMap;
  std::vector<MiniRooms> miniRooms{{0, 0}};
  int mini_map_size_ = 5;  // 5x5
  int symbol_map_ = 0x23;  // #
  bool tiles_ = true;

 public:
  void update();
  void generatorMiniMap();
  void mapMove(int i);
  void miniMapBack();
  void render();

  int getSymbolMap() const;
  int getMiniMapSize() const;
  void setRoomsCoords(int x_, int y_);
  bool isTiles() const;
  void setTiles(bool tiles);
  explicit MiniMap(GameMap* gameMap);
  MiniMap();
};

#endif  // INCLUDE_GAME_MINIMAP_H_
