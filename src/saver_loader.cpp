#include "game/saver_loader.h"
#include <stdio.h>
#include "game/map.h"
#include "game/room.h"

void SaverLoader::saver() {
  FILE *file;

  file = fopen(path, "a");
  for (unsigned int i = 1; i < map->getRooms().size(); i++) {
    fprintf(file, "%d,%d;", map->getRooms().at(i).getX(), map->getRooms().at(i).getY());
    if (feof(file)) {
      break;
    }
  }
  fprintf(file, "/\n");
  fclose(file);
}

void SaverLoader::loader() {
  FILE *file;
  int x = 0, y = 0, n = 0;
  char ch;
  char symbol = '/';
  Room room(x, y);

  file = fopen(path, "r");
  if (saveSlot != 0) {
    while (n != saveSlot) {
      fscanf(file, "\n");
      n++;
    }
  }
  while (!feof(file)) {
    fscanf(file, "%c", &ch);
    fseek(file, - 1, SEEK_CUR);
    if (ch == symbol) break;
    fscanf(file, "%d,%d;", &x, &y);
    room.setX(x);
    room.setY(y);
    map->setRooms(Room(room.getX(), room.getY()));
  }
  fclose(file);
}

SaverLoader::SaverLoader(Map *map) : map(map) {}
