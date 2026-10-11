#include <stdio.h>

int main(){
    float num1;
    float num2;
    char sinal;
    float somar, subtrair, multiplicar, dividir;

    printf("Informe o primeiro numero: ");
    scanf("%f", &num1);

    printf("Informe o sinal: ");
    scanf(" %c", &sinal);

    printf("Informe o segundo numero: ");
    scanf("%f", &num2);

    if (sinal == '+'){
        somar = num1 + num2;
        printf("RESULTADO: %.2f\n", somar);
    } else if (sinal == '-'){
        subtrair = num1 - num2;
        printf("RESULTADO: %.2f\n", subtrair);
    } else if (sinal == '*'){
        multiplicar = num1 * num2;
        printf("RESULTADO: %.2f\n", multiplicar);
    } else if (sinal == '/'){
        if(num2 == 0){
            printf("INVALIDO! Nao pode divdir por zero!");
        } else{
            dividir = num1 / num2;
            printf("RESULTADO: %.2f\n", dividir);
        
    }

}
    return 0;
}

/* 6) Desenvolva uma calculadora
receba dois números e o sinal. 
Mostre o resultado
Desafio. Se for divisão e o segundo numero for 0. 
Colocar segundo número não pode ser 0*/