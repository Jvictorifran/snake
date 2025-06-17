#ifndef ESTRUTURAS_H  //abre o bloco para ser executado apenas uma vez pelo cmd
#define ESTRUTURAS_H //para mostrar que o arquivo ja foi incluso

#define MAX 100 //tamanho maximo da cobra
#define ALTURA 20 //altura do campo do jogo (mapa)
#define LARGURA 30// largura do campo do jogo (mapa)

#include <stdlib.h> 
#include <stdio.h>
#include <ncurses.h> //bibilioteca para customizar o terminal

//posiçoes do mapa
typedef struct position{
    int x, y;
}position;

//estrutura da cobra, tamanho e posiçao dela dentro do mapa
typedef struct snake{
    position body[MAX];//armazena a posiçao da cobra dentro do jogo
    int tamanho;//tamanho do corpo da cobra
}snake;

void movimenta__cobra(snake* cobra, char direção);//funçao para captar a tecla digitada e mover a cobra
void desenha_jogo(snake* cobra);//desenha o mapa do jogo
void desenha_cobra(snake* cobra);//desenha a cobra 
int comecobra(snake* cobra);//função computa se a cobra comeu ou nao

#endif //fecha o bloco