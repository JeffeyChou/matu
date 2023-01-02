#include "aircraft.h"

Flighter army;
Flighter enemy[MAXENEMY];
Bullet blt[MAXBLT];
Bullet blt2[MAXBLT];
Bullet blt3[MAXBLT];
BG bg;
ACL_Image gameover;
ACL_Sound firesound;
ACL_Sound bgm1;
ACL_Sound bgm2;
int yg = -50;
int cnt = 0;		//
int cnt2 = 0;
int enemyblt = 0;
int enemycnt = 0; 
int gaptime = 0;	//
int score = 40;
char txt[5] = { 48, };
int isFire = 0;		//
int isPlaySound = 0;
float fire_speed = 0;

void movePosition();
void fire();
void iscrash();
void ArmyisCrash(Flighter* enemy, Flighter* army);
void paintGameOver();
void enemyInit(Flighter* army);
void paintTitle();
void SoundPlay();
void enemyfire(Flighter* enemy, Flighter* army);
void keyAction(int key, int event);


void paint() {
	int i = 0;
	movePosition();
	beginPaint();
	clearDevice();
	setTextColor(BLACK);
	setTextSize(TXTSIZE);
	setTextFont(TXTFONT);
	paintBG(&bg);
	paintTitle();
	for (i = 0; i < MAXENEMY; i++) {
		if (enemy[i].isAlive == 1) {
			paintFlighter(&enemy[i]);
		}
	}
	for (i = 0; i < MAXBLT; i++) {
		paintBLT(&blt[i]);
		paintBLT(&blt2[i]);
		paintBLT(&blt3[i]);
	}
	if (army.isAlive == 1) {
		paintFlighter(&army);
	}
	else if (army.isAlive == 0) {
		paintGameOver();
	}
	endPaint();
}

//model
void movePosition() {
	int i = 0;
	if (army.isAlive == 1) {
		moveArmy(&army);
	}
	if (army.isAlive == 0) {
		if (yg <= W_HEIGHT/2-20) yg += 1;
	}
	for (i = 0; i < MAXENEMY; i++) {
		moveEnemy(&enemy[i],&army);
	}
	for (i = 0; i < MAXBLT; i++) {
		moveBLT(&blt[i],1);
		moveBLT(&blt2[i],1);
		moveBLT(&blt3[i], 0);
	}
	moveBG(&bg);
}

void timer(int id) {

	if (id == 0) {
		if (army.isAlive == 1) {
			iscrash();
			fire();
		}
		enemyInit(&army);
		enemyfire(&enemy[enemycnt], &army);
		paint();
		SoundPlay();
	}
}

void fire() {
	if (isFire == 1) {
		if (army.counts == 0) {
			army.counts = ARMY_BLT_FREQUENCY;
			blt[cnt] = initBLT(blt[cnt], &army, 4, 22);
			blt2[cnt2] = initBLT(blt2[cnt2], &army, 28,22);
			blt[cnt].isAlive = 1;
			blt2[cnt2].isAlive = 1;
			playSound(firesound, 0);
			if (++cnt == MAXBLT) cnt = 0;
			if (++cnt2 == MAXBLT) cnt2 = 0;
		}
		else
			army.counts--;
	}
}

void enemyInit(Flighter* army) {
	if (gaptime <= 0 && army->isAlive == 1) {
		initEnemy(&enemy[enemycnt]);
		gaptime = rand() % gaptimems * 4 + gaptimems;
		if (++enemycnt == MAXENEMY) enemycnt = 0;
	}

	else
		gaptime -= ENEMY_SPEED;
	if (score > 20 && score % 20 == 0 && ENEMY_SPEED <= 5) {
		score++;
		ENEMY_BLT_FREQUENCY -= score / 10;
		ENEMY_SPEED = score / 25;
		if (gaptime >= 10) {
			gaptimems = 20 - ENEMY_SPEED;
		}
	}
}

