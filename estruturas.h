#ifndef ESTRUTURAS_H  //abre o bloco para ser executado apenas uma vez pelo cmd
#define ESTRUTURAS_H //para mostrar que o arquivo ja foi incluso

#define MAX 100 //tamanho maximo da cobra
#define ALTURA 20 //altura do campo do jogo (mapa)
#define LARGURA 80// largura do campo do jogo (mapa)

#include <stdlib.h> 
#include <stdio.h>
//#include <ncurses.h> //bibilioteca para customizar o terminal
#include <ctype.h>
#include <time.h>// funçao usada para gerar um novo local para comida

//posiçoes do mapa
typedef struct position{
    int x, y;
}position;

//estrutura da cobra, tamanho e posiçao dela dentro do mapa
typedef struct snake{
    position body[MAX];//armazena a posiçao da cobra dentro do jogo
    int tamanho;//tamanho do corpo da cobra
}snake;

void movimenta__cobra(snake*, char);//funçao para captar a tecla digitada e mover a cobra
void desenha__jogo(snake*, position*);//desenha o mapa do jogo
void come__cobra(snake*, position*);//função computa se a cobra comeu ou nao
int colisao(snake*);//verifica se a cobra colidiu
void gera_nova_comida(snake*, position*);//gera novo local da comida de uma forma aleatoria
#endif //fecha o bloco