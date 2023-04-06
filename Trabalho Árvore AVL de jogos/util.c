#include "util.h"

#include <stdio.h>
#include <stdlib.h>

int ano_char_to_int(char* ano_c){
    int ano;
    ano = 1000*(ano_c[0]-'0')+100*(ano_c[1]-'0')+10*(ano_c[2]-'0')+(ano_c[3]-'0');
    return ano;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}