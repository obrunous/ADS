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