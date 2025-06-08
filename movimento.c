#include "movimento.h"
#include "libs.h"
#include "snake.h"


char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int mover_cobra(snake *cobra, position *comida, int *pontos, int *game_over, int *velocidade, char direcao){
    //variavies
    int i;

    //verifico se a cobra esta  "viva"

    position nova_cabeca = cobra->body[0];
    if(cobra->tamanho <= 0){
        *game_over = 1;
        return 0;
    }

    // movimenta a cobra pelos eixos x e y
    // dependendo da direção informada
    // w = cima, s = baixo, a = esquerda, d = direita
    if (direcao == ' ') {
        return 0; // Se a direção for espaço, não move a cobra
    }
    switch(to_lower(direcao)){
        case 'w':
            nova_cabeca.y -= 1;
            break;
        case 's':
            nova_cabeca.y += 1;
            break;
        case 'a':
            nova_cabeca.x -= 1;
            break;
        case 'd':
            nova_cabeca.x += 1;
            break;
        default:
            printf("Direção inválida!\n");
            return 0;
    }

    for (i = cobra->tamanho -1 > 0; i >= 0; i --) {
        cobra->body[i] = cobra->body[i - 1];
    }
    

    if (comida->x == cobra->body[0].x && comida->y == cobra->body[0].y){
        cobra->tamanho += 1;
    }
}
