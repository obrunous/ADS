/* 3) Receba 4 números e calcule a média. Se a média for maior
que 6 informe “Aluno Aprovado” se for menor informe “Aluno Reprovado” */

#include <stdio.h>

int main(){
    float n1, n2, n3, n4;
    float media; 

    printf("Informe o primeiro numero: ");
    scanf("%f", &n1);

    printf("Informe o segundo numero: ");
    scanf("%f", &n2);

    printf("Informe o terceiro numero: ");
    scanf("%f", &n3);

    printf("Informe o quarto numero: ");
    scanf("%f", &n4);

    media = (n1 + n2 + n3 + n4) / 4;

    if(media >= 6){
        printf("APROVADO!\n");
    } else {
        printf("REPROVADO!\n");
    }

    printf("Media: %.2f\n", media);

    return 0;
}