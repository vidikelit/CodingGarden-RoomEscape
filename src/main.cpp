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
    Room room;
    Player player(controls, 13, 11);
    map.Draw();
    map.Update();
    while(true) {
//        terminal_clear();
        //отчистка область поля комнаты
//        terminal_clear_area(1, 1, 18, 18);
        controls.Update();
        if(controls.IsExit())
            break;

        player.Update();
        terminal_refresh();
    }
}