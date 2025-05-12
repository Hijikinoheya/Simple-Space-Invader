#include <ncurses.h>
#include <stdlib.h>
#include "bullet.h"
#include "enemy.h"

#define MAX_BULLETS 100

typedef struct {
    int x, y, dir;
    int alive;
} Bullet;

static Bullet bullets[MAX_BULLETS];

void init_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) bullets[i].alive = 0;
}

void cleanup_bullets() {
    // 今は特に必要なし
}

void add_bullet(int x, int y, int dir) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].alive) {
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].dir = dir;
            bullets[i].alive = 1;
            break;
        }
    }
}

void update_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive) {
            bullets[i].y += bullets[i].dir;
            if (bullets[i].y < 0 || bullets[i].y >= LINES) {
                bullets[i].alive = 0;
            }
        }
    }
}

void draw_bullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive) {
            mvprintw(bullets[i].y, bullets[i].x, "|");
        }
    }
}

void check_collisions() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].alive && bullets[i].dir == -1) {
            if (check_hit(bullets[i].x, bullets[i].y)) {
                bullets[i].alive = 0;
            }
        }
    }
}