void enemyfire(Flighter* enemy, Flighter* army) {
	if (army->isAlive == 1 && enemy->isAlive == 1 ) {
		if (enemy->counts == 0) {
			enemy->counts = ENEMY_BLT_FREQUENCY;
			blt3[enemyblt] = initENEMYBLT(blt3[enemyblt], enemy, ENEMY_WIDTH/2, 0);
			blt3[enemyblt].isAlive = 1;
			if (++enemyblt == MAXBLT)	enemyblt = 0;
		}
		else
			enemy->counts--;
			
	}
}

void getKey(int key, int event) {
	keyAction(key, event);
}

void keyAction(int key, int event) {
	static int isMove = 0;
	if (isMove == 0 && (key == LEFT || key == UP || key == DOWN || key == RIGHT) && event == 0) {
		isMove = 1;
		switch (key) {
		case LEFT:	army.dir = LEFT;	break;
		case UP:	army.dir = UP;	break;
		case RIGHT:	army.dir = RIGHT;	break;
		case DOWN:	army.dir = DOWN;	break;
		}
	}
	else
		if (isMove == 1 && (key == LEFT || key == UP || key == DOWN || key == RIGHT) && event == 1) {
			isMove = 0;
			army.dir = 0;
		}
	if (isFire == 0 && key == FIREKEY && event == 0) {
		isFire = 1;
	}
	else
		if (isFire == 1 && key == FIREKEY && event == 1) {
			isFire = 0;
		}
}

void isHitbyBlt(Bullet* blt, Flighter* enemy) {
	if (blt->isAlive == 1 && enemy->isAlive == 1 && blt->yl <= enemy->yr && blt->yr >= enemy->yl) {
		if (!(blt->xr <enemy->xl || blt->xl > enemy->xr)) {
			blt->isAlive = enemy->isAlive = 0;
			score++;
		}
	}
}


void ArmyisCrash(Flighter* enemy, Flighter* army) {
	if (enemy->isAlive == 1 && army->isAlive == 1 ) {
		int enemy_x = (enemy->xr + enemy->xl) / 2;
		int enemy_y = (enemy->yr + enemy->yl) / 2;
			if ((enemy_x <= army->xr && enemy_x >= army->xl) && (enemy_y <= army->yr && enemy_y >= army->yl)) {
				enemy->isAlive = army->isAlive = 0;
				score++;
			}
		
	}
}

void iscrash() {
	int i, j;
	//bullet censation
	for (i = 0; i < MAXBLT; i++) {
		for (j = 0; j < MAXENEMY; j++) {
			isHitbyBlt(&blt[i], &enemy[j]);
			isHitbyBlt(&blt2[i], &enemy[j]);
			isHitbyBlt(&blt3[i], &army);
		}
	}
	//crash censation
	for (j = 0; j < MAXENEMY; j++) {
		ArmyisCrash(&enemy[j], &army);
		enemyfire(&enemy[j], &army);
	
	}
}

void SoundPlay() {
	if (isPlaySound == 0 && army.isAlive == 1) {
		playSound(bgm1, 1);
		isPlaySound = 1;
	}
	else if (isPlaySound == 1 && army.isAlive == 0) {
		stopSound(bgm1);
		isPlaySound = 2;
		playSound(bgm2, 0);
	}
}

void paintGameOver() {
	putImageTransparent(&gameover, GAMEOVER_X, yg, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, WHITE);
}

void getText(int score) {
	int s = score;
	int n = 0;
	while (s > 0) {
		s = s / 10;
		n++;
	}
	s = score;
	while (n > 0) {
		txt[n - 1] = s % 10 + 48;
		s = s / 10;
		n--;
	}
}

void paintTitle() {
	getText(score);
	paintText(2, 2, txt);
}

int Setup() {
	initWindow("AirCraft", INIT_WIDTH, INIT_HEIGHT, W_WIDTH, W_HEIGHT);
	//	initConsole();
	srand(time(NULL));
	loadImage(GAMEOVER_PATH, &gameover);
	loadSound(FIRESOUND_PATH, &firesound);
	loadSound(BGMSOUND_PATH, &bgm1);
	loadSound(GAMEOVERSOUND_PATH, &bgm2);
	bg = initBG(bg);
	initArmy(&army);
	registerKeyboardEvent(getKey);
	registerTimerEvent(timer);
	startTimer(0, TIMEINTERVAL);
	return 0;
}
