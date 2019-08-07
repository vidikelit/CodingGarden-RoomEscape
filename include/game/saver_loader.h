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
  int level_;
  bool clearLine;

 public:
  void saver() override;
  void loader() override;
  void lineCheck(int lev);
  int getLevel() const;
  void setLevel(int level);
  bool isClearLine() const;
  void setClearLine(bool clearLine);
  void setMap(GameMap *gameMap);
};

#endif  // INCLUDE_GAME_SAVER_LOADER_H_
