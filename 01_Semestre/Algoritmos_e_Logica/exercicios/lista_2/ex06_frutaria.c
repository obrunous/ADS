#include <stdio.h>

int main(){
    float kgMorango;
    float kgMaca;
    float precoMorango;
    float precoMaca;
    float valorTotal;

    printf("Informe a quantidade de morangos em kg: ");
    scanf("%f", &kgMorango);

    printf("Informe a quantidade de maças em kg: ");
    scanf("%f", &kgMaca);

    if(kgMorango <= 5){
        precoMorango = 7.50;
    } else {
        precoMorango = 5.30;
    }

    if(kgMaca <= 5){
        precoMaca = 3.50;
    } else {
        precoMaca = 2.80;
    }

    valorTotal = (kgMorango * precoMorango) + (kgMaca * precoMaca);

    if((kgMorango + kgMaca) < 5 && valorTotal > 19.00) {
        valorTotal = valorTotal - (valorTotal * 0.08);
    }

    printf("Valor total: %.2f\n", valorTotal);

    return 0;
}

/*
ENUNCIADO

Elabore um programa que leia as quantidades de morangos e maçãs compradas, em quilos,
e calcule o valor total da compra.
Morangos: até 5 kg, R$ 7,50 por quilo; acima de 5 kg, R$ 5,30 por quilo.
Maçãs: até 5 kg, R$ 3,50 por quilo; acima de 5 kg, R$ 2,80 por quilo.
Conforme a regra implementada neste código, aplique 8% de desconto quando a quantidade
total for menor que 5 kg e o valor total for maior que R$ 19,00.
Mostre o valor final da compra.

MEU RACIOCÍNIO

[x] 1. Criar as variáveis para as quantidades de frutas, os preços por quilo e o valor total.
[x] 2. Pedir, ler e guardar a quantidade de morangos em quilos.
[x] 3. Pedir, ler e guardar a quantidade de maçãs em quilos.
[x] 4. Se a quantidade de morangos for até 5 kg, usar o preço de 7,50 por quilo; caso contrário, usar 5,30.
[x] 5. Se a quantidade de maçãs for até 5 kg, usar o preço de 3,50 por quilo; caso contrário, usar 2,80.
[x] 6. Calcular o valor total somando quantidade vezes preço de cada fruta.
[x] 7. Se a quantidade total for menor que 5 kg e o valor total for maior que 19,00, aplicar 8% de desconto.
[x] 8. Mostrar o valor total com duas casas decimais.

*/
