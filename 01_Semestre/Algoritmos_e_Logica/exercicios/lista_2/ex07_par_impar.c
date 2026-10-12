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

/*
ENUNCIADO (descrição baseada no código atual)

Elabore um programa que leia um número inteiro e informe se ele é par ou ímpar.
Se for par, informe também se ele é maior que 15.
Se for ímpar, informe também se ele é menor que 50.

PROCEDIMENTO

[x] 1. Criar a variável para guardar o número inteiro.
[x] 2. Pedir um número inteiro.
[x] 3. Ler e guardar o número.
[x] 4. Se o resto da divisão por 2 for zero, mostrar que o número é par.
[x] 5. Para um número par, verificar e mostrar se ele é maior que 15.
[x] 6. Caso o resto da divisão por 2 não seja zero, mostrar que o número é ímpar.
[x] 7. Para um número ímpar, verificar e mostrar se ele é menor que 50.

*/
