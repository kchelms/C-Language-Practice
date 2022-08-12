#include "./towerOfHanoi.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void fillTower(TowerOfHanoi* t) {
    Stack* s = &t->stacks[0];

    int size = TOWER_DISCS;

    while(push(s, size--));
}

TowerOfHanoi initGame() {
    TowerOfHanoi t;

    t.moves = 0;
    t.stacks[0] = newStack(TOWER_DISCS);
    t.stacks[1] = newStack(TOWER_DISCS);
    t.stacks[2] = newStack(TOWER_DISCS);

    fillTower(&t);
    
    return t;
}

void play(TowerOfHanoi* tower) {
    FILE* moves_record = fopen("./moves.txt", "r");

    do {
        printTowerState(*tower);  

        size_t line_size = 32 * sizeof(char);
        char* line = (char*)malloc(line_size);

        getline(&line, &line_size, moves_record);

        int instruction[2];

        if(!getInstruction(line, instruction)) {
            printf("Invalid Instruction");
            continue;
        }

        if(instruction[0] == 4) {
            showMoves(*tower, instruction[1]);
        }

        else {
            if(!moveDisc(tower, instruction[0], instruction[1]))
                printf("Illegal Move");
        }
        
    } while(tower->stacks[2].size < 7);

    printTowerState(*tower);

    fclose(moves_record);    
}



int getInstruction(char* string, int* out) {
    int ret = 0;

    char* cmds[2];

    cmds[0] = strtok(string, " \n");

    if(!(cmds[1] = strtok(NULL, " \n"))) {
        cmds[1] = cmds[0];
        cmds[0] = "4";
    } 

    out[0] = (cmds[0][0] >= '1' && cmds[0][0] <= '4') ? ((int)(cmds[0][0] - '0')) : 0;
    out[1] = (cmds[1][0] >= '1' && cmds[1][0] <= '3') ? ((int)(cmds[1][0] - '0')) : 0;

    if(out[0] != 0) {
        ret = 1;    
    }

    return ret;
}

int moveDisc(TowerOfHanoi* t, int from, int to) {
    int ret = 0;

    Stack *f_stack = &(t->stacks[from - 1]), *t_stack = &(t->stacks[to - 1]);

    if(f_stack->size > 0 && (*(f_stack->top) < *(t_stack->top) || t_stack->size == 0)) {
        int f_pop = 0;

        pop(f_stack, &f_pop);
        
        push(t_stack, f_pop);

        t->moves++;

        ret = 1;
    }

    return ret;
}

void printTowerState(TowerOfHanoi t) {
    system("clear");

    printf("\n\n");

    Stack* towers = t.stacks;

    char toPrint;
    
    for(int i = TOWER_DISCS; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            int disc;

            toPrint = (towers[j].size == i && pop(&towers[j], &disc))? ('0' +  disc) : '|';

            printf("    %c  ", toPrint);
        }

        printf("\n");
    }

    printf("_______________________\n\n");
}

void showMoves_helper(TowerOfHanoi t, int tower) {
    for(int i = 0; i < 3; i++) {
        if(i == tower)
            continue;

        int fromTowerHasDisc = t.stacks[tower].size;
        int movedDiscIsSmaller = (*t.stacks[i].top > *t.stacks[tower].top) || t.stacks[i].size == 0;

        if(fromTowerHasDisc && movedDiscIsSmaller)
            printf("    %d  %d", tower + 1, i + 1);
    }
}

void showMoves(TowerOfHanoi t, int tower) {
    if(tower != 0)
        return showMoves_helper(t, tower - 1);
        
    for(int i = 0; i < 3; i++)
        showMoves_helper(t, i);
}