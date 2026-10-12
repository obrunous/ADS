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