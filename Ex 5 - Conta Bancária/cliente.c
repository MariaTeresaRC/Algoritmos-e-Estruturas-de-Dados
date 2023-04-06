#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente_{
    char* cpf;
    char* nome;
    int idade;
    double saldo;
};

CLIENTE* cliente_ler(){
    char* linha = (char*)malloc(70*sizeof(char));
    CLIENTE* cliente = (CLIENTE*)malloc(sizeof(CLIENTE));
    scanf(" %[^(\r|\n)]", linha);
    char* token = strtok(linha, ";");
    cliente->cpf = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(cliente->cpf, token);
    token = strtok(NULL, ";");
    cliente->nome = (char*)malloc(sizeof(char)*(strlen(token)+1));
    strcpy(cliente->nome, token);
    token = strtok(NULL, ";");
    int aux = 10*(token[0]-'0') + (token[1]-'0');
    cliente->idade = aux;
    token = strtok(NULL, ";");
    cliente->saldo = atof(token);
    free(linha);
    return cliente;
}

boolean cliente_apagar(CLIENTE** cliente){
    if(*cliente != NULL){
        free((*cliente)->cpf);
        free((*cliente)->nome);
        free(*cliente);
        return TRUE;
    }
    return FALSE;
}

void cliente_printa_cpf(CLIENTE* cliente){
    if((cliente->cpf[0]-'0') != 0) printf("%c", cliente->cpf[0]);
    printf("%c%c", cliente->cpf[1], cliente->cpf[2]);
    printf("%c%c%c", cliente->cpf[4], cliente->cpf[5], cliente->cpf[6]);
    printf("%c%c%c", cliente->cpf[8], cliente->cpf[9], cliente->cpf[10]);
    printf("%c%c\n", cliente->cpf[12], cliente->cpf[13]);
}

void cliente_printa_nome(CLIENTE* cliente){
    printf("%s\n", cliente->nome);
}

void cliente_mostra_saldo(CLIENTE* cliente){
    printf("%.2lf\n", cliente->saldo);
}

/* A funcao cliente_compara_cpf retorna um numero:
 *      =0 caso o cpf de c1 e c2 sejam iguais
 *      >0 caso o cpf de c1 seja maior que c2
 *      <0 caso o cpf de c2 seja maior que c1
 */
int cliente_compara_cpf(CLIENTE* c1, CLIENTE* c2){
    return strcmp(c1->cpf, c2->cpf);
}