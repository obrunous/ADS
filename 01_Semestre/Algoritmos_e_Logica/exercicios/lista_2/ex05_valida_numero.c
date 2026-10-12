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

/*
ENUNCIADO (descrição baseada no código atual)

Elabore um programa que leia um número inteiro e informe se ele é válido.
Considere válido um número entre 50 e 70, inclusive, ou maior que 100.

PROCEDIMENTO

[x] 1. Criar a variável para guardar o número inteiro.
[x] 2. Pedir um número.
[x] 3. Ler e guardar o número.
[x] 4. Se o número estiver entre 50 e 70, inclusive, ou for maior que 100, mostrar Válido.
[x] 5. Caso contrário, mostrar que o número não é válido.

*/
