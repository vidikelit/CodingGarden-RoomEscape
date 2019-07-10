#include <BearLibTerminal.h>
#include "../include/controls.h"
#include "../include/player.h"
#include "../include/window.h"

int main()
{
    Window window;
    terminal_open();
    window.Settings();
    terminal_refresh();


    int x = 1;
    int y = 1;

    Controls controls;
    Player player(controls, x, y);
    while(true) {
        terminal_clear();

        controls.Update();
        if(controls.IsExit())
            break;

        player.Update();

        terminal_refresh();
    }
}