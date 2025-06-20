#include "estruturas.h"

void movimenta__cobra(snake* cobra, char direcao){//sobre o movimento da cobra

    for (int i = cobra->tamanho - 1; i > 0; i--)
        cobra->body[i] = cobra->body[i-1];//serve para fazer a cobra seguir a cabeça

    if (direcao == ' '){
        return;//se a direçao for espaço, retorna
    }

    switch (direcao) {
        case 'w': cobra->body[0].y--; break;//caso w mova cobra para cima
        case 's': cobra->body[0].y++; break;//caso s mova cobra para baixo
        case 'a': cobra->body[0].x--; break;//caso a mova a cobra para esquerda
        case 'd': cobra->body[0].x++; break;//caso d mova a cobra para direita
    }
}

void desenha_jogo(snake* cobra, position* comida){//sobre o desenho do jogo
    
    for (int y = 0; y < ALTURA; y++){//primeiro for percorre em y
        for(int x = 0; x < LARGURA; x++){//segundo for percorre em x
           
            if (y == 0 || y == ALTURA - 1 || x == 0 || x == LARGURA - 1){// imprime a primeira linha  e ultima
                printf("#");
            }
            
            else{//desenhando a cobra, comida e espaços vazios
                
                int desenhou = 0;//variavel de controle
                
                if(cobra->body[0].x == x && cobra->body[0].y == y){//verifica a cabeça da cobra
                    printf("O");//printando a cabeça da cobra
                    desenhou = 1;
                }
                else{//desenha o corpo da cobrra
                    for(int i = 1; i < cobra->tamanho; i++){
                        if(cobra->body[i].x == x && cobra->body[i].y == y){//verifica se o corpo esta naquele local
                            printf("o");//printando o corpo 
                            desenhou = 1;
                            break;
                            
                        }
                    }
                    if(!desenhou && comida->x == x && comida->y == y){//verifica se a comida esta naquele local
                        printf("*");//desenha comida 
                        desenhou = 1;//mostra q desenhou nessa parte para nao desenhar encima desse local
                    }

                    if(!desenhou){//onde nao foi desenhado
                        printf(" ");//desenha um espaço vazio
                    }
                }
            }
        }
        printf("\n"); //quebra a linha a cada vez que sai do segundo for
    }
    
}

int comecobra(snake* cobra, position* comida){//verifica se a cobra comeu a comida, se sim retorna um se nao retorna 0
    
    if(cobra->body[0].x == comida->x && cobra->body[0].y == comida->y){ //caso a comida esteja no mesmo local da cobra 
        cobra->tamanho += 1;//se a cobra comeu a fruta ela cresce 1
        return 1;//retorne 1
    }

    return 0;//se nao retorna 0
}

int colisao(snake* cobra){
    for(int i = 0; i < cobra->tamanho; i++){
        if(cobra->body[0].x == cobra->body[i].x && cobra->body[0].x == cobra->body[0].x)//comparo para ver se a cabeça colidiu com o corpo 
            return 1;
        }
    if(cobra->body[0].x <= 0 || cobra->body[0].x >= LARGURA-1 || cobra->body[0].y == 0 || cobra->body[0].y == ALTURA - 1 )//se colidir com as bordas return 1
        return 1;

    return 0; //caso nao colida return 0  
}
