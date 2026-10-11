/* 4) Informe o Peso e a Altura. Calcule o IMC. 
Se o IMC for maior que 30 mostre a mensagem
“Obeso”, caso contrário mostre a mensagem “Normal”
Imc = peso / (altura ^2) */

#include <stdio.h>

int main(){
    float peso;
    float altura;
    float imc;

    printf("Informe o peso: ");
    scanf("%f", &peso);

    printf("Informe a altura: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    if(imc > 30){
        printf("OBESO\n");
    } else {
        printf("NORMAL\n");
    }

    printf("IMC: %.2f\n", imc);

    return 0;
}