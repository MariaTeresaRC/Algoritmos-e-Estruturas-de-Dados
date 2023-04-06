#include <stdio.h>
#include "ponto.h"
#include "caminho.h"

int main(){

    int N;

    scanf("%d", &N);

    CAMINHO* caminho;
    caminho = caminho_criar(N);

    float x, y;
    PONTO* ponto;
    for(int i=0; i<N; i++){
        scanf("%f %f", &x, &y);
        ponto = ponto_criar(x, y);
        caminho_adicionar_ponto(caminho, ponto);
    }

    printf("%.2f", caminho_distancia(caminho));

    return 0;
}
