#include <stdio.h>

int main(){
    int idade;

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    if(idade >= 18 && idade <= 67){
        printf("Pode doar.\n");
    } else{
        printf("Nao pode doar.\n");
    }

    return 0;
}

/*
ENUNCIADO

Elabore um programa que leia a idade de uma pessoa e informe se ela pode doar sangue.
Considere, neste exercício, que a idade permitida vai de 18 a 67 anos, inclusive.

MEU RACIOCÍNIO

[x] 1. Criar a variável para guardar a idade.
[x] 2. Pedir a idade.
[x] 3. Ler e guardar a idade.
[x] 4. Se a idade estiver entre 18 e 67, inclusive, mostrar Pode doar.
[x] 5. Caso contrário, mostrar Nao pode doar.

*/
