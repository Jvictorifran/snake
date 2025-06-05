#include "libs.h"

#ifndef SNAKE_H
#define SNAKE_H

#include "libs.h"
#define TAMANHO_MAXIMO 100

typedef struct {
    position body[TAMANHO_MAXIMO];
    int tamanho;
} snake;

void inicializar_cobra(snake *cobra, int x, int y, int tamanho_inicial);
void desenhar_cobra(const snake *cobra);
// Outras funções que desejar

#endif // SNAKE_H