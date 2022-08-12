#include <stdio.h>
#include <stdlib.h>

#include "./towerOfHanoi.h"

int main() {
    TowerOfHanoi tower = initGame();

    play(&tower); 
}
