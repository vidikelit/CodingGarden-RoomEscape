#include "game/saver_loader.h"
#include <stdio.h>
#include <string>
#include "game/map.h"
#include "game/room.h"

void SaverLoader::saver() {
  char ch;
  int newLine = 0;
  int cell = 0;
  std::string str;
  char symbol = '\n';

  textSave.clear();
  // собираем содержимое файла
  file = fopen(path, "r");
  while (!feof(file)) {
    if (ch == '/') break;
    fscanf(file, "%c", &ch);
    textSave.push_back(ch);
  }
  for (unsigned int i = 0; i < textSave.size(); i++) {
    if (newLine == saveSlot) break;
    if (textSave.at(i) == symbol) newLine++;
    cell++;
  }
  // удаление слота
  for (unsigned int i = 0;; i++) {
    if (textSave.at(cell) == symbol) break;
    textSave.erase(textSave.begin() + cell);
  }
  // формирование данных
  for (unsigned int i = 1; i < map->getRooms().size(); i++) {
    str = std::to_string(map->getRooms().at(i).getX());
    for (auto s : str) {
      textSave.insert(textSave.begin() + cell++, s);
    }
    textSave.insert(textSave.begin() + cell++, ',');
    str = std::to_string(map->getRooms().at(i).getY());
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
  int x = 0, y = 0;
  char ch;
  int newLine = 0;
  Room room(x, y);

  file = fopen(path, "r");
  while (newLine != saveSlot) {
    fscanf(file, "%c", &ch);
    if (ch == '\n') newLine++;
  }
  while (!feof(file)) {
    fscanf(file, "%c", &ch);
    fseek(file, -1, SEEK_CUR);
    if (ch == '\n') break;
    fscanf(file, "%d,%d;", &x, &y);
    room.setX(x);
    room.setY(y);
    map->setRooms(Room(room.getX(), room.getY()));
  }
  fclose(file);
}

SaverLoader::SaverLoader(Map *map) : map(map) {}

int SaverLoader::getSaveSlot() const {
  return saveSlot;
}
void SaverLoader::setSaveSlot(int saveSlot) {
  SaverLoader::saveSlot = saveSlot;
}
void SaverLoader::setMap(Map *map) {
  SaverLoader::map = map;
}
SaverLoader::SaverLoader() {}
