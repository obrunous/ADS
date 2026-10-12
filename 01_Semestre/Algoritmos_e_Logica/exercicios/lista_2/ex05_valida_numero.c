#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero:\n");
    scanf("%d", &numero);


    if((numero >= 50 && numero <= 70) || numero > 100){
        printf("Válido!\n");
    } else {
        printf("Este número não é valido.\n");
    }

    return 0;
}