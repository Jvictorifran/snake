#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include "libs.h"
#include "snake.h"

typedef struct{
    int x, y;
}position;

int mover_cobra(snake *cobra, position *comida, int *pontos, int *game_over, int *velocidade, char direcao);

#endif // MOVIMENTO_H