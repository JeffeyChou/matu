#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_

#include "acllib.h"
#include "setting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct _bg {
	ACL_Image image;
	int x, y1, y2;
}BG;

typedef struct _flighter {
	ACL_Image image;
	int width, height;
	int xl, yl, xr, yr;
	int dir;
	int isAlive;
	int counts;
}Flighter;

typedef struct _bullet {
	ACL_Image image;
	int width, height;
	int xl, yl, xr, yr;
	int isAlive;
}Bullet;

void initArmy(Flighter* army) {
	loadImage("data/army.bmp", &(army->image));
	army->isAlive = 1;
	army->width = ARMY_WIDTH;
	army->height = ARMY_HEIGHT;
	army->xl = W_WIDTH / 2-army->width/2;
	army->yl = W_HEIGHT / 3 * 2 - army->height / 2;
	army->xr = army->xl + army->width ;
	army->yr = army->yl + army->height ;
	army->dir = 0;
	army->counts = ARMY_BLT_FREQUENCY;
}

void initEnemy(Flighter* enemy) {
	loadImage("data/enemy.bmp", &(enemy->image));
	enemy->isAlive = 1;
	enemy->width = ENEMY_WIDTH;
	enemy->height = ENEMY_HEIGHT;
	enemy->xl = (rand() % W_WIDTH) + ENEMY_WIDTH;
	enemy->yl = enemy->height-30;
	enemy->xr = enemy->xl + enemy->width ;
	enemy->yr = enemy->yl + enemy->height ;
	enemy->dir = 0;
	enemy->counts = ENEMY_BLT_FREQUENCY;
}
Bullet initBLT(Bullet blt, Flighter* f, int x_offset, int y_offset) {
	loadImage(BLT_PATH, &blt.image);
	blt.width = BLT_WIDTH;
	blt.height = BLT_HEIGHT;
	blt.isAlive = 0;
	blt.xl = f->xl + x_offset;
	blt.yl = f->yl + y_offset;
	blt.xr = blt.xl + blt.width;
	blt.yr = blt.yl + blt.height;
	return blt;
}

Bullet initENEMYBLT(Bullet blt, Flighter* f, int x_offset, int y_offset) {
	loadImage(ENEMY_BLT_PATH, &blt.image);
	blt.width = BLT_WIDTH;
	blt.height = BLT_HEIGHT;
	blt.isAlive = 0;
	blt.xl = f->xl + x_offset;
	blt.yl = f->yl + y_offset;
	blt.xr = blt.xl + blt.width ;
	blt.yr = blt.yl + blt.height ;
	return blt;
}

BG initBG(BG bg) {
	loadImage("data/bg.bmp", &bg.image);
	bg.x = 0;
	bg.y1 = 0;
	bg.y2 = -W_HEIGHT + 1;
	return bg;
}

//motion
void moveEnemy(Flighter* enemy, Flighter* army) {
	if (enemy->isAlive == 1) {
		int enemyx = enemy->xl + enemy->width / 2;
		int enemyy = enemy->yl + enemy->height / 2;
		int armyx = army->xl + army->width / 2;
		int armyy = army->yl + army->height / 2;
		int dx = armyx - enemyx;
		int dy = armyy - enemyy;
		double sqrx = (ENEMY_SPEED) * dx / sqrt(dx * dx + dy * dy);
		double sqry = (ENEMY_SPEED) * dy / sqrt(dx * dx + dy * dy);
		enemy->xl += sqrx;
		enemy->yl += sqry;
		enemy->xr = enemy->xl + enemy->width ;
		enemy->yr = enemy->yl + enemy->height;
	}
	if (army->isAlive == 0) {
		enemy->yl += 10;
		enemy->yr +=  enemy->yl + 10;
	}
}
void moveArmy(Flighter* f) {
	switch (f->dir) {
	case LEFT:	(f->xl >= 0) ? (f->xl -= ARMY_SPEED, f->xr -= ARMY_SPEED) : 1;
		break;
	case RIGHT:	(f->xr <= W_WIDTH) ? (f->xl += ARMY_SPEED, f->xr += ARMY_SPEED) : 1;
		break;
	case UP:	(f->yl >= 0) ? (f->yl -= ARMY_SPEED, f->yr -= ARMY_SPEED) : 1;
		break;
	case DOWN:	(f->yr <= W_HEIGHT) ? (f->yl += ARMY_SPEED, f->yr += ARMY_SPEED) : 1;
		break;
	default:
		;
	}
}
void moveBLT(Bullet* blt,int type) {
	if (blt->isAlive == 1) {
		if (type == 1) {
			blt->yl -= FIRE_SPEED;
			blt->yr = blt->yl + blt->height;
		}
		if (type == 0) {
			blt->yl += 3;
			blt->yr = blt->yl + blt->height;
		}
	}
	if (blt->yl < 0 || blt->yr > W_HEIGHT) {
		blt->isAlive = 0;
	}
}
void moveBG(BG* bg) {
	bg->y1++;
	bg->y2++;
	if (bg->y1 == W_HEIGHT) {
		bg->y1 = -W_HEIGHT + 1;
	}
	if (bg->y2 == W_HEIGHT) {
		bg->y2 = -W_HEIGHT + 1;
	}
}

void paintFlighter(Flighter* f) {
	if (f->isAlive == 1) {
		putImageTransparent(&(f->image), f->xl, f->yl, f->width, f->height, WHITE);
	}
}
void paintBLT(Bullet* blt) {
	if (blt->isAlive == 1) {
		putImageTransparent(&(blt->image), blt->xl, blt->yl, blt->width, blt->height, WHITE);
	}
}
void paintBG(BG* bg) {
	putImage(&(bg->image), bg->x, bg->y1);
	putImage(&(bg->image), bg->x, bg->y2);
}


#endif
#pragma once
