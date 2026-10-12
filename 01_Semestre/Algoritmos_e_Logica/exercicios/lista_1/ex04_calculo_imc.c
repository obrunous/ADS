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

/*
ENUNCIADO

4) Informe o Peso e a Altura. Calcule o IMC.
Se o IMC for maior que 30 mostre a mensagem
“Obeso”, caso contrário mostre a mensagem “Normal”
Imc = peso / (altura ^2)

MEU RACIOCÍNIO

[x] 1. Criar as variáveis para peso, altura e IMC.
[x] 2. Pedir, ler e guardar o peso.
[x] 3. Pedir, ler e guardar a altura.
[x] 4. Calcular o IMC: peso dividido pela altura vezes a altura.
[x] 5. Se o IMC for maior que 30, mostrar OBESO.
[x] 6. Caso contrário, mostrar NORMAL.
[x] 7. Mostrar o IMC com duas casas decimais.

*/
