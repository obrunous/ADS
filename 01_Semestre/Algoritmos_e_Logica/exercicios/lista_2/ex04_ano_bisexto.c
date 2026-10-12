#include <stdio.h>

int main() {
    int dia, mes, ano, limiteDias;

    printf("Informe o dia do aniversário: ");
    scanf("%d", &dia);

    printf("Informe o mês do aniversário: ");
    scanf("%d", &mes);

    printf("Informe o ano do aniversário: ");
    scanf("%d", &ano);

    if (ano <= 1900 || ano >= 2023) {
        printf("Data inválida! O ano deve ser maior que 1900 e menor que 2023.\n");
    } else if (mes < 1 || mes > 12) {
        printf("Data inválida! O mês deve estar entre 1 e 12.\n");
    } else if (dia < 1) {
        printf("Data inválida! O dia deve ser maior ou igual a 1.\n");
    } else {
        if (mes == 2) {
            if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) {
                limiteDias = 29;
            } else {
                limiteDias = 28;
            }
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            limiteDias = 30;
        } else {
            limiteDias = 31;
        }

        if (dia > limiteDias) {
            printf("Data inválida! Este mês tem no máximo %d dias.\n", limiteDias);
        } else {
            printf("Data válida!\n");
        }
    }

    return 0;
}

/*
ENUNCIADO

Elabore um programa que leia o dia, o mês e o ano de um aniversário e verifique se a data é válida.
O ano deve ser maior que 1900 e menor que 2023, e o mês deve estar entre 1 e 12.
Verifique a quantidade de dias de cada mês, considerando os anos bissextos para fevereiro.

MEU RACIOCÍNIO

[x] 1. Criar as variáveis para dia, mês, ano e limite de dias.
[x] 2. Pedir, ler e guardar o dia, o mês e o ano do aniversário.
[x] 3. Se o ano for menor ou igual a 1900 ou maior ou igual a 2023, mostrar a mensagem de ano inválido.
[x] 4. Se o mês estiver fora do intervalo de 1 a 12, mostrar a mensagem de mês inválido.
[x] 5. Se o dia for menor que 1, mostrar a mensagem de dia inválido.
[x] 6. Para fevereiro, verificar se o ano é divisível por 400 ou se é divisível por 4 e não por 100.
[x] 7. Se o ano for bissexto, definir 29 dias para fevereiro; caso contrário, definir 28.
[x] 8. Para abril, junho, setembro e novembro, definir 30 dias.
[x] 9. Para os demais meses, definir 31 dias.
[x] 10. Se o dia ultrapassar o limite do mês, mostrar a mensagem de data inválida.
[x] 11. Caso contrário, mostrar Data válida.

*/
