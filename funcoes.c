#include "estruturas.h"

void movimenta__cobra(snake* cobra, char direcao){

    for (int i = cobra->tamanho - 1; i > 0; i--)
        cobra->body[i] = cobra->body[i-1];

    if (direcao == ' '){
        return;
    }

    switch (direcao) {
        case 'w': cobra->body[0].y--; break;
        case 's': cobra->body[0].y++; break; 
        case 'a': cobra->body[0].x--; break;
        case 'd': cobra->body[0].x++; break; 
    }
}

void desenha_jogo(){
    return;
}
