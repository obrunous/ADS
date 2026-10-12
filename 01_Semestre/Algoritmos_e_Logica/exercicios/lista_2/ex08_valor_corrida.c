/*

[x] 1. Criar as variáveis para distância, bandeira e valor da corrida.
[x] 2. Pedir a distância percorrida em quilômetros.
[x] 3. Ler e guardar a distância.
[x] 4. Pedir o tipo da bandeira: 1 ou 2.
[x] 5. Ler e guardar a bandeira.
[x] 6. Se a bandeira for 1, calcular: distância vezes 1,80.
[x] 7. Se a bandeira for 2, calcular: distância vezes 2,30.
[x] 8. Mostrar o valor da corrida.

*/

#include <stdio.h>

int main(){
    float distancia, valorCorrida;
    int bandeira;

    printf("Informe a distancia percorrida em km:\n");
    scanf("%f", &distancia);

    printf("Informe a bandeira(1 ou 2):\n");
    scanf("%d", &bandeira);

    if(bandeira == 1){
        valorCorrida = distancia * 1.80;
        printf("Valor da corrida: %.2f\n", valorCorrida);
    } else if(bandeira == 2){
        valorCorrida = distancia * 2.30;
        printf("Valor da Corrida: %.2f\n", valorCorrida);
    }

    return 0;
}
