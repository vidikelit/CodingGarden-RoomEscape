#include "../include/door.h"
#include <cmath>


void Door::scanner() {
    if(controls.isE()){
        for(int i = 0; i <= 4;i++){
            if(sqrt(pow(doorsCoords[i][0] - player.getX(), 2) + pow(doorsCoords[i][1] - player.getY(), 2)))
                teleport();
        }
    }
}
void Door::teleport() {

}

Door::Door(Controls &controls, Player &player) : controls(controls), player(player) {

}




