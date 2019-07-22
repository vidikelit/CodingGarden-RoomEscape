#ifndef INCLUDE_GAME_SAVER_LOADER_H_
#define INCLUDE_GAME_SAVER_LOADER_H_

#include "game/map.h"

class SaverLoader {
 private:
  Map *map;
  const char *path = "saveFile.txt";
  int saveSlot = 0;

 public:
  void saver();
  void loader();

  explicit SaverLoader(Map *map);
};

#endif  // INCLUDE_GAME_SAVER_LOADER_H_
