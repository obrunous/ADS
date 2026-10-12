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
