#ifndef TOWER_OF_HANOI_DEFINED
#define TOWER_OF_HANOI_DEFINED

#define TOWER_DISCS 7

#include "./stack.h"

typedef struct towerOfHanoi {
    int moves;
    Stack stacks[3];
    
} TowerOfHanoi;

TowerOfHanoi initGame();
int getInstruction(char*, int*);

void play(TowerOfHanoi*);
int moveDisc(TowerOfHanoi*, int, int);

void printTowerState(TowerOfHanoi);
void showMoves(TowerOfHanoi, int);

#endif