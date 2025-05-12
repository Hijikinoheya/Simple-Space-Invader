#include <ncurses.h>
#include <stdlib.h>
#include "enemy.h"
#include "player.h"

#define MAX_ENEMIES 20

typedef struct {
    int x, y, alive;
} Enemy;

static Enemy enemies[MAX_ENEMIES];

void init_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].x = rand() % COLS;
        enemies[i].y = rand() % (LINES / 3);
        enemies[i].alive = 1;
    }
}

void update_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive && rand() % 100 < 1) {
            enemies[i].y++;
            if (enemies[i].y >= LINES - 2) {
                enemies[i].y = 0;
                enemies[i].x = rand() % COLS;
                hit_player();
            }
        }
    }
}

void draw_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive) {
            mvprintw(enemies[i].y, enemies[i].x, "V");
        }
    }
}

int check_hit(int x, int y) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].alive && enemies[i].x == x && enemies[i].y == y) {
            enemies[i].alive = 0;
            add_score(100);
            return 1;
        }
    }
    return 0;
}
