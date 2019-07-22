#include "game/saver_loader.h"
#include <stdio.h>
#include "game/map.h"
#include "game/room.h"

void SaverLoader::saver() {
  FILE *file;

  file = fopen(path, "a");
  for (int i = 0; i < map->getRooms().size(); i++) {
    fprintf(file, "%d,%d;", map->getRooms().at(i).getX(), map->getRooms().at(i).getY());
    if (feof(file)) {
      break;
    }
  }
  fclose(file);
}

void SaverLoader::loader() {
  FILE *file;
  int x, y;
  Room room(x, y);

  file = fopen(path, "r");
  while (!feof(file)) {
    fscanf(file, "%d,%d;", &x, &y);
    room.setX(x);
    room.setY(y);
    map->setRooms(Room(room.getX(), room.getY()));
  }
  fclose(file);
}

SaverLoader::SaverLoader(Map *map) : map(map) {}
