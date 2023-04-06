/* SCC0502 - Algoritmos e Estruturas de Dados 1
 * 
 * Aluno: Maria Teresa Raetano Cardoso
 * n USP: 10748604
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "jogo.h"
#include "arvore.h"

int main(){

    int ordem;      //recebe a forma de impressao da arvore
    char remove[4];     //recebe o ano a ser removido, ou 'F' para indicar o encerramento do programa

    scanf(" %d", &ordem);

    ARVORE* arvore = ler_CSV();

    while(scanf(" %s", remove)>0){
        if(strcmp(remove, "F")==0){
            break;
        }else{
            arvore_remocao(arvore, ano_char_to_int(remove));
        }
    }

    switch(ordem){
    case 1:
        arvore_pre_ordem(arvore);
        break;
    case 2:
        arvore_em_ordem(arvore);
        break;
    case 3:
        arvore_pos_ordem(arvore);
        break;
    }

    arvore_apagar(&arvore);

    return 0;
}