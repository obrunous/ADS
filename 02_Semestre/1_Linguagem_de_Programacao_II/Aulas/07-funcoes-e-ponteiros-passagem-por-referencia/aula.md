# Aula 07 - Funções e Ponteiros: Passagem por Referência

**Data:** 14/09/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3dbd0f04d53981789262f731c7e7462e)

## 🎯 Tema da aula
**Funções — Passagem por Referência em C**
> Nesta aula, o objetivo é entender como uma função pode alterar diretamente variáveis criadas no `main` usando **endereços de memória**, **ponteiros**, `&` e `*`.
## 1. Conceito central
Em C, uma variável ocupa um espaço na memória. Esse espaço possui um **endereço**.
Exemplo:
```c
int x = 5;
```
Podemos imaginar que a variável `x` está guardada em algum endereço da memória.
```text
MEMÓRIA

Endereço        Variável        Valor
0x1000          x               5
```
- `x` → acessa o valor `5`.
- `&x` → acessa o endereço onde `x` está armazenado.
- `int *p` → declara um ponteiro capaz de guardar o endereço de uma variável `int`.
- `*p` → acessa o conteúdo existente no endereço guardado pelo ponteiro.
> Tecnicamente, C passa argumentos por valor. O que chamamos na aula de **passagem por referência** é feito passando o **valor do endereço de memória** para um ponteiro. Na prática, isso permite que a função altere a variável original.
---
## 2. 📦 Analogia do estoque
Imagine um estoque em que cada produto fica armazenado em um endereço físico.
### Exemplo de endereço
```text
03-04-08
```
Significa:
```text
03 → Rua 03
04 → Nível 04
08 → Posição 08
```
Esse endereço identifica exatamente onde o produto está armazenado.
### Relação com programação
```text
PROGRAMAÇÃO                     ESTOQUE

variável                        posição de armazenagem
valor da variável               produto armazenado
&variável                       endereço da posição
ponteiro                        romaneio de separação
*ponteiro                       ir até o endereço e acessar o produto
```
### Romaneio de separação
O **romaneio de separação** não é o produto. Ele contém a informação necessária para chegar até o produto.
Imagine que no romaneio aparece:
```text
Produto: Caixa A
Endereço: 03-04-08
```
O separador lê o endereço, vai até:
**Rua 03 → Nível 04 → Posição 08**
e acessa o produto armazenado naquela posição.
Na programação, o ponteiro funciona de maneira semelhante:
```c
int *ponteiro;
```
O ponteiro não é o valor da variável. Ele guarda o **endereço onde o valor está armazenado**.
### Passagem por valor x passagem por referência
> **Passagem por valor:** é como entregar ao funcionário apenas uma cópia das informações do produto. Ele pode riscar ou alterar o papel, mas o produto original continua igual na posição do estoque.
> **Passagem por referência:** é como entregar no romaneio o endereço real `03-04-08`. O funcionário vai fisicamente até essa posição e consegue mexer no produto original.
---
## 3. Operadores essenciais
### `&` — operador de endereço
```c
&x
```
Significa:
**“Qual é o endereço de memória da variável `x`?”**
Analogia:
```text
x  = produto
&x = endereço 03-04-08
```
### `*` — ponteiro na declaração
```c
int *x;
```
Aqui o `*` informa que `x` é um **ponteiro para inteiro**.
Ou seja: `x` poderá guardar o endereço de uma variável do tipo `int`.
### `*` — desreferência
```c
*x
```
Quando usado dessa forma, significa:
**“Vá ao endereço guardado em `x` e acesse o valor que está lá.”**
Analogia:
```text
romaneio possui endereço 03-04-08
          ↓
separador vai até 03-04-08
          ↓
acessa o produto
```
---
## 4. Fluxo geral da passagem por referência
```text
main cria uma variável
        ↓
variável ocupa um endereço na memória
        ↓
&variável obtém esse endereço
        ↓
função recebe o endereço em um ponteiro
        ↓
*ponteiro acessa o valor original
        ↓
função modifica o valor
        ↓
variável do main aparece modificada
```
---
## 5. 💻 Exercício 1 — `mudaValores`
O trecho visível na aula foi:
```c
int x, y;

x = 5;
y = 7;

mudaValores(&x, &y);

printf("x:%d e y:%d", x, y);
```
> A implementação completa da função `mudaValores` não apareceu no registro da aula. Por isso, esta página explica detalhadamente apenas o trecho que foi realmente apresentado, sem inventar os valores que a função atribuiria.
### Linha por linha
#### Linha 1
```c
int x, y;
```
Cria duas variáveis inteiras chamadas `x` e `y`.
Mentalmente:
```text
MEMÓRIA

x → posição reservada para um inteiro
y → posição reservada para um inteiro
```
Analogia do estoque: duas posições foram reservadas para receber produtos.
---
#### Linha 2
```c
x = 5;
```
Coloca o valor `5` dentro da variável `x`.
```text
x → 5
```
Analogia: o produto de valor `5` foi colocado na posição correspondente a `x`.
---
#### Linha 3
```c
y = 7;
```
Coloca o valor `7` dentro da variável `y`.
```text
x → 5
y → 7
```
---
#### Linha 4
```c
mudaValores(&x, &y);
```
Essa é a linha principal do exercício.
A função não recebe apenas `5` e `7`.
Ela recebe:
```text
&x → endereço de x
&y → endereço de y
```
Analogia:
```text
ROMANEIO

Item x → endereço 03-04-08
Item y → endereço 03-04-09
```
A função recebe os endereços e pode ir diretamente até as posições originais.
Por isso, se dentro de `mudaValores` houver algo como:
```c
*x = algumValor;
```
ela estará alterando a variável `x` criada no `main`.
---
#### Linha 5
```c
printf("x:%d e y:%d", x, y);
```
Mostra na tela os valores finais de `x` e `y` após a execução da função.
A ideia do exercício é justamente observar que a função consegue alterar as variáveis originais.
---
## 6. 💻 Exercício 2 — Rotacionar quatro valores
### Enunciado
Desenvolver uma função por referência que receba quatro endereços de memória e rotacione seus valores.
### Antes da função
```text
A = 5
B = 6
C = 7
D = 8
```
### Depois da função
```text
A = 8
B = 5
C = 6
D = 7
```
### Movimento dos valores
```text
A → B
B → C
C → D
D → A
```
Ou visualmente:
```text
5 → posição B
6 → posição C
7 → posição D
8 → posição A
```
### Lógica antes do código
```text
auxiliar recebe A
A recebe D
D recebe C
C recebe B
B recebe auxiliar
```
Precisamos da variável `auxiliar` para não perder o valor original de `A`.
---
### Código completo
```c
#include <stdio.h>

void rotacionarValores(int *a, int *b, int *c, int *d) {
    int auxiliar;

    auxiliar = *a;

    *a = *d;
    *d = *c;
    *c = *b;
    *b = auxiliar;
}

int main(void) {
    int a = 5;
    int b = 6;
    int c = 7;
    int d = 8;

    printf("Antes:\n");
    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("C = %d\n", c);
    printf("D = %d\n", d);

    rotacionarValores(&a, &b, &c, &d);

    printf("\nDepois:\n");
    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("C = %d\n", c);
    printf("D = %d\n", d);

    return 0;
}
```
---
## 7. Exercício 2 — Explicação linha por linha
### `#include <stdio.h>`
```c
#include <stdio.h>
```
Inclui a biblioteca padrão de entrada e saída.
Ela é necessária porque o programa utiliza `printf`.
---
### Cabeçalho da função
```c
void rotacionarValores(int *a, int *b, int *c, int *d) {
```
Vamos dividir essa linha:
```text
void
```
A função não retorna um valor usando `return`.
Ela altera diretamente as variáveis recebidas pelos endereços.
```text
rotacionarValores
```
É o nome da função.
```c
int *a
```
`a` é um ponteiro para `int`.
Ele receberá o endereço da variável `a` existente no `main`.
A mesma lógica vale para:
```c
int *b
int *c
int *d
```
Analogia:
```text
ponteiro a → romaneio com endereço da posição A
ponteiro b → romaneio com endereço da posição B
ponteiro c → romaneio com endereço da posição C
ponteiro d → romaneio com endereço da posição D
```
---
### Variável auxiliar
```c
int auxiliar;
```
Cria uma variável temporária.
Ela serve para guardar um valor enquanto os outros são movidos.
Sem ela, perderíamos o valor original de `A`.
Analogia: é como usar uma área temporária do estoque para deixar uma caixa enquanto reorganizamos as outras posições.
---
### Guardando o valor de A
```c
auxiliar = *a;
```
`a` contém um endereço.
`*a` significa: acessar o valor existente nesse endereço.
Inicialmente:
```text
*a = 5
```
Então:
```text
auxiliar = 5
```
Estado neste momento:
```text
A = 5
B = 6
C = 7
D = 8
auxiliar = 5
```
---
### D vai para A
```c
*a = *d;
```
`*d` acessa o valor de `D`, que é `8`.
Esse valor é colocado na posição apontada por `a`.
Resultado:
```text
A = 8
B = 6
C = 7
D = 8
auxiliar = 5
```
O valor original `5` de A não foi perdido porque está salvo em `auxiliar`.
---
### C vai para D
```c
*d = *c;
```
`*c` vale `7`.
Então D recebe `7`.
```text
A = 8
B = 6
C = 7
D = 7
auxiliar = 5
```
---
### B vai para C
```c
*c = *b;
```
`*b` vale `6`.
Então C recebe `6`.
```text
A = 8
B = 6
C = 6
D = 7
auxiliar = 5
```
---
### Valor original de A vai para B
```c
*b = auxiliar;
```
`auxiliar` guarda o valor `5`.
Então B recebe `5`.
Resultado final:
```text
A = 8
B = 5
C = 6
D = 7
```
---
### Início do programa
```c
int main(void) {
```
É o ponto de entrada do programa.
---
### Criação das quatro variáveis
```c
int a = 5;
int b = 6;
int c = 7;
int d = 8;
```
Cria quatro variáveis inteiras e atribui seus valores iniciais.
Mentalmente:
```text
A → endereço 03-04-08 → valor 5
B → endereço 03-04-09 → valor 6
C → endereço 03-04-10 → valor 7
D → endereço 03-04-11 → valor 8
```
Os endereços acima são apenas uma analogia de estoque para facilitar a visualização.
---
### Impressão do estado inicial
```c
printf("Antes:\n");
```
Mostra o texto `Antes:`.
`<br>` significa quebra de linha.
Depois:
```c
printf("A = %d\n", a);
printf("B = %d\n", b);
printf("C = %d\n", c);
printf("D = %d\n", d);
```
Cada `%d` é substituído pelo valor inteiro da respectiva variável.
Saída:
```text
Antes:
A = 5
B = 6
C = 7
D = 8
```
---
### Chamada da função
```c
rotacionarValores(&a, &b, &c, &d);
```
Essa é a parte mais importante do programa.
Não estamos enviando:
```text
5, 6, 7, 8
```
Estamos enviando:
```text
&a → endereço de a
&b → endereço de b
&c → endereço de c
&d → endereço de d
```
Analogia:
```text
ROMANEIO DE SEPARAÇÃO

A → 03-04-08
B → 03-04-09
C → 03-04-10
D → 03-04-11
```
A função recebe esses endereços e altera diretamente o conteúdo das posições.
---
### Impressão final
```c
printf("\nDepois:\n");
```
Mostra o título da segunda parte.
Depois:
```c
printf("A = %d\n", a);
printf("B = %d\n", b);
printf("C = %d\n", c);
printf("D = %d\n", d);
```
Agora os valores já foram modificados pela função.
Saída:
```text
Depois:
A = 8
B = 5
C = 6
D = 7
```
---
### Finalização
```c
return 0;
```
Indica que o programa terminou corretamente.
---
## 8. 💻 Exercício 3 — Converter segundos
### Enunciado
Receber um tempo em segundos e criar uma função que produza três resultados:
- horas;
- minutos;
- segundos restantes.
Exemplo apresentado:
```text
30005 segundos
```
Resultado:
```text
8 horas
20 minutos
5 segundos
```
---
### Código completo
```c
#include <stdio.h>

void converterTempo(int totalSegundos, int *horas, int *minutos, int *segundos) {
    *horas = totalSegundos / 3600;

    totalSegundos = totalSegundos % 3600;

    *minutos = totalSegundos / 60;

    *segundos = totalSegundos % 60;
}

int main(void) {
    int totalSegundos;
    int horas;
    int minutos;
    int segundos;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &totalSegundos);

    converterTempo(totalSegundos, &horas, &minutos, &segundos);

    printf("\n%d horas\n", horas);
    printf("%d minutos\n", minutos);
    printf("%d segundos\n", segundos);

    return 0;
}
```
---
## 9. Exercício 3 — Explicação linha por linha
### Biblioteca
```c
#include <stdio.h>
```
Permite utilizar `printf` e `scanf`.
---
### Cabeçalho da função
```c
void converterTempo(int totalSegundos, int *horas, int *minutos, int *segundos) {
```
Essa função recebe quatro parâmetros.
#### `int totalSegundos`
```c
int totalSegundos
```
Recebe uma cópia do valor digitado pelo usuário.
Esse parâmetro é passado **por valor**.
Se o usuário digitar `30005`:
```text
totalSegundos = 30005
```
#### `int *horas`
```c
int *horas
```
Recebe o endereço da variável `horas` do `main`.
#### `int *minutos`
Recebe o endereço da variável `minutos`.
#### `int *segundos`
Recebe o endereço da variável `segundos`.
Esses três ponteiros permitem que a função produza três resultados diferentes.
---
### Calculando horas
```c
*horas = totalSegundos / 3600;
```
Uma hora possui:
```text
60 minutos × 60 segundos = 3600 segundos
```
Com `30005`:
```text
30005 / 3600 = 8
```
Como estamos trabalhando com inteiros, a parte decimal é descartada.
Então:
```text
*horas = 8
```
Como `horas` é um ponteiro, esse `8` é escrito diretamente na variável `horas` criada no `main`.
---
### Descobrindo o restante
```c
totalSegundos = totalSegundos % 3600;
```
O operador `%` calcula o resto da divisão inteira.
```text
30005 % 3600 = 1205
```
Depois de retirar 8 horas completas, restam:
```text
1205 segundos
```
Agora:
```text
totalSegundos = 1205
```
---
### Calculando minutos
```c
*minutos = totalSegundos / 60;
```
Com 1205 segundos:
```text
1205 / 60 = 20
```
Então:
```text
*minutos = 20
```
---
### Calculando os segundos restantes
```c
*segundos = totalSegundos % 60;
```
Calculamos o resto:
```text
1205 % 60 = 5
```
Então:
```text
*segundos = 5
```
Resultado produzido pela função:
```text
horas = 8
minutos = 20
segundos = 5
```
---
### `main`
```c
int main(void) {
```
Início do programa.
---
### Variável de entrada
```c
int totalSegundos;
```
Variável que armazenará o número digitado pelo usuário.
---
### Variáveis de saída
```c
int horas;
int minutos;
int segundos;
```
Essas três variáveis receberão os resultados calculados pela função.
Inicialmente, ainda não possuem os valores finais.
---
### Mensagem para o usuário
```c
printf("Digite o tempo em segundos: ");
```
Exibe uma mensagem solicitando a entrada.
---
### Leitura do valor
```c
scanf("%d", &totalSegundos);
```
`scanf` precisa saber **onde** deve armazenar o número digitado.
Por isso usamos:
```c
&totalSegundos
```
Ou seja: o endereço da variável.
Analogia:
```text
"Coloque o produto recebido exatamente no endereço 03-04-08."
```
---
### Chamada da função
```c
converterTempo(totalSegundos, &horas, &minutos, &segundos);
```
Observe a diferença:
```text
totalSegundos → valor
&horas        → endereço
&minutos      → endereço
&segundos     → endereço
```
Portanto:
- `totalSegundos` entra na função por valor;
- `horas`, `minutos` e `segundos` são modificados por seus endereços.
Analogia do romaneio:
```text
Entrada do pedido:
30005 segundos

Romaneio informa onde registrar os resultados:
Horas    → posição H
Minutos  → posição M
Segundos → posição S
```
A função calcula e grava diretamente nessas posições.
---
### Impressão das horas
```c
printf("\n%d horas\n", horas);
```
Mostra o valor calculado para `horas`.
Para o exemplo:
```text
8 horas
```
---
### Impressão dos minutos
```c
printf("%d minutos\n", minutos);
```
Resultado:
```text
20 minutos
```
---
### Impressão dos segundos
```c
printf("%d segundos\n", segundos);
```
Resultado:
```text
5 segundos
```
---
### Encerramento
```c
return 0;
```
Finaliza o programa indicando execução bem-sucedida.
---
## 10. Execução completa do exercício 3
Para entrada:
```text
30005
```
O programa pensa assim:
```text
30005 / 3600 = 8 horas
30005 % 3600 = 1205 segundos restantes
1205 / 60 = 20 minutos
1205 % 60 = 5 segundos
```
Resultado final:
```text
8 horas
20 minutos
5 segundos
```
---
## 11. O que memorizar para a prova
- `&variavel` significa **endereço da variável**.
- `int *p` declara um **ponteiro para inteiro**.
- `*p` acessa ou altera o **valor armazenado no endereço apontado**.
- A função recebe endereços quando queremos alterar variáveis do `main`.
- Na chamada usamos `&`.
- Dentro da função usamos `*` para acessar o conteúdo.
- Uma variável auxiliar evita perder valores durante trocas ou rotações.
- `%` fornece o resto de uma divisão inteira.
- `/` entre inteiros realiza divisão inteira.
> **Imagem mental da aula:** `&` coloca o endereço no romaneio. O ponteiro recebe esse endereço. `*` faz o separador ir até a posição indicada e acessar o produto que está ali.
## 12. Resumo em uma linha
```text
variável → valor | &variável → endereço | ponteiro → guarda endereço | *ponteiro → acessa/altera o valor original
```
## 13. 💻 Exercício 4 — Ordenar três valores por referência
### Enunciado registrado no quadro
**Dê 3 números para a função `ordenaValores`, e a função irá ordenar em ordem crescente os valores. Use função com passagem por referência.**
### Objetivo
Receber três variáveis inteiras e reorganizar seus valores para que, ao final:
```text
a <= b <= c
```
### Exemplo
Antes:
```text
A = 8
B = 3
C = 5
```
Depois:
```text
A = 3
B = 5
C = 8
```
### Lógica antes do código
Precisamos comparar os valores dois a dois. Sempre que estiverem fora de ordem, fazemos uma troca usando uma variável auxiliar.
```text
se A > B → troca A com B
se A > C → troca A com C
se B > C → troca B com C
```
Depois dessas três comparações, os valores ficam em ordem crescente.
### Código completo
```c
#include <stdio.h>

void ordenaValores(int *a, int *b, int *c) {
    int auxiliar;

    if (*a > *b) {
        auxiliar = *a;
        *a = *b;
        *b = auxiliar;
    }

    if (*a > *c) {
        auxiliar = *a;
        *a = *c;
        *c = auxiliar;
    }

    if (*b > *c) {
        auxiliar = *b;
        *b = *c;
        *c = auxiliar;
    }
}

int main(void) {
    int a;
    int b;
    int c;

    printf("Digite tres numeros: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Antes: %d %d %d\n", a, b, c);

    ordenaValores(&a, &b, &c);

    printf("Depois: %d %d %d\n", a, b, c);

    return 0;
}
```
### Explicação linha por linha
#### Cabeçalho da função
```c
void ordenaValores(int *a, int *b, int *c)
```
A função não retorna um valor com `return`. Ela recebe três ponteiros para `int`. Cada ponteiro guarda o endereço de uma variável criada no `main`.
Na chamada:
```c
ordenaValores(&a, &b, &c);
```
`&a`, `&b` e `&c` fornecem os endereços das três variáveis.
#### Variável auxiliar
```c
int auxiliar;
```
É uma posição temporária usada durante uma troca. Sem ela, um dos valores poderia ser perdido ao sobrescrever uma variável.
#### Primeira comparação
```c
if (*a > *b)
```
`*a` acessa o valor armazenado no endereço de `a`; `*b` acessa o valor de `b`. Se A for maior que B, eles estão fora da ordem crescente e precisam ser trocados.
```c
auxiliar = *a;
*a = *b;
*b = auxiliar;
```
Fluxo da troca:
```text
auxiliar ← A
A ← B
B ← auxiliar
```
#### Segunda comparação
```c
if (*a > *c)
```
Compara A com C. Se A ainda for maior, os dois valores são trocados. Isso ajuda a garantir que o menor valor fique em A.
#### Terceira comparação
```c
if (*b > *c)
```
Compara os dois valores restantes. Se B for maior que C, troca B com C. Ao final:
```text
A <= B <= C
```
### Execução manual — 8, 3, 5
Estado inicial:
```text
A = 8
B = 3
C = 5
```
Primeira comparação: `8 > 3` → verdadeiro → troca A e B.
```text
A = 3
B = 8
C = 5
```
Segunda comparação: `3 > 5` → falso → nada muda.
```text
A = 3
B = 8
C = 5
```
Terceira comparação: `8 > 5` → verdadeiro → troca B e C.
```text
A = 3
B = 5
C = 8
```
Resultado final: **3, 5, 8**.
### 📦 Analogia do estoque
Imagine três posições do estoque:
```text
A → 03-04-08 → quantidade 8
B → 03-04-09 → quantidade 3
C → 03-04-10 → quantidade 5
```
O `main` entrega para `ordenaValores` um **romaneio de separação** contendo os endereços das três posições. A função não recebe apenas uma cópia das quantidades: usando os ponteiros, ela consegue acessar as posições originais.
Quando usamos:
```c
*a
```
é como dizer: **vá ao endereço indicado no romaneio para A e veja a quantidade armazenada ali**.
Quando fazemos:
```c
*a = *b;
```
é como acessar as duas posições e colocar em A o valor encontrado em B.
A variável `auxiliar` funciona como uma posição temporária: seguramos uma quantidade enquanto reorganizamos as outras duas, evitando perder o valor original.
### O que este exercício combina
`if` faz as comparações; `>` verifica se os valores estão fora da ordem; `&` envia os endereços; os parâmetros `int *` recebem esses endereços; `*` acessa e altera os valores originais; `auxiliar` permite realizar as trocas sem perder dados.
> **Imagem mental:** `&` coloca o endereço no romaneio → o ponteiro recebe o endereço → `*` leva até a posição original → `if` decide se é necessário trocar → `auxiliar` segura temporariamente um valor → os três números terminam em ordem crescente.
