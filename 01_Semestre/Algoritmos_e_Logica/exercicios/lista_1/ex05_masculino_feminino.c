/* 5) Receba uma letra. Se for ‘M’ mostrar masculino. Se for ‘F’ mostrar Feminino. Caso Contrário
coloque inválido */

#include <stdio.h> 

int main(){
    char letra;

    printf("Informe uma letra('M' para masculino ou 'F' para feminino): ");
    scanf(" %c", &letra);

    if(letra == 'M'){
        printf("Masculino\n");
    } else if (letra == 'F'){
        printf("Feminino\n");
    } else{
        printf("Inválido\n");
    }

    return 0;
}