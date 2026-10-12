#include <stdio.h>

int main(){
    int a, b, c;

    printf("Informe o primeiro numero: ");
    scanf("%d", &a);
    printf("Informe o segundo numero: ");
    scanf("%d", &b);
    printf("Informe o terceiro numero: ");
    scanf("%d", &c);

    if(a >= b && a >= c){
        printf("%d é MAIOR!\n", a);
    } else if(b >= a && b >= c){
        printf("%d é MAIOR!\n", b);
    } else{
        printf("%d é MAIOR!\n", c);
    }
    return 0;
}

/*
ENUNCIADO

Elabore um programa que leia três números inteiros e mostre o maior deles.

PROCEDIMENTO

[x] 1. Criar as variáveis para os três números inteiros.
[x] 2. Pedir, ler e guardar cada um dos três números.
[x] 3. Se o primeiro for maior ou igual aos outros dois, mostrar o primeiro como maior.
[x] 4. Se o segundo for maior ou igual aos outros dois, mostrar o segundo como maior.
[x] 5. Caso contrário, mostrar o terceiro como maior.

*/
