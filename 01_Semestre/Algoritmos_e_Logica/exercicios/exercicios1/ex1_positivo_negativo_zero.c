/*1) Receba um número e mostre se ele é Positivo, Negativo ou 0*/

#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    if(numero > 0){
        printf("POSITIVO\n");
    } else if (numero < 0){
        printf("NEGATIVO\n");
    } else{
        printf("ZERO\n");
    }
    return 0;
}