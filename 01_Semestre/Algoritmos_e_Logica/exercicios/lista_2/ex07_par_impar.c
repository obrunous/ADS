#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero inteiro:\n");
    scanf("%d", &numero);

    if(numero % 2 == 0){
        printf("O numero é par.\n");

        if(numero > 15){
            printf("O numero é maior que 15.\n");
        } else {
            printf("O numero não é maior que 15.\n");
        }
    } else {
        printf("O número é impar.\n");

        if(numero < 50) {
            printf("O número é menor que 50.\n");
        } else {
            printf("O número não é menor que 50.\n");
        }
    }

    return 0;
}

/*
    O operador % calcula o resto da divisão.
    Se o resto da divisão por 2 for zero, o número é par.
*/
