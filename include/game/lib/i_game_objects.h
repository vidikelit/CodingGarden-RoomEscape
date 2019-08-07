#ifndef INCLUDE_GAME_LIB_I_GAME_OBJECTS_H_
#define INCLUDE_GAME_LIB_I_GAME_OBJECTS_H_

class IGameObjects {
  virtual void update() = 0;
  virtual void render() = 0;
};

#endif  // INCLUDE_GAME_LIB_I_GAME_OBJECTS_H_
