#ifndef ESTRUTURAS_H  //abre o bloco para ser executado apenas uma vez pelo cmd
#define ESTRUTURAS_H //para mostrar que o arquivo ja foi incluso

#define MAX 100

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

//posiçoes do mapa
typedef struct position{
    int x, y;
}position;

typedef struct snake{
    char body[MAX];
    int tamanho;
}snake;


#endif //fecha o bloco