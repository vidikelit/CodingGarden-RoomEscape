#ifndef INCLUDE_GAME_SAVER_LOADER_H_
#define INCLUDE_GAME_SAVER_LOADER_H_

#include <stdio.h>
#include <vector>
#include "game/gameMap.h"
#include "game/lib/i_saver_loader.h"

class SaverLoader: public ISaverLoader{
 private:
  GameMap *gameMap;
  FILE *file;
  const char *path = "saveFile.txt";
  std::vector<char> textSave{};
  int saveSlot_ = 0;

 public:
  void saver() override;
  void loader() override;

  void setSaveSlot(int saveSlot);
  void setMap(GameMap *gameMap);
};

#endif  // INCLUDE_GAME_SAVER_LOADER_H_
