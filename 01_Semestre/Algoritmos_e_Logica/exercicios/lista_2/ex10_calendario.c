#include <stdio.h>

int main(){
    int mes;

    printf("Informe o mês: ");
    scanf("%d", &mes);

    if(mes == 1){
        printf("Janeiro\n");
    } else if(mes == 2){
        printf("Fevereiro\n");
    } else if(mes == 3){
        printf("Março\n");
    } else if(mes == 4){
        printf("Abril\n");
    } else if(mes == 5){
        printf("Maio\n");
    } else if(mes == 6){
        printf("Junho\n");
    } else if(mes == 7){
        printf("Julho\n");
    } else if(mes == 8){
        printf("Agosto\n");
    } else if(mes == 9){
        printf("Setembro\n");
    } else if(mes == 10){
        printf("Outubro\n");
    } else if(mes == 11){
        printf("Novembro\n");
    } else if(mes == 12){
        printf("Dezembro\n");
    } else{
        printf("Número inválido!");
    }

    return 0;
}


/*

Elabore um programa que
leia um número inteiro
de 1 a 12 e apresente o
nome do mês correspondente
por extenso. Caso o usuário
digite um número fora desse
intervalo, o programa deverá exibir
uma mensagem de número inválido.

[x] 1. Criar uma variável inteira para guardar o número do mês.
[x] 2. Pedir um número de 1 a 12.
[x] 3. Ler e guardar o número.
[x] 4. Se for 1, mostrar Janeiro.
[x] 5. Se for 2, mostrar Fevereiro.
[x] 6. Se for 3, mostrar Março.
[x] 7. Se for 4, mostrar Abril.
[x] 8. Se for 5, mostrar Maio.
[x] 9. Se for 6, mostrar Junho.
[x] 10. Se for 7, mostrar Julho.
[x] 11. Se for 8, mostrar Agosto.
[x] 12. Se for 9, mostrar Setembro.
[x] 13. Se for 10, mostrar Outubro.
[x] 14. Se for 11, mostrar Novembro.
[x] 15. Se for 12, mostrar Dezembro.
[x] 16. Caso não corresponda a nenhum mês, mostrar Número inválido.
*/