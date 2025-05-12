#include <ncurses.h>
#include "game.h"

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();

    init_game();
    game_loop();
    end_game();

    endwin();
    return 0;
}
