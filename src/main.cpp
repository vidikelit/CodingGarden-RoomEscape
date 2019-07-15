#include <BearLibTerminal.h>
#include "../include/controls.h"
#include "../include/room.h"
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
    map.Update();
    while(true) {
////        отчистка области поля комнаты
//        terminal_clear_area(1, 1, 18, 18);
        controls.Update();
        if(controls.IsExit())
            break;

        player.Update();
        terminal_refresh();
    }
}