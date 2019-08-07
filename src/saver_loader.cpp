#include "game/saver_loader.h"
#include <stdio.h>
#include <string>
#include "game/gameMap.h"
#include "game/gameRoom.h"

void SaverLoader::saver() {
  std::string str;
  char ch;
  int newLine = 0, cell = 0;

  textSave.clear();
  // собираем содержимое файла
  file = fopen(path, "r");
  while (!feof(file)) {
    if (ch == '/') break;
    fscanf(file, "%c", &ch);
    textSave.push_back(ch);
  }
  for (unsigned int i = 0; i < textSave.size(); i++) {
    if (newLine == level_) break;
    if (textSave.at(i) == '\n') newLine++;
    cell++;
  }
  // удаление слота
  for (int i = 0;; i++) {
    if (textSave.at(cell) == '\n') break;
    textSave.erase(textSave.begin() + cell);
  }
  // сохранение координат комнат
  for (unsigned int i = 1; i < gameMap->getRooms().size(); i++) {
    str = std::to_string(gameMap->getRooms().at(i).getX());
    for (auto s : str) textSave.insert(textSave.begin() + cell++, s);
    textSave.insert(textSave.begin() + cell++, ',');
    str = std::to_string(gameMap->getRooms().at(i).getY());
    for (auto s : str) textSave.insert(textSave.begin() + cell++, s);
    textSave.insert(textSave.begin() + cell++, ';');
  }
  textSave.insert(textSave.begin() + cell++, 'c');
  // сохранение координат монет
  for (auto room : gameMap->getRooms()) {
    for (auto coin : room.getCoins()) {
      str = std::to_string(coin.getX());
      for (auto s : str) textSave.insert(textSave.begin() + cell++, s);
      textSave.insert(textSave.begin() + cell++, ',');
      str = std::to_string(coin.getY());
      for (auto s : str) textSave.insert(textSave.begin() + cell++, s);
      textSave.insert(textSave.begin() + cell++, ';');
    }
    textSave.insert(textSave.begin() + cell++, 'c');
  }
  fclose(file);
  // записываем новые данные в файл
  file = fopen(path, "w");
  for (unsigned int i = 0; i < textSave.size(); i++) {
    fprintf(file, "%c", textSave.at(i));
  }
  fclose(file);
}

void SaverLoader::loader() {
  char ch;
  int x = 0, y = 0, newLine = 0;
  GameRoom gameRoom(x, y);

  file = fopen(path, "r");
  while (newLine != level_) {
    fscanf(file, "%c", &ch);
    if (ch == '\n') newLine++;
  }
  while (!feof(file)) {
    fscanf(file, "%c", &ch);
    if (ch == 'c') break;
    fseek(file, -1, SEEK_CUR);
    fscanf(file, "%d,%d;", &x, &y);
    gameMap->formRoom(x, y);
  }
  int r = 0;
  while (!feof(file)) {
    fscanf(file, "%c", &ch);
    if (ch == 'c') {
      fscanf(file, "%c", &ch);
      if (ch == '\n') break;
      if (ch == 'c') break;
      r++;
    }
    fseek(file, -1, SEEK_CUR);
    if (ch == '\n') break;
    fscanf(file, "%d,%d;", &x, &y);
    gameMap->formCoin(x, y, r);
  }
  fclose(file);
}
void SaverLoader::setMap(GameMap* gameMap) {
  SaverLoader::gameMap = gameMap;
}
int SaverLoader::getLevel() const {
  return level_;
}
void SaverLoader::setLevel(int level) {
  level_ = level;
}
void SaverLoader::lineCheck(int lev) {
  std::string str;
  char ch;
  int newLine = 0;

  textSave.clear();
  // собираем содержимое файла
  file = fopen(path, "r");
  while (!feof(file)) {
    if (ch == '/') break;
    fscanf(file, "%c", &ch);
    textSave.push_back(ch);
  }
  for (unsigned int i = 0; i < textSave.size(); i++) {
    if (newLine == lev) {
      if ((textSave.at(i) == '\n' && textSave.at(i + 1) == '\n') ||
          (textSave.at(i) == '\n' && textSave.at(i + 1) == '/')) {
        clearLine = true;
        break;
      }
        clearLine = false;
      break;
    }
    if (textSave.at(i) == '\n')
      newLine++;
  }
  fclose(file);
}
bool SaverLoader::isClearLine() const {
  return clearLine;
}
void SaverLoader::setClearLine(bool clearLine) {
  SaverLoader::clearLine = clearLine;
}
