#ifndef CARTA_H
#define CARTA_H


#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct carta_ CARTA;

CARTA* carta_ler();
boolean carta_apagar(CARTA* carta);
int carta_valor(CARTA* carta);

#endif