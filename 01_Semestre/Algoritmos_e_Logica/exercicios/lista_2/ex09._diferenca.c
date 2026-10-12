#include <stdio.h>

int main(){
    int a;
    int b;
    int diferenca;

    printf("Informe o primeiro número:\n");
    scanf("%d", &a);

    printf("Informe o segundo número:\n");
    scanf("%d", &b);

    if(a > b){
        diferenca = a - b;
        printf("Diferença: %d\n", diferenca);
    } else{
        diferenca = b - a;
        printf("Diferença: %d\n", diferenca);
    }

    return 0;
}

/*
ENUNCIADO

Elabore um programa que
leia dois números inteiros
e apresente o resultado da diferença do
maior número pelo menor deles.

PROCEDIMENTO

[x] 1. Criar as variáveis para os dois números inteiros e a diferença.
[x] 2. Pedir o primeiro número.
[x] 3. Ler e guardar o primeiro número.
[x] 4. Pedir o segundo número.
[x] 5. Ler e guardar o segundo número.
[x] 6. Se o primeiro número for maior que o segundo, calcular: primeiro menos segundo.
[x] 7. Caso contrário, calcular: segundo menos primeiro.
[x] 8. Mostrar o resultado da diferença.

*/
