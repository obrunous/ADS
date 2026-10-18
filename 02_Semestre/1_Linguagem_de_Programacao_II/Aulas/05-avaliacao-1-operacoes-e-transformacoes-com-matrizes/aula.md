# Aula 05 - Avaliação 1: Operações e Transformações com Matrizes

**Data:** 24/08/2026

**Fonte:** [Página da avaliação no Notion](https://app.notion.com/p/3b6d0f04d53981a48c21e1a13ed767e1)

## Prova 1 — Matrizes em C
> **Data:** 24/08/2026
> **Resultado:** **Conceito A**
> **Tema central:** criação, leitura, processamento e transformação de matrizes usando estruturas de repetição.
### Objetivos desta aula
Ao revisar esta prova, o estudante deve ser capaz de:
- declarar matrizes e vetores em C;
- percorrer linhas e colunas com dois `for`;
- criar padrões usando os índices;
- somar matrizes;
- construir uma matriz transposta;
- localizar e contar valores que obedecem a uma condição;
- somar cada coluna e guardar os resultados em um vetor;
- executar mentalmente um código e desenhar a matriz produzida.
### 1. Fundamento principal: como percorrer uma matriz
Uma matriz possui duas dimensões:
- `linha`: indica a posição vertical;
- `coluna`: indica a posição horizontal.
Para visitar todas as posições, usamos dois laços:
```c
for (linha = 0; linha < totalLinhas; linha++) {
    for (coluna = 0; coluna < totalColunas; coluna++) {
        // trabalhar com matriz[linha][coluna]
    }
}
```
#### Fluxo lógico
1. O primeiro `for` escolhe uma linha.
2. O segundo `for` percorre todas as colunas dessa linha.
3. Ao terminar a linha, o programa avança para a próxima.
4. O processo acaba quando todas as posições forem visitadas.
#### Analogia
Imagine um funcionário conferindo as cadeiras de uma sala. Ele entra na primeira fileira, verifica cadeira por cadeira e, somente depois, passa para a fileira seguinte. A fileira representa a linha; cada cadeira representa uma coluna.
---
## Gabarito comentado
### Questão 1 — Matriz alternada 7 × 7
A matriz solicitada alterna `0` e `1`:
```text
0 1 0 1 0 1 0
1 0 1 0 1 0 1
0 1 0 1 0 1 0
1 0 1 0 1 0 1
0 1 0 1 0 1 0
1 0 1 0 1 0 1
0 1 0 1 0 1 0
```
#### Ideia lógica
A soma `linha + coluna` informa se a posição é par ou ímpar:
- soma par → `0`;
- soma ímpar → `1`.
#### Código completo
```c
#include <stdio.h>

int main(void) {
    int matriz[7][7];
    int linha, coluna;

    for (linha = 0; linha < 7; linha++) {
        for (coluna = 0; coluna < 7; coluna++) {
            matriz[linha][coluna] = (linha + coluna) % 2;
        }
    }

    for (linha = 0; linha < 7; linha++) {
        for (coluna = 0; coluna < 7; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
```
#### Analogia
É como montar um tabuleiro. Depois de colocar uma peça de uma cor, a próxima deve ser da outra cor. Ao começar uma nova linha, a cor inicial também se alterna.
#### Erro comum
Usar somente `coluna % 2` faria todas as linhas começarem com `0`. A expressão precisa considerar **linha e coluna**.
---
### Questão 2 — Soma de duas matrizes 4 × 3
Para somar matrizes, somamos elementos que ocupam a mesma posição:
```c
C[linha][coluna] = A[linha][coluna] + B[linha][coluna];
```
#### Fluxo lógico
1. Ler ou possuir os valores de `A`.
2. Ler ou possuir os valores de `B`.
3. Percorrer as 12 posições.
4. Somar os elementos correspondentes.
5. Guardar cada resultado em `C`.
6. Mostrar a matriz `C`.
#### Código completo
```c
#include <stdio.h>

int main(void) {
    int A[4][3], B[4][3], C[4][3];
    int linha, coluna;

    printf("Digite os valores da matriz A:\n");
    for (linha = 0; linha < 4; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            scanf("%d", &A[linha][coluna]);
        }
    }

    printf("Digite os valores da matriz B:\n");
    for (linha = 0; linha < 4; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            scanf("%d", &B[linha][coluna]);
        }
    }

    for (linha = 0; linha < 4; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            C[linha][coluna] =
                A[linha][coluna] + B[linha][coluna];
        }
    }

    printf("Matriz C:\n");
    for (linha = 0; linha < 4; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            printf("%d ", C[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
```
#### Analogia
Imagine duas bandejas iguais, cada uma com 4 fileiras e 3 espaços. Somamos o conteúdo do primeiro espaço da bandeja A ao primeiro espaço da bandeja B, repetindo isso posição por posição.
#### Erro comum
Somar posições diferentes ou inverter os índices. A posição `A[2][1]` deve ser somada exatamente com `B[2][1]`.
---
### Questão 3 — Matriz transposta 10 × 10
Na transposta, linhas viram colunas:
```c
MatrizT[coluna][linha] = matrizX[linha][coluna];
```
#### Exemplo pequeno
Matriz original:
```text
1 2 3
4 5 6
```
Transposta:
```text
1 4
2 5
3 6
```
#### Código completo
```c
#include <stdio.h>

int main(void) {
    int matrizX[10][10];
    int matrizT[10][10];
    int linha, coluna;

    printf("Digite os 100 valores da matriz X:\n");

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            scanf("%d", &matrizX[linha][coluna]);
        }
    }

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            matrizT[coluna][linha] =
                matrizX[linha][coluna];
        }
    }

    printf("Matriz transposta:\n");

    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", matrizT[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
```
#### Analogia
É como virar uma planilha: o que estava organizado horizontalmente passa a ficar vertical. A posição linha 2, coluna 5 passa para linha 5, coluna 2.
#### Erro comum
Fazer `matrizT[linha][coluna] = matrizX[linha][coluna]`. Isso apenas copia a matriz; não cria a transposta.
---
### Questão 4 — Valores acima de 32
Matriz fornecida:
```text
 4  91 100 20
 5   9   8 21
89   4   6  3
34   7   4 15
12   5   2 20
```
Valores maiores que 32:
```text
91 100 89 34
```
**Quantidade: 4 valores.**
#### Código completo
```c
#include <stdio.h>

int main(void) {
    int A[5][4] = {
        {4, 91, 100, 20},
        {5, 9, 8, 21},
        {89, 4, 6, 3},
        {34, 7, 4, 15},
        {12, 5, 2, 20}
    };

    int linha, coluna;
    int contador = 0;

    printf("Valores acima de 32:\n");

    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 4; coluna++) {
            if (A[linha][coluna] > 32) {
                printf("%d ", A[linha][coluna]);
                contador++;
            }
        }
    }

    printf("\nQuantidade: %d\n", contador);

    return 0;
}
```
#### Fluxo lógico
1. Inicializar `contador` com zero.
2. Percorrer cada posição.
3. Verificar se o valor é maior que 32.
4. Se for, mostrar o valor e incrementar o contador.
5. Após os laços, mostrar a quantidade.
#### Analogia
Um fiscal examina cada caixa de um estoque. Sempre que encontra uma caixa com mais de 32 itens, anota o número e soma uma ocorrência ao relatório.
#### Erros comuns
- usar `>= 32` quando a questão diz **acima de 32**;
- esquecer `contador = 0`;
- colocar o `printf` da quantidade dentro dos laços.
---
### Questão 5 — Soma das colunas em um vetor
Usando a matriz da questão 4:
| Coluna | Cálculo | Soma |
| --- | --- | --- |
| 0 | 4 + 5 + 89 + 34 + 12 | 144 |
| 1 | 91 + 9 + 4 + 7 + 5 | 116 |
| 2 | 100 + 8 + 6 + 4 + 2 | 120 |
| 3 | 20 + 21 + 3 + 15 + 20 | 79 |
**Vetor resultante:**
```text
144 116 120 79
```
#### Ideia lógica
Para somar uma coluna inteira, a coluna precisa permanecer fixa enquanto as linhas variam.
#### Código completo
```c
#include <stdio.h>

int main(void) {
    int A[5][4] = {
        {4, 91, 100, 20},
        {5, 9, 8, 21},
        {89, 4, 6, 3},
        {34, 7, 4, 15},
        {12, 5, 2, 20}
    };

    int vetor[4] = {0, 0, 0, 0};
    int linha, coluna;

    for (coluna = 0; coluna < 4; coluna++) {
        for (linha = 0; linha < 5; linha++) {
            vetor[coluna] += A[linha][coluna];
        }
    }

    printf("Soma das colunas:\n");

    for (coluna = 0; coluna < 4; coluna++) {
        printf("%d ", vetor[coluna]);
    }

    printf("\n");

    return 0;
}
```
#### Analogia
Imagine quatro cofres, um para cada coluna. O funcionário mantém um cofre selecionado e percorre todas as linhas colocando nele os valores daquela coluna. Depois passa para o próximo cofre.
#### Erros comuns
- criar um vetor com 5 posições, embora existam somente 4 colunas;
- não zerar o vetor antes da soma;
- trocar os limites: são 5 linhas e 4 colunas;
- percorrer por linhas sem organizar corretamente o acumulador de cada coluna.
---
### Questão 6 — Interpretação de código
A condição da prova é:
```c
if (linha >= coluna) {
    matriz[linha][coluna] = 1;
} else {
    matriz[linha][coluna] = 0;
}
```
#### Como pensar
Para cada célula, compare o número da linha com o número da coluna:
- se `linha >= coluna`, recebe `1`;
- caso contrário, recebe `0`.
#### Execução por linha
- Linha 0: somente `0 >= 0` é verdadeiro.
- Linha 1: `1 >= 0` e `1 >= 1` são verdadeiros.
- Linha 2: colunas 0, 1 e 2 recebem `1`.
- Linha 3: colunas 0, 1, 2 e 3 recebem `1`.
- Linha 4: todas as colunas recebem `1`.
#### Resultado correto
```text
1 0 0 0 0
1 1 0 0 0
1 1 1 0 0
1 1 1 1 0
1 1 1 1 1
```
A diagonal principal e tudo que está abaixo dela recebem `1`.
#### Analogia
Imagine uma escada. A cada linha descida, aparece um degrau a mais. A primeira linha tem um bloco; a segunda tem dois; até a última, que possui cinco.
---
## Síntese do que a prova avaliou
| Habilidade | Questão |
| --- | --- |
| Criar padrões com índices | 1 |
| Somar matrizes | 2 |
| Trocar linhas por colunas | 3 |
| Filtrar e contar valores | 4 |
| Acumular valores por coluna | 5 |
| Simular mentalmente um código | 6 |
### Modelo mental para qualquer exercício de matriz
Antes de programar, responda:
1. Qual é o número de linhas?
2. Qual é o número de colunas?
3. Preciso preencher, ler, calcular ou mostrar?
4. O cálculo acontece em cada célula?
5. Preciso de um `if`?
6. Preciso de contador, acumulador, vetor ou outra matriz?
7. A variável deve ser zerada antes dos laços ou a cada nova linha/coluna?
8. Os índices permanecem iguais ou devem ser invertidos?
---
## Como deveria ter sido a preparação
### Plano ideal de 7 dias
#### Dia 1 — Estrutura e percurso
**Objetivo:** dominar declaração, índices e dois `for`.
- Declarar matrizes 3 × 3, 4 × 3 e 5 × 4.
- Preencher valores pelo teclado.
- Mostrar as matrizes corretamente.
- Desenhar no papel a ordem em que as posições são visitadas.
**Exercício final:** ler e mostrar uma matriz 5 × 4.
#### Dia 2 — Padrões
**Objetivo:** aprender a criar valores a partir de `linha` e `coluna`.
- diagonal principal: `linha == coluna`;
- abaixo da diagonal: `linha > coluna`;
- diagonal e abaixo: `linha >= coluna`;
- tabuleiro alternado: `(linha + coluna) % 2`.
**Exercício final:** reproduzir a matriz alternada da questão 1 sem consultar a resposta.
#### Dia 3 — Operações entre matrizes
**Objetivo:** compreender operações posição por posição.
- Somar duas matrizes pequenas no papel.
- Programar a soma em `C`.
- Conferir manualmente três posições.
- Repetir usando matrizes 4 × 3.
**Exercício final:** resolver a questão 2 completa.
#### Dia 4 — Transposta
**Objetivo:** fixar a inversão dos índices.
- Fazer exemplos 2 × 3 no papel.
- Marcar setas de `X[linha][coluna]` para `T[coluna][linha]`.
- Programar uma transposta 3 × 3.
- Depois adaptar para 10 × 10.
**Exercício final:** resolver a questão 3 sem consultar material.
#### Dia 5 — Condições, contadores e acumuladores
**Objetivo:** distinguir contar de somar.
- Contador: `contador++`.
- Acumulador: `soma += valor`.
- Mostrar números maiores que um limite.
- Contar pares, ímpares e valores maiores que 32.
**Exercício final:** resolver a questão 4 e conferir manualmente o resultado.
#### Dia 6 — Soma por linhas e colunas
**Objetivo:** controlar qual índice permanece fixo.
- Somar cada linha.
- Somar cada coluna.
- Guardar resultados em vetores.
- Treinar a inicialização dos acumuladores.
**Exercício final:** obter sozinho o vetor `144 116 120 79`.
#### Dia 7 — Simulado completo
**Objetivo:** reproduzir as condições reais da prova.
- Tempo sugerido: 90 minutos.
- Sem consultar respostas.
- Resolver uma questão de cada tipo.
- Executar manualmente um código com `if/else`.
- Compilar todos os programas.
- Corrigir os erros e escrever por que ocorreram.
### Rotina diária sugerida — 60 minutos
- **10 minutos:** revisão dos conceitos do dia anterior.
- **15 minutos:** leitura e simulação no papel.
- **25 minutos:** programação sem copiar.
- **10 minutos:** compilação, correção e registro dos erros.
### Checklist para os minutos finais da prova
- [ ] Declarei a matriz com as dimensões corretas?
- [ ] Usei `linha < númeroDeLinhas`?
- [ ] Usei `coluna < númeroDeColunas`?
- [ ] Inicializei contadores, acumuladores e vetores?
- [ ] Usei `&` no `scanf`?
- [ ] Coloquei `printf("\\n")` depois de cada linha exibida?
- [ ] Na transposta, inverti os índices?
- [ ] Em “acima de 32”, usei `> 32`?
- [ ] Na soma das colunas, o vetor possui 4 posições?
- [ ] Fiz um teste manual com pelo menos uma linha ou coluna?
## Conclusão
A prova foi construída sobre uma única base: **percorrer uma matriz corretamente e decidir o que fazer em cada posição**. As variações foram criar um padrão, somar, inverter índices, filtrar, contar e acumular. O melhor preparo teria combinado desenho no papel, rastreamento dos índices e implementação prática diária.
