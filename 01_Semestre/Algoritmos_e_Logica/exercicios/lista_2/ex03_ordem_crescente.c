#include <stdio.h>

int main(){
    int a, b, c, temp;

    printf("Informe o primeiro numero: ");
    scanf("%d", &a);

    printf("Informe o segundo numero: ");
    scanf("%d", &b);

    printf("Informe o terceiro numero: ");
    scanf("%d", &c);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }

    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    printf("Ordem crescente: %d %d %d\n", a, b, c);

    return 0;
}

/*
    Lógica do programa:
    - Compara a e b; se a for maior, troca os valores.
    - Compara a e c; se a for maior, troca os valores.
    - Compara b e c; se b for maior, troca os valores.
    - Ao final, os três números ficam em ordem crescente.
*/