#ifndef INCLUDE_GAME_SAVER_LOADER_H_
#define INCLUDE_GAME_SAVER_LOADER_H_

#include <stdio.h>
#include <vector>
#include "game/gameMap.h"

class SaverLoader {
 private:
  GameMap *gameMap;
  FILE *file;
  const char *path = "saveFile.txt";
  std::vector<char> textSave{};
  int saveSlot_ = 0;

 public:
  void saver();
  void loader();

  void setSaveSlot(int saveSlot);
  void setMap(GameMap *gameMap);
};

#endif  // INCLUDE_GAME_SAVER_LOADER_H_
