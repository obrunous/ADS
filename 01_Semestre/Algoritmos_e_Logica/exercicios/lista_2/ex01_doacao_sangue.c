#include <stdio.h>

int main(){
    int idade;

    printf("Informe a sua idade: ");
    scanf("%d", &idade);

    if(idade >= 18 && idade <= 67){
        printf("Pode doar.\n");
    } else{
        printf("Nao pode doar.\n");
    }

    return 0;
}

/*
PROCEDIMENTO

[x] 1. Criar a variável para guardar a idade.
[x] 2. Pedir a idade.
[x] 3. Ler e guardar a idade.
[x] 4. Se a idade estiver entre 18 e 67, inclusive, mostrar Pode doar.
[x] 5. Caso contrário, mostrar Nao pode doar.

*/
