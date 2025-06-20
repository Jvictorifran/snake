#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include "estruturas.h"

// Função para capturar tecla sem precisar de Enter
char getch() {
    struct termios oldt, newt;
    char c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main() {
    srand(time(NULL));

    snake cobra;
    position comida;
    char direcao = 'd'; // Começa indo para a direita
    int gameover = 0;

    // Inicializa a cobra no centro do tabuleiro
    cobra.tamanho = 3;//define o tamanho da cobra pra 3
    cobra.body[0].x = LARGURA / 2;//coloca a cobra no meio do eixo x
    cobra.body[0].y = ALTURA / 2;//coloca a cobra no meio do eixo y
    cobra.body[1].x = cobra.body[0].x - 1;
    cobra.body[1].y = cobra.body[0].y;
    cobra.body[2].x = cobra.body[0].x - 2;
    cobra.body[2].y = cobra.body[0].y;

    // Gera a primeira comida
    gera_nova_comida(&cobra, &comida);

    while (!gameover) {
        system("clear"); // Limpa a tela no Mac/Linux
        desenha__jogo(&cobra, &comida);//desenha o jogo

        printf("Direção (WASD): ");//pede pro usuario digitar a tecla
        direcao = getch();//captura a tecla sem enter

        movimenta__cobra(&cobra, direcao);//movimenta cobra

        // Usa a função para tratar se a cobra comeu a comida
        come__cobra(&cobra, &comida);

        // Verifica colisão
        if (colisao(&cobra)) {
            gameover = 1;
        }
    }

    printf("Game Over!\n");//mostra o game over na tela
    return 0;//encerrando o programa
}