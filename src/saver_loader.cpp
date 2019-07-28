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
    if (newLine == saveSlot_) break;
    if (textSave.at(i) == '\n') newLine++;
    cell++;
  }
  // удаление слота
  for (unsigned int i = 0;; i++) {
    if (textSave.at(cell) == '\n') break;
    textSave.erase(textSave.begin() + cell);
  }
  // формирование данных
  for (unsigned int i = 1; i < gameMap->getRooms().size(); i++) {
    str = std::to_string(gameMap->getRooms().at(i).getX());
    for (auto s : str) {
      textSave.insert(textSave.begin() + cell++, s);
    }
    textSave.insert(textSave.begin() + cell++, ',');
    str = std::to_string(gameMap->getRooms().at(i).getY());
    for (auto s : str) {
      textSave.insert(textSave.begin() + cell++, s);
    }
    textSave.insert(textSave.begin() + cell++, ';');
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
  while (newLine != saveSlot_) {
    fscanf(file, "%c", &ch);
    if (ch == '\n') newLine++;
  }
  while (!feof(file)) {
    fscanf(file, "%c", &ch);
    fseek(file, -1, SEEK_CUR);
    if (ch == '\n') break;
    fscanf(file, "%d,%d;", &x, &y);
    gameRoom.setX(x);
    gameRoom.setY(y);
    gameMap->setRooms(GameRoom(gameRoom.getX(), gameRoom.getY()));
  }
  fclose(file);
}

void SaverLoader::setSaveSlot(int saveSlot) {
  SaverLoader::saveSlot_ = saveSlot;
}
void SaverLoader::setMap(GameMap *gameMap) {
  SaverLoader::gameMap = gameMap;
}

