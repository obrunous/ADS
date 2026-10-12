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



/*
ENUNCIADO

6) Desenvolva uma calculadora
receba dois números e o sinal.
Mostre o resultado
Desafio. Se for divisão e o segundo numero for 0.
Colocar segundo número não pode ser 0

MEU RACIOCÍNIO

[x] 1. Criar as variáveis para os dois números, o sinal e os resultados.
[x] 2. Pedir, ler e guardar o primeiro número.
[x] 3. Pedir, ler e guardar o sinal da operação.
[x] 4. Pedir, ler e guardar o segundo número.
[x] 5. Se o sinal for +, somar os números e mostrar o resultado.
[x] 6. Se o sinal for -, subtrair o segundo número do primeiro e mostrar o resultado.
[x] 7. Se o sinal for *, multiplicar os números e mostrar o resultado.
[x] 8. Se o sinal for / e o segundo número for zero, mostrar a mensagem de divisão inválida.
[x] 9. Se o sinal for / e o segundo número não for zero, dividir o primeiro pelo segundo e mostrar o resultado.

*/
