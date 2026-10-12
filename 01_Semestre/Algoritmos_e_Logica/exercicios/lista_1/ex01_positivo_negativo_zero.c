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

/*
PROCEDIMENTO

[x] 1. Criar a variável para guardar o número.
[x] 2. Pedir um número.
[x] 3. Ler e guardar o número.
[x] 4. Se o número for maior que zero, mostrar POSITIVO.
[x] 5. Se o número for menor que zero, mostrar NEGATIVO.
[x] 6. Caso contrário, mostrar ZERO.

*/
