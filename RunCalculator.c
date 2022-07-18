#include<stdio.h>
#include<stdlib.h>
#include"PosfixCalculator.h"

int main(int argc, char *argv[]) {
    if(argc > 1){
        calculate(argv[1]);
    }else{
        char expresssion[CHAR_LENGTH_LIMIT+1];
        printf("Digite a expressao\n");
        scanf("%s",expresssion);
        calculate(expresssion);
    }
    return(0);
}
