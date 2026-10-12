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

/*
ENUNCIADO

Elabore um programa que leia três números inteiros e apresente os valores em ordem crescente.

MEU RACIOCÍNIO

[x] 1. Criar as variáveis para os três números e uma variável temporária.
[x] 2. Pedir, ler e guardar cada um dos três números.
[x] 3. Se o primeiro número for maior que o segundo, trocar os dois usando a variável temporária.
[x] 4. Se o primeiro número for maior que o terceiro, trocar os dois usando a variável temporária.
[x] 5. Se o segundo número for maior que o terceiro, trocar os dois usando a variável temporária.
[x] 6. Mostrar os três números em ordem crescente.

*/
