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

void desenha_jogo(snake* cobra){//sobre o desenho do jogo
    
    for (int y = 0; y < ALTURA; y++){
        for(int x = 0; x < LARGURA; x++){
           
            if (y == 0 || y == ALTURA - 1){// imprime a primeira linha  e ultima
                printf("#");
            }

            else if(x == 0 || x == LARGURA - 1){// imprime a primeira e ultima coluna
                printf("#");
            }

            else{
                desenha_cobra(cobra);
                printf(" ");//imprime o meio do quadraro (ainda precisa de tratamento)
            }
        }
        printf("\n"); //quebra a linha a cada vez que sai do segundo for
    }
}

void desenha_cobra(snake* cobra){//sobre o desenho da cobra
    
    for (int y = 0; y < ALTURA; y++){
        for (int x = 0; x < LARGURA; x++){//percorro sobre o mapa todo
            
            int desenhou = 0;

            if(cobra->body[0].x == x && cobra->body[0].y == y){ //se a cabeça da cobra for encontrada eu a desenho
               
                printf("<8");//printando a cabeça da cobra
                desenhou = 1;
            }
            else{//caso nao seja a cabeça desenha o corpo
                
                for(int i = 1; i < cobra->tamanho; i++){//percorre e desenha todo o corpo
                    
                    if(cobra->body[i].x == x && cobra->body[i].y == y){
                        printf("o");//printando o corpo 
                        desenhou = 1;
                        break;
                    }
                }
            }

            if(!desenhou){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int comecobra(snake* cobra, position* comida){
    return;
}


