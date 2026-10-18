# Aula 01 - Matrizes em C: Estrutura, Índices e Percurso

**Data:** 03/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3b6d0f04d5398172930fe271a0c17a8a)

> **Objetivo da aula:** compreender matrizes em C como estruturas organizadas em linhas e colunas; percorrê-las com dois laços `for` aninhados; acessar cada posição por `matriz[linha][coluna]`; e usar valores, operações e condições para criar padrões.
## 1. O que é uma matriz?
Uma matriz pode ser entendida como uma **planilha**: existem linhas, colunas e células. Cada célula é uma posição em que podemos armazenar um valor.
```c
int matriz[5][6];
```
Essa declaração cria uma matriz com:
- **5 linhas**;
- **6 colunas**;
- **30 posições** no total;
- cada posição armazena um valor do tipo `int`.
### Índices começam em 0
Apesar de existirem 5 linhas, os índices são:
```text
0, 1, 2, 3, 4
```
E as 6 colunas são:
```text
0, 1, 2, 3, 4, 5
```
> **Regra importante:** quantidade e último índice não são a mesma coisa. Uma matriz com 5 linhas termina na linha 4; uma matriz com 6 colunas termina na coluna 5.
## 2. Como acessar uma célula
A estrutura é:
```c
matriz[linha][coluna]
```
Por exemplo:
```c
matriz[2][4]
```
significa acessar a posição localizada na **linha 2 e coluna 4**.
### Analogia
Imagine um prédio. `linha` indica o andar e `coluna` indica o apartamento daquele andar. Assim, `matriz[2][4]` funciona como uma coordenada: primeiro encontramos a linha e depois a coluna.
## 3. Como percorrer uma matriz
Como a matriz possui duas dimensões, usamos **dois `for` aninhados**.
```c
for (int linha = 0; linha < 5; linha++) {
    for (int coluna = 0; coluna < 6; coluna++) {
        // trabalha com matriz[linha][coluna]
    }
}
```
### Fluxo lógico
1. O `for` externo seleciona uma linha.
2. O `for` interno percorre todas as colunas daquela linha.
3. Quando as colunas terminam, o programa avança para a próxima linha.
4. O processo continua até percorrer toda a matriz.
Na linha 0, por exemplo, o percurso é:
```text
[0][0] → [0][1] → [0][2] → [0][3] → [0][4] → [0][5]
```
Depois:
```text
[1][0] → [1][1] → [1][2] → [1][3] → [1][4] → [1][5]
```
> **Resumo:** o `for` externo controla as linhas; o `for` interno percorre as colunas da linha atual.
---
## 4. Exercício 2 — preencher tudo com 1
A primeira regra trabalhada é preencher todas as posições com o mesmo valor.
```c
matriz[linha][coluna] = 1;
```
Leia como: **“na célula em que estou agora, coloque 1.”**
Resultado:
```text
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
```
O programa visita as 30 posições e executa a mesma atribuição em todas elas.
## 5. Exercício 3 — valor da linha
Agora cada posição recebe o valor da linha em que se encontra.
```c
matriz[linha][coluna] = linha;
```
Resultado:
```text
0 0 0 0 0 0
1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4
```
Quando `linha == 2`, por exemplo, todas as colunas daquela linha recebem `2`.
> Aqui aparece uma ideia importante: `linha` não serve apenas para localizar uma posição. Seu valor também pode participar da atribuição ou de um cálculo.
## 6. Exercício 4 — valor da coluna
Agora fazemos o inverso:
```c
matriz[linha][coluna] = coluna;
```
Resultado:
```text
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
```
No exercício anterior, o valor mudava quando mudávamos de **linha**. Aqui, o valor muda quando mudamos de **coluna**.
## 7. Exercício 5 — diagonal principal
Agora usamos uma condição para decidir o valor de cada célula.
```c
if (linha == coluna) {
    matriz[linha][coluna] = 1;
} else {
    matriz[linha][coluna] = 0;
}
```
Resultado:
```text
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
```
As posições com `1` são:
```text
[0][0]
[1][1]
[2][2]
[3][3]
[4][4]
```
O padrão é claro: **linha e coluna possuem o mesmo índice**.
> A partir daqui, passamos a decidir o valor de uma célula com base em sua posição.
## 8. Exercício 6 — linha + coluna
Neste exercício, o valor armazenado é calculado pela soma dos índices.
```c
matriz[linha][coluna] = linha + coluna;
```
Resultado:
```text
0 1 2 3 4 5
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
```
Exemplo:
```text
matriz[2][3]
linha = 2
coluna = 3
2 + 3 = 5
```
Portanto, `matriz[2][3]` recebe `5`.
## 9. Exercício 7 — linha × coluna
A estrutura permanece igual, mas agora multiplicamos os índices.
```c
matriz[linha][coluna] = linha * coluna;
```
Resultado:
```text
0 0 0 0  0  0
0 1 2 3  4  5
0 2 4 6  8 10
0 3 6 9 12 15
0 4 8 12 16 20
```
Por exemplo, na posição `[4][5]`:
```text
4 × 5 = 20
```
Esse exercício funciona como uma pequena **tabuada bidimensional**.
## 10. Exercício 8 — região triangular
Agora utilizamos uma comparação entre coluna e linha.
```c
if (coluna <= linha) {
    matriz[linha][coluna] = 1;
} else {
    matriz[linha][coluna] = 0;
}
```
Resultado:
```text
1 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
1 1 1 1 0 0
1 1 1 1 1 0
```
A condição `coluna <= linha` seleciona uma região inteira da matriz. Na linha 0 existe uma posição com `1`; na linha 1 existem duas; na linha 2 existem três; e assim sucessivamente.
## 11. Exercício 9 — moldura
O objetivo é criar uma borda de `1` e deixar o interior com `0`.
```text
1 1 1 1 1 1
1 0 0 0 0 1
1 0 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
```
Precisamos identificar quatro situações:
- `linha == 0` → borda superior;
- `linha == 4` → borda inferior;
- `coluna == 0` → borda esquerda;
- `coluna == 5` → borda direita.
Como basta que **uma dessas condições** seja verdadeira, usamos o operador lógico OU: `||`.
```c
if (linha == 0 || linha == 4 || coluna == 0 || coluna == 5) {
    matriz[linha][coluna] = 1;
} else {
    matriz[linha][coluna] = 0;
}
```
> **Por que não `&&`?** Porque `&&` exigiria que as condições fossem verdadeiras ao mesmo tempo. Uma linha não pode ser simultaneamente 0 e 4. Com `||`, basta estar em cima **OU** embaixo **OU** à esquerda **OU** à direita.
---
## 12. Preencher × exibir
Nos exercícios existem dois trabalhos diferentes:
1. **preencher a matriz**;
2. **mostrar a matriz na tela**.
Para exibir:
```c
for (linha = 0; linha < 5; linha++) {
    for (coluna = 0; coluna < 6; coluna++) {
        printf("%d ", matriz[linha][coluna]);
    }
    printf("\n");
}
```
O `printf("\n")` fica **depois do `for` das colunas**, pois a quebra de linha deve acontecer somente quando todas as colunas da linha atual já foram impressas.
## 13. Estrutura geral dos exercícios
```c
#include <stdio.h>

int main(void) {
    int matriz[5][6];
    int linha, coluna;

    // 1. Percorrer e preencher a matriz
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 6; coluna++) {
            // regra do exercício
        }
    }

    // 2. Percorrer novamente para exibir
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 6; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
```
A estrutura geral praticamente não muda. O que muda de um exercício para outro é principalmente **a regra aplicada a `matriz[linha][coluna]`**.
## 14. Evolução lógica da Aula 1
```text
MATRIZ
  ↓
matriz[linha][coluna]
  ↓
FOR das linhas
  ↓
FOR das colunas
  ↓
acessar cada célula
  ↓
atribuir um valor
  ↓
usar linha/coluna no cálculo
  ↓
usar IF/ELSE para tomar decisões
  ↓
criar padrões dentro da matriz
```
> **Frase-chave da aula:** uma matriz é uma estrutura organizada em linhas e colunas. Usamos dois `for` aninhados para percorrê-la. Em cada posição `matriz[linha][coluna]`, podemos armazenar um valor fixo, calcular um valor usando linha e coluna ou usar condições para decidir o valor daquela posição.
## 15. Checklist de domínio
- [ ] Sei explicar por que uma matriz `5 × 6` possui linhas `0–4` e colunas `0–5`.
- [ ] Sei explicar o papel do `for` externo e do `for` interno.
- [ ] Sei identificar uma posição usando `matriz[linha][coluna]`.
- [ ] Sei preencher uma matriz com um valor fixo.
- [ ] Sei utilizar `linha` e `coluna` em cálculos.
- [ ] Sei identificar a diagonal principal usando `linha == coluna`.
- [ ] Sei usar `if/else` para definir valores de acordo com a posição.
- [ ] Sei explicar quando utilizar `||` em uma condição.
- [ ] Sei imprimir uma matriz preservando sua organização em linhas e colunas.
## 16. Resumo para revisão rápida
| Conceito | Regra principal |
| --- | --- |
| Matriz 5 × 6 | `int matriz[5][6];` |
| Acessar célula | `matriz[linha][coluna]` |
| Percorrer | dois `for` aninhados |
| Ex. 2 | valor fixo `1` |
| Ex. 3 | `= linha` |
| Ex. 4 | `= coluna` |
| Ex. 5 | `linha == coluna` |
| Ex. 6 | `linha + coluna` |
| Ex. 7 | `linha * coluna` |
| Ex. 8 | `coluna <= linha` |
| Ex. 9 | quatro bordas usando `\|\|` |
