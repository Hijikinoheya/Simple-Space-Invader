#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

static int running = 1;

void init_game() {
    srand(time(NULL));
    init_player();
    init_enemies();
    init_bullets();
}

void game_loop() {
    while (running) {
        clear();
        update_player();
        update_enemies();
        update_bullets();
        check_collisions();
        draw_player();
        draw_enemies();
        draw_bullets();
        mvprintw(0, 0, "Score: %d  Lives: %d", get_score(), get_lives());
        refresh();
        if (get_lives() <= 0) running = 0;
        napms(33);  // 約30FPS
    }
}

void end_game() {
    cleanup_bullets();
}
