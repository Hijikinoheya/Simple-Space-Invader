#include <ncurses.h>
#include <time.h>
#include "player.h"
#include "bullet.h"

static int px, py;
static int lives = 3;
static int score = 0;
static clock_t last_shot = 0;

void init_player() {
    px = COLS / 2;
    py = LINES - 2;
}

void update_player() {
    int ch = getch();
    if (ch == KEY_LEFT && px > 0) px--;
    else if (ch == KEY_RIGHT && px < COLS - 1) px++;
    else if (ch == ' ' || ch == KEY_UP) {
        clock_t now = clock();
        if ((now - last_shot) > CLOCKS_PER_SEC) {
            add_bullet(px, py - 1, -1);
            last_shot = now;
        }
    }
}

void draw_player() {
    mvprintw(py, px, "^");
}

int get_lives() {
    return lives;
}

int get_score() {
    return score;
}

void hit_player() {
    lives--;
}

void add_score(int s) {
    score += s;
}
