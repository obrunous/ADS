#include <stdio.h>

int main(){
    // 1.  DECLARA AS VARIAVEIS
    float valorCompra;
    int opcao;

    // 2. PEDE O VALOR DA COMPRA
    printf("Informe o valor da compra: ");
    scanf("%f", &valorCompra);

    // 3. PEDE A FORMA DE PAGAMENTO
    printf("=== INFORME A FORMA DE PAGAMENTO ===\n");
    printf("1 - Pix à Vista\n");
    printf("2 - Credito à Vista\n");
    printf("3 - Credito Parcelado\n");
    scanf("%d", &opcao);

    // 4. CALCULA E MOSTRA O VALOR FINAL DA COMPRA CONFORME A FORMA DE PAGAMENTO
    // Aplica 10% de desconto no pagamento à vista.
    if(opcao == 1){
        valorCompra = valorCompra - (valorCompra / 10);
        printf("VALOR FINAL: %.2f\n", valorCompra);
    // Aplica 2% de acréscimo no cartão de crédito.
    } else if(opcao == 2){
        valorCompra = valorCompra + (valorCompra * 0.02);
        printf("VALOR FINAL: %.2f\n", valorCompra);
    // Aplica 10% de acréscimo no pagamento parcelado.
    } else if(opcao == 3){
        valorCompra = valorCompra + (valorCompra * 0.10);
        printf("VALOR FINAL: %.2f\n", valorCompra);
    } else{
            printf("INVÁLIDO!");
    }

    return 0;
}

/* 7) Ao pagar uma compra o atendente pergunta.
1- A vista tem 10% de desconto
2- No cartão de crédito tem 2% de acrescimo
3-No cartão parcelado em 3x tem 10% de acrescimo
Mostre o valor a ser pago.*/

// Aplica 10% de desconto no pagamento à vista.
// Aplica 2% de acréscimo no cartão de crédito.
// Aplica 10% de acréscimo no pagamento parcelado.