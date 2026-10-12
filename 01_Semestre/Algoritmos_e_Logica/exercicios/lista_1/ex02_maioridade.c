/* 2) Receba uma idade é mostre se é maior ou igual a 18 anos. Mostre a
mensagem se for maior que 18 anos e mostre a mensagem se for menor que 18 anos
*/

#include <stdio.h> 

int main(){
    int idade;

    printf("Informe uma idade: ");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("MAIOR DE IDADE\n");
    } else {
        printf("MENOR DE IDADE\n");
    }

    return 0;
}

/*
PROCEDIMENTO

[x] 1. Criar a variável para guardar a idade.
[x] 2. Pedir a idade.
[x] 3. Ler e guardar a idade.
[x] 4. Se a idade for maior ou igual a 18, mostrar MAIOR DE IDADE.
[x] 5. Caso contrário, mostrar MENOR DE IDADE.

*/
