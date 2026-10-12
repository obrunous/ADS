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

/*
ENUNCIADO

5) Receba uma letra. Se for ‘M’ mostrar masculino. Se for ‘F’ mostrar Feminino. Caso Contrário
coloque inválido

MEU RACIOCÍNIO

[x] 1. Criar uma variável para guardar a letra.
[x] 2. Pedir uma letra: M ou F.
[x] 3. Ler e guardar a letra.
[x] 4. Se a letra for M, mostrar Masculino.
[x] 5. Se a letra for F, mostrar Feminino.
[x] 6. Caso contrário, mostrar Inválido.

*/
