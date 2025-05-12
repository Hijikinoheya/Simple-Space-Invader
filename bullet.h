#ifndef BULLET_H
#define BULLET_H

void init_bullets();
void update_bullets();
void draw_bullets();
void add_bullet(int x, int y, int dir);
void check_collisions();
void cleanup_bullets();

#endif
