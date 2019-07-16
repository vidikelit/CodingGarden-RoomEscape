#include <BearLibTerminal.h>
#include "../include/controls.h"
#include "../include/player.h"
#include "../include/window.h"
#include "../include/map.h"


int main()
{
    srand(time(NULL));
    Window window;
    terminal_open();
    window.Settings();
    terminal_refresh();

    Controls controls;
    Map map;

    Player player(controls, 11, 11);
    map.generator();
    map.render(0);
    while(true) {
//        отчистка области поля комнаты
        terminal_layer(1);
        terminal_clear_area(1, 1, 19, 19);
        terminal_layer(0);

        controls.Update();
        if(controls.isE()){
            map.scanner(player.getX(), player.getY(), map.number_room_);
        }
        if(controls.isExit())
            break;
        player.update();
        terminal_refresh();
    }
    terminal_close();
}