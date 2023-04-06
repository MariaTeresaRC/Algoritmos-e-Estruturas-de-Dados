#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "arvore.h"

int main(){

    int num;
    char op;
    char* cpf = (char*)malloc(15*sizeof(char));
    scanf(" %d", &num);
    CLIENTE* cliente;
    ARVORE* arvore = arvore_criar();

    for(int i=0; i<num; i++){
        cliente = cliente_ler();
        arvore_insercao(arvore, cliente);
    }

    scanf(" %c", &op);
    switch(op){
    case 'I':
        cliente = cliente_ler();
        arvore_insercao(arvore, cliente);
        arvore_pre_ordem(arvore);
        break;
    case 'R':
        scanf(" %[^(\r|\n)]", cpf);
        arvore_remocao(arvore, cpf);
        arvore_pre_ordem(arvore);
        break;
    case 'B':
        scanf(" %[^(\r|\n)]", cpf);
        cliente_print(arvore_busca(arvore, cpf));
        printf("\n");
        break;
    }

    arvore_apagar(&arvore);
    free(cpf);

    return 0;
}