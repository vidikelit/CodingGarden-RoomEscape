#ifndef INCLUDE_GAME_SAVER_LOADER_H_
#define INCLUDE_GAME_SAVER_LOADER_H_

#include <stdio.h>
#include <vector>
#include "game/map.h"

class SaverLoader {
 private:
  Map *map;
  FILE *file;
  const char *path = "saveFile.txt";
  std::vector<char> textSave{};
  int saveSlot = 0;

 public:
  void saver();
  void loader();

  void setSaveSlot(int saveSlot);
  void setMap(Map *map);
};

#endif  // INCLUDE_GAME_SAVER_LOADER_H_
