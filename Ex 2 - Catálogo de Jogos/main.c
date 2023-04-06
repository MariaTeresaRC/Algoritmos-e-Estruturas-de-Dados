#include <stdio.h>
#include <string.h>
#include "jogo.h"
#include "catalogo.h"

int main(){

    CATALOGO* catalogo = catalogo_criar();
    JOGO* jogo;
    char comando;
    char nome[30], empresa[30];
    int ano;
    int exit = FALSE;       //flag para controlar a ordem de execução do programa

    do{
        scanf(" %c", &comando);
        if(comando == 'F') exit = TRUE;
        if (exit != TRUE){
            ungetc(comando, stdin);
            scanf(" %[^(\r|\n)]", nome);
            scanf(" %[^(\r|\n)]", empresa);
            scanf(" %d", &ano);
            jogo = jogo_criar(nome, empresa, ano);
            catalogo_adicionarjogo(catalogo, jogo);
        } 
    }while(exit == FALSE);

    exit = FALSE;

    do{
        scanf(" %c", &comando);
        if(comando == 'F') exit = TRUE;
        if(exit != TRUE){
            switch (comando){
            case 'A':
                scanf(" %d", &ano);
                if(!(catalogo_busca_ano(catalogo, ano))){
                    printf("Nada encontrado\n");
                }
                break;
            
            case 'E':
                scanf(" %[^(\r|\n)]", empresa);
                if(!(catalogo_busca_empresa(catalogo, empresa))){
                    printf("Nada encontrado\n");
                }
                break;
            }
        }
    } while (exit == FALSE);
    
    catalogo_apagar(catalogo);

    return 0;
}