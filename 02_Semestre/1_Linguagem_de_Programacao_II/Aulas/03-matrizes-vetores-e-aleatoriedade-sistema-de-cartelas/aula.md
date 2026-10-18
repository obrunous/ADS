# Aula 03 - Matrizes, Vetores e Aleatoriedade: Sistema de Cartelas

**Data:** 14/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3b6d0f04d53981c1a7f5ff7523c23730)

> **Objetivo da aula:** compreender a construção de um sistema de cartelas em C que gera 10.000 apostas com 6 números, evita números repetidos dentro de uma mesma cartela, contabiliza ocorrências, identifica o número mais frequente e compara números sorteados com todas as cartelas.
## 1. Visão geral do programa
O programa trabalha com uma simulação de cartelas numéricas. Cada cartela possui **6 números**, e o sistema mantém **10.000 cartelas**.
A estrutura principal é:
```c
int cartelas[10000][6];
```
Isso significa:
- 10.000 linhas → uma linha para cada cartela;
- 6 colunas → seis números por cartela;
- 60.000 posições disponíveis na matriz.
> **Analogia:** imagine uma mesa com 10.000 bilhetes. Cada bilhete possui exatamente 6 espaços. A matriz `cartelas[10000][6]` representa todos esses bilhetes dentro da memória do computador.
## 2. Bibliotecas utilizadas
O código fornecido começa com:
```c
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
```
No programa:
- `stdio.h` é utilizado para `printf` e `scanf`;
- `stdlib.h` fornece `rand` e `srand`;
- `time.h` fornece `time`, usado na inicialização da geração pseudoaleatória.
## 3. Variáveis principais
```c
int cartelas[10000][6];
int ocorrencias[61];
int numerossorteados[6];
int quantidadepontos[10000];
int cont,opcao;
int cont1,cont2;
int numero;
int numerosorteadojaexiste;
int indicemaior,maiornumero;
```
### Papel de cada estrutura
| Variável | Função no programa |
| --- | --- |
| `cartelas[10000][6]` | Armazena as 10.000 cartelas, cada uma com 6 números. |
| `ocorrencias[61]` | Conta quantas vezes cada número aparece nas cartelas. |
| `numerossorteados[6]` | Armazena os seis números informados como sorteados. |
| `quantidadepontos[10000]` | Guarda a quantidade de acertos de cada cartela. |
| `cont`, `cont1`, `cont2` | Contadores usados nos laços. |
| `numero` | Armazena temporariamente um número gerado. |
| `numerosorteadojaexiste` | Indica se o número gerado já existe na cartela atual. |
| `indicemaior` | Guarda qual número possui a maior quantidade de ocorrências. |
| `maiornumero` | Guarda a maior quantidade de ocorrências encontrada. |
## 4. Inicialização dos números aleatórios
Antes do menu, o programa executa:
```c
srand(time(NULL));
```
A chamada prepara a sequência utilizada por `rand()`.
Depois, na geração de cada número:
```c
numero = rand()%60+1;
```
O valor resultante fica no intervalo utilizado pelo programa:
```text
1 até 60
```
### Fluxo lógico
```text
rand()
   ↓
% 60
   ↓
valor entre 0 e 59
   ↓
+ 1
   ↓
valor entre 1 e 60
```
## 5. Menu principal — `do...while`
O programa mantém um menu dentro de um `do...while`:
```c
do
{
    printf("\n1-Gerar Cartelas");
    printf("\n2-Mostrar Cartelas");
    printf("\n3-Verifique os Numeros que mais aparecem");
    printf("\n4-Verifique os Numeros que menos aparecem");
    printf("\n5-Informe Numeros Sorteados");
    printf("\n Informe a opcao:");
    scanf("%d",&opcao);

    switch(opcao)
    {
        // opções
    }
}while(opcao!=5);
```
O menu é executado pelo menos uma vez. Ao final de cada operação, a condição é testada:
```c
opcao != 5
```
Enquanto a opção for diferente de 5, o programa retorna ao menu.
> **Analogia:** o `do...while` funciona como um atendente que volta a mostrar o menu após concluir um serviço. O atendimento continua até chegar à condição de encerramento definida no código.
## 6. `switch` — escolha da operação
A opção digitada pelo usuário é analisada por:
```c
switch(opcao)
```
A estrutura separa o programa em casos:
- `case 1` → gerar cartelas;
- `case 2` → mostrar cartelas;
- `case 3` → verificar ocorrências e encontrar o número que mais aparece;
- `case 4` → no código fornecido, não possui comandos próprios antes de `case 5`;
- `case 5` → informar números sorteados e calcular pontos;
- `default` → opção inválida.
## 7. Case 1 — gerar 10.000 cartelas
A geração começa com:
```c
for(cont=0;cont<10000;cont++)
{
    for(cont1=0;cont1<6;cont1++)
    {
        // geração de cada número
    }
}
```
### O que cada `for` representa
- `cont` percorre as cartelas de 0 até 9999;
- `cont1` percorre as 6 posições da cartela atual.
Assim, `cartelas[cont][cont1]` significa:
```text
cartela atual + posição atual dentro da cartela
```
### Analogia
Imagine um funcionário preenchendo 10.000 bilhetes.
1. Ele pega a cartela 0.
2. Preenche seus seis espaços.
3. Pega a cartela 1.
4. Preenche seus seis espaços.
5. Continua até a cartela 9999.
## 8. Gerando um número
Dentro do segundo `for`:
```c
numero = rand()%60+1;
numerosorteadojaexiste = 0;
```
Primeiro é gerado um número entre 1 e 60. Em seguida, a variável `numerosorteadojaexiste` começa com 0.
Neste código:
```text
0 → ainda não foi identificado como repetido
1 → número já existe na cartela
```
## 9. Verificando se o número já existe
A verificação só ocorre quando já existe pelo menos uma posição anterior na cartela:
```c
if(cont1>0)
```
Depois o programa percorre as posições já trabalhadas:
```c
for(cont2=0;cont2<=cont1;cont2++)
{
    if(numero == cartelas[cont][cont2])
    {
        numerosorteadojaexiste = 1;
        break;
    }
}
```
### Fluxo lógico
```text
Gerar número
   ↓
Já há número(s) na cartela?
   ↓ sim
Comparar com as posições da cartela
   ↓
Encontrou número igual?
   ├── sim → numerosorteadojaexiste = 1 → break
   └── não → continuar comparação
```
### Papel do `break`
```c
break;
```
Quando o número repetido é encontrado, não é necessário continuar procurando dentro desse laço. O `break` interrompe o `for` de comparação.
## 10. Guardar ou tentar novamente
Depois da verificação:
```c
if(numerosorteadojaexiste == 0)
{
    cartelas[cont][cont1]=numero;
}
else
{
    cont1--;
}
```
Existem dois caminhos.
### Caminho 1 — número não repetido
```c
cartelas[cont][cont1] = numero;
```
O número é gravado naquela posição da cartela.
### Caminho 2 — número repetido
```c
cont1--;
```
O contador é reduzido. Quando o `for` fizer seu incremento normal, a posição volta a ser trabalhada, permitindo uma nova tentativa.
> **Analogia:** o funcionário sorteia uma bolinha para preencher o próximo espaço do bilhete. Se aquele número já estiver no bilhete, ele descarta a bolinha e tenta novamente para o mesmo espaço.
## 11. Case 2 — mostrar todas as cartelas
O código percorre novamente a matriz:
```c
for(cont=0;cont<10000;cont++)
{
    printf("\n Seq:%6d ",cont);

    for(cont1=0;cont1<6;cont1++)
    {
        printf("%2d ",cartelas[cont][cont1]);
    }
}
```
O primeiro `for` seleciona cada cartela. O segundo percorre seus seis números.
O trecho:
```c
printf("\n Seq:%6d ",cont);
```
mostra a sequência/índice da cartela.
Depois:
```c
printf("%2d ",cartelas[cont][cont1]);
```
mostra cada número armazenado.
## 12. Case 3 — zerar o vetor de ocorrências
Antes de contar quantas vezes os números aparecem, o vetor é zerado:
```c
for(cont=0;cont<=60;cont++)
{
    ocorrencias[cont]=0;
}
```
Isso prepara as posições para a contagem.
O vetor possui 61 posições:
```c
int ocorrencias[61];
```
O programa utiliza os próprios números de 1 a 60 como índices.
Exemplo:
```text
ocorrencias[7]
```
representa quantas vezes o número 7 apareceu.
## 13. Contando todas as ocorrências
O programa percorre todas as 10.000 cartelas e seus seis números:
```c
for(cont=0;cont<10000;cont++)
{
    for(cont1=0;cont1<6;cont1++)
    {
        numero = cartelas[cont][cont1];
        ocorrencias[numero]++;
    }
}
```
A linha central é:
```c
ocorrencias[numero]++;
```
Se o número encontrado for 32, por exemplo, a operação será equivalente a:
```c
ocorrencias[32]++;
```
Ou seja: **some mais uma ocorrência ao contador do número 32**.
### Analogia
Imagine 60 caixas, uma para cada número. Toda vez que o funcionário encontra o número 32 em uma cartela, coloca uma ficha na caixa 32.
## 14. Encontrando o número que mais aparece
O programa começa assumindo o número 1 como referência:
```c
indicemaior = 1;
maiornumero = ocorrencias[1];
```
Depois percorre do número 2 ao 60:
```c
for(cont=2;cont<=60;cont++)
{
    printf("\n %2d - %4d",cont,ocorrencias[cont]);

    if (maiornumero < ocorrencias[cont])
    {
        maiornumero = ocorrencias[cont];
        indicemaior = cont;
    }
}
```
Sempre que encontra uma ocorrência maior que a armazenada em `maiornumero`, atualiza:
```c
maiornumero = ocorrencias[cont];
indicemaior = cont;
```
No final:
```c
printf("\nQuantidade de Ocorrencias:%d Numero:%d",maiornumero,indicemaior);
```
### Diferença importante
- `maiornumero` → quantidade de vezes que o campeão apareceu;
- `indicemaior` → qual foi o número campeão.
Exemplo conceitual:
```text
Número 27 apareceu 1050 vezes

indicemaior = 27
maiornumero = 1050
```
## 15. Case 4 — comportamento presente no código fornecido
No código enviado aparece:
```c
case 4:
case 5:
```
Não existe um bloco de comandos entre os dois casos.
Portanto, **conforme o código fornecido**, ao entrar no `case 4`, a execução segue para os mesmos comandos que aparecem após `case 5`.
> A opção 4 está escrita no menu como **“Verifique os Numeros que menos aparecem”**, mas o trecho fornecido não contém uma implementação específica para procurar o menor número de ocorrências. Aqui registramos exatamente o comportamento presente no material, sem completar uma lógica que não foi fornecida.
## 16. Case 5 — informar os seis números sorteados
Primeiro, o programa zera a pontuação das 10.000 cartelas:
```c
for(cont=0;cont<10000;cont++)
{
    quantidadepontos[cont]=0;
}
```
Depois solicita os seis números sorteados:
```c
for(cont=0;cont<6;cont++)
{
    printf("Informe o %d numero sorteado:",cont);
    scanf("%d",&numerossorteados[cont]);
}
```
Os valores ficam armazenados em:
```c
numerossorteados[6]
```
## 17. Comparar números sorteados com todas as cartelas
Essa etapa possui **três `for` aninhados**:
```c
for(cont=0;cont<10000;cont++)
{
    for(cont1=0;cont1<6;cont1++)
    {
        for(cont2=0;cont2<6;cont2++)
        {
            if(numerossorteados[cont2]==cartelas[cont][cont1])
            {
                quantidadepontos[cont]++;
            }
        }
    }
}
```
### Papel de cada contador
- `cont` → qual cartela está sendo verificada;
- `cont1` → qual número da cartela está sendo observado;
- `cont2` → qual número sorteado está sendo comparado.
### Fluxo de uma cartela
```text
Selecionar cartela
   ↓
Selecionar um dos 6 números da cartela
   ↓
Comparar com os 6 números sorteados
   ↓
Encontrou igualdade?
   ├── sim → quantidadepontos[cartela]++
   └── não → continuar
```
### Analogia
Pegue uma cartela e marque seu primeiro número. Compare esse número com as seis bolas sorteadas. Depois faça o mesmo com o segundo número da cartela, depois o terceiro, até terminar os seis. Só então passe para a próxima cartela.
## 18. Contabilizando os pontos
Quando ocorre igualdade:
```c
if(numerossorteados[cont2]==cartelas[cont][cont1])
{
    quantidadepontos[cont]++;
}
```
Se a cartela atual for a cartela 350, por exemplo, cada acerto incrementa:
```c
quantidadepontos[350]
```
Ao terminar a comparação, essa posição contém a pontuação daquela cartela.
## 19. Mostrar cartelas com pelo menos 4 pontos
O programa percorre a pontuação das 10.000 cartelas:
```c
for(cont=0;cont<10000;cont++)
{
    if(quantidadepontos[cont]>=4)
    {
        printf("\ncartela:%d pontos:%d",cont,quantidadepontos[cont]);
    }
}
```
A condição é:
```c
quantidadepontos[cont] >= 4
```
Portanto, são exibidas cartelas com:
```text
4 pontos
5 pontos
6 pontos
```
## 20. Default — opção inválida
Caso nenhuma das opções previstas seja escolhida:
```c
default:
    printf("Opcao Invalida");
    break;
```
Isso evita que uma opção fora do menu seja tratada como uma operação válida.
## 21. Fluxo completo do sistema
```text
INÍCIO
   ↓
Declarar matrizes, vetores e variáveis
   ↓
srand(time(NULL))
   ↓
Exibir menu
   ↓
Ler opção
   ↓
SWITCH
   ├── 1 → gerar 10.000 cartelas
   │        ↓
   │      gerar 6 números por cartela
   │        ↓
   │      verificar repetição
   │
   ├── 2 → mostrar as cartelas
   │
   ├── 3 → zerar ocorrências
   │        ↓
   │      contar números
   │        ↓
   │      encontrar maior ocorrência
   │
   ├── 4 → segue para o bloco compartilhado com case 5 no código fornecido
   │
   ├── 5 → zerar pontos
   │        ↓
   │      ler 6 números sorteados
   │        ↓
   │      comparar com 10.000 cartelas
   │        ↓
   │      mostrar cartelas com 4 ou mais pontos
   │
   └── default → opção inválida
   ↓
Testar opcao != 5
   ├── verdadeiro → voltar ao menu
   └── falso → encerrar
```
## 22. O que esta aula acrescenta em relação às matrizes básicas
Na Aula 1, a matriz era usada principalmente para criar e visualizar padrões. Aqui, a matriz passa a representar **dados de um sistema**.
A progressão é:
```text
MATRIZ
   ↓
10.000 cartelas × 6 números
   ↓
FOR aninhado
   ↓
geração aleatória
   ↓
verificação de repetição
   ↓
vetor de contagem
   ↓
comparação entre conjuntos de números
   ↓
pontuação por cartela
   ↓
menu com SWITCH + DO...WHILE
```
## 23. Estruturas de programação praticadas
| Estrutura | Uso nesta aula |
| --- | --- |
| Matriz | Armazenar 10.000 cartelas com 6 números. |
| Vetores | Ocorrências, números sorteados e pontuação. |
| `for` | Percorrer cartelas, posições, ocorrências e sorteios. |
| `if/else` | Detectar números repetidos e decidir se deve armazenar ou tentar novamente. |
| `switch` | Controlar as opções do menu. |
| `do...while` | Repetir o menu enquanto a condição definida for verdadeira. |
| `break` | Interromper a busca quando uma repetição é encontrada e finalizar casos do `switch`. |
| `rand()` | Gerar números utilizados nas cartelas. |
| Incremento `++` | Contar ocorrências e acertos. |
## 24. Frases-chave para a prova
> **Matriz de cartelas:** `cartelas[cont][cont1]` localiza uma cartela pela primeira dimensão e um dos seis números daquela cartela pela segunda dimensão.
> **Contagem por índice:** em `ocorrencias[numero]++`, o próprio valor do número funciona como índice do vetor que registra quantas vezes ele apareceu.
> **Três laços na conferência:** uma dimensão percorre as cartelas, outra percorre os seis números da cartela e a terceira percorre os seis números sorteados.
## 25. Checklist de domínio
- [ ] Sei explicar o que representa `cartelas[10000][6]`.
- [ ] Sei explicar por que `cont` percorre as cartelas e `cont1` percorre seus números.
- [ ] Sei explicar `rand()%60+1` dentro da lógica utilizada no programa.
- [ ] Sei explicar a função de `numerosorteadojaexiste`.
- [ ] Sei explicar por que o programa usa um terceiro contador, `cont2`, para procurar repetição.
- [ ] Sei explicar o efeito de `cont1--` quando um número repetido é encontrado.
- [ ] Sei explicar `ocorrencias[numero]++`.
- [ ] Sei diferenciar `maiornumero` de `indicemaior`.
- [ ] Sei explicar os três `for` usados na conferência dos números sorteados.
- [ ] Sei explicar como `quantidadepontos[cont]` representa a pontuação de uma cartela.
- [ ] Sei explicar por que somente cartelas com `>= 4` são mostradas.
- [ ] Sei explicar o papel do `switch` e do `do...while`.
- [ ] Sei reconhecer que, no código fornecido, `case 4` não contém uma lógica própria para o menor número de ocorrências.
## 26. Código-base da aula — conforme material fornecido
```c
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void main()
{
int cartelas[10000][6];
int ocorrencias[61];
int numerossorteados[6];
int quantidadepontos[10000];
int cont,opcao;
int cont1,cont2;
int numero;
int numerosorteadojaexiste;
int indicemaior,maiornumero;
srand(time(NULL));
do
{
printf("\n1-Gerar Cartelas");
printf("\n2-Mostrar Cartelas");
printf("\n3-Verifique os Numeros que mais aparecem");
printf("\n4-Verifique os Numeros que menos aparecem");
printf("\n5-Informe Numeros Sorteados");
printf("\n Informe a opcao:");
scanf("%d",&opcao);
switch(opcao)
{
case 1:
for(cont=0;cont<10000;cont++)
{
for(cont1=0;cont1<6;cont1++)
{
numero = rand()%60+1;
numerosorteadojaexiste = 0;
if(cont1>0)
{
for(cont2=0;cont2<=cont1;cont2++)
{
if(numero == cartelas[cont][cont2])
{
numerosorteadojaexiste = 1;
break;
}
}
}
if(numerosorteadojaexiste == 0)
{
cartelas[cont][cont1]=numero;
}
else
{
cont1--;
}
}
}
break;
case 2:
for(cont=0;cont<10000;cont++)
{
printf("\n Seq:%6d ",cont);
for(cont1=0;cont1<6;cont1++)
{
printf("%2d ",cartelas[cont][cont1]);
}
}
break;
case 3:
for(cont=0;cont<=60;cont++)
{
ocorrencias[cont]=0;
}
for(cont=0;cont<10000;cont++)
{
for(cont1=0;cont1<6;cont1++)
{
numero = cartelas[cont][cont1];
ocorrencias[numero]++;
}
}
indicemaior = 1;
maiornumero = ocorrencias[1];
for(cont=2;cont<=60;cont++)
{
printf("\n %2d - %4d",cont,ocorrencias[cont]);
if (maiornumero < ocorrencias[cont])
{
maiornumero = ocorrencias[cont];
indicemaior = cont;
}
}
printf("\nQuantidade de Ocorrencias:%d Numero:%d",maiornumero,indicemaior);
break;
case 4:
case 5:
for(cont=0;cont<10000;cont++)
{
quantidadepontos[cont]=0;
}
for(cont=0;cont<6;cont++)
{
printf("Informe o %d numero sorteado:",cont);
scanf("%d",&numerossorteados[cont]);
}
for(cont=0;cont<10000;cont++)
{
for(cont1=0;cont1<6;cont1++)
{
for(cont2=0;cont2<6;cont2++)
{
if(numerossorteados[cont2]==cartelas[cont][cont1])
{
quantidadepontos[cont]++;
}
}
}
}
for(cont=0;cont<10000;cont++)
{
if(quantidadepontos[cont]>=4)
{
printf("\ncartela:%d pontos:%d",cont,quantidadepontos[cont]);
}
}
break;
default:
printf("Opcao Invalida");
break;
}
}while(opcao!=5);
}
```
> **Síntese da Aula 3:** o programa combina matriz, vetores, geração de números, laços aninhados, busca, contagem, comparação, `if/else`, `switch` e `do...while` para transformar os conceitos de matrizes em um sistema maior e integrado.
