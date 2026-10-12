#include <stdio.h>

int main(){
    int a, b, c;

    printf("Informe o primeiro numero: ");
    scanf("%d", &a);
    printf("Informe o segundo numero: ");
    scanf("%d", &b);
    printf("Informe o terceiro numero: ");
    scanf("%d", &c);

    if(a >= b && a >= c){
        printf("%d é MAIOR!\n", a);
    } else if(b >= a && b >= c){
        printf("%d é MAIOR!\n", b);
    } else{
        printf("%d é MAIOR!\n", c);
    }
    return 0;
}