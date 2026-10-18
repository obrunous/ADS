# Aula 04 - Matrizes e Vetores: Análise de Vendas por Loja e Trimestre

**Data:** 17/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3c3d0f04d5398013835be78c3171e18e)

> **Objetivo da aula:** aplicar matrizes e vetores a um problema de vendas. O programa registra as vendas de **3 lojas durante 4 trimestres**, calcula o total vendido por cada loja e por cada trimestre e identifica a loja e o trimestre com maior valor de vendas.
## 1. Visão geral do sistema
O programa trabalha com uma matriz de vendas:
```c
int vendas[3][4];
```
- **3 linhas** → representam as 3 lojas.
- **4 colunas** → representam os 4 trimestres.
- Cada posição `vendas[linha][coluna]` guarda o valor vendido por uma loja em determinado trimestre.
**Fluxo lógico:** loja + trimestre → localizar uma célula da matriz → armazenar o valor da venda.
**Analogia:** imagine uma planilha. Cada linha é uma loja e cada coluna é um trimestre. A célula onde linha e coluna se encontram contém quanto aquela loja vendeu naquele período.
## 2. Estruturas de dados utilizadas
O código utiliza uma matriz e dois vetores principais:
```c
int vendas[3][4];
int lojas[3];
int trimestre[4];
```
| Estrutura | Função no programa |
| --- | --- |
| `vendas[3][4]` | Armazena as vendas das 3 lojas nos 4 trimestres |
| `lojas[3]` | Armazena o total vendido por cada loja |
| `trimestre[4]` | Armazena o total vendido em cada trimestre |
## 3. Variáveis de controle e maior valor
```c
int linha,coluna;
int maiorvalorloja,indicemaiorvalorloja;
int maiorvalortrimestre,indicemaiorvalortrimestre;
```
- `linha` percorre as lojas.
- `coluna` percorre os trimestres.
- `maiorvalorloja` guarda o maior total encontrado entre as lojas.
- `indicemaiorvalorloja` guarda a posição da loja que possui esse maior total.
- `maiorvalortrimestre` guarda o maior total encontrado entre os trimestres.
- `indicemaiorvalortrimestre` guarda a posição do trimestre correspondente.
## 4. Entrada dos dados de vendas
```c
for(linha=0;linha<3;linha++)
{
    for(coluna=0;coluna<4;coluna++)
    {
        printf("\nInforme o valor da Loja:%d trimestre: %d-->",linha+1,coluna+1);
        scanf("%d",&vendas[linha][coluna]);
    }
}
```
### Fluxo lógico
1. O `for` externo escolhe uma loja.
2. O `for` interno percorre os quatro trimestres dessa loja.
3. O usuário informa o valor vendido.
4. O valor é armazenado em `vendas[linha][coluna]`.
5. Depois dos quatro trimestres, o programa passa para a próxima loja.
### Analogia
Imagine um funcionário preenchendo uma planilha anual. Ele começa na **Loja 1** e registra trimestre 1, 2, 3 e 4. Depois desce para a **Loja 2** e repete o processo. Por último, faz o mesmo com a Loja 3.
Como são 3 lojas × 4 trimestres, serão preenchidas **12 posições** da matriz.
## 5. Por que aparece `linha+1` e `coluna+1`?
Internamente, os índices começam em zero:
- lojas: `0`, `1`, `2`;
- trimestres: `0`, `1`, `2`, `3`.
Para apresentar uma numeração mais natural ao usuário, o programa usa:
```c
linha+1
coluna+1
```
Assim, o índice `0` aparece como **Loja 1** ou **Trimestre 1**.
## 6. Exibição da matriz de vendas
```c
printf("\nMostrar Dados da Venda.\n");
for(linha=0;linha<3;linha++)
{
    for(coluna=0;coluna<4;coluna++)
    {
        printf("%4d ",vendas[linha][coluna]);
    }
    printf("\n");
}
```
O programa percorre novamente toda a matriz, mas agora apenas para mostrar os valores.
**Ponto importante:** o `printf("\n");` fica depois do `for` das colunas. Isso faz com que, depois de mostrar os quatro trimestres de uma loja, a próxima loja seja exibida em uma nova linha.
## 7. Inicialização do vetor `lojas`
```c
for(linha=0;linha<3;linha++)
{
    lojas[linha]=0;
}
```
Antes de começar a somar as vendas, cada posição do vetor precisa começar em zero.
Visualmente:
```text
lojas = [0, 0, 0]
```
**Analogia:** são três caixas vazias, uma para cada loja. O programa vai colocar dentro de cada caixa a soma dos quatro trimestres daquela loja.
## 8. Inicialização do vetor `trimestre`
```c
for(coluna=0;coluna<4;coluna++)
{
    trimestre[coluna]=0;
}
```
O mesmo princípio é aplicado aos quatro trimestres:
```text
trimestre = [0, 0, 0, 0]
```
Cada posição começa em zero para depois acumular as vendas das três lojas.
## 9. Somando por loja e por trimestre
Este é um dos blocos centrais da aula:
```c
for(linha=0;linha<3;linha++)
{
    for(coluna=0;coluna<4;coluna++)
    {
        lojas[linha]=lojas[linha]+vendas[linha][coluna];
        trimestre[coluna]=trimestre[coluna]+vendas[linha][coluna];
    }
}
```
A mesma célula da matriz alimenta **dois totais diferentes**.
### Soma por linha — loja
```c
lojas[linha]=lojas[linha]+vendas[linha][coluna];
```
Enquanto a linha permanece na mesma loja, as quatro colunas são somadas.
Exemplo conceitual:
```text
Loja 1: 100 + 200 + 300 + 400 = 1000
```
O resultado fica em:
```c
lojas[0]
```
### Soma por coluna — trimestre
```c
trimestre[coluna]=trimestre[coluna]+vendas[linha][coluna];
```
Agora o agrupamento é por coluna: o programa soma as vendas das diferentes lojas que pertencem ao mesmo trimestre.
Exemplo conceitual:
```text
Trimestre 1 = Loja 1 + Loja 2 + Loja 3
```
### Analogia da planilha
Na matriz, **somar horizontalmente** produz o total de uma loja. **Somar verticalmente** produz o total de um trimestre.
```text
                T1    T2    T3    T4      TOTAL LOJA
Loja 1          [ ]   [ ]   [ ]   [ ]  → lojas[0]
Loja 2          [ ]   [ ]   [ ]   [ ]  → lojas[1]
Loja 3          [ ]   [ ]   [ ]   [ ]  → lojas[2]
                 ↓     ↓     ↓     ↓
                tri0  tri1  tri2  tri3
```
## 10. Exibindo o total vendido por loja
```c
printf("\nMostrar Dados das Vendas nas Lojas\n");
for(linha=0;linha<3;linha++)
{
    printf("\nLoja: %d Vendeu: %d",linha+1,lojas[linha]);
}
```
Agora não é mais necessário percorrer a matriz inteira. Os totais já estão armazenados no vetor `lojas`.
## 11. Exibindo o total vendido por trimestre
```c
printf("\nMostrar Dados das Vendas por Trimestre\n");
for(coluna=0;coluna<4;coluna++)
{
    printf("\nTrimestre: %d Valor:%d",coluna+1,trimestre[coluna]);
}
```
O vetor `trimestre` possui quatro posições, uma para cada trimestre.
## 12. Encontrando a loja com maior valor
Primeiro, o código assume que a primeira loja possui o maior valor:
```c
maiorvalorloja = lojas[0];
indicemaiorvalorloja = 0;
```
Depois compara com as demais:
```c
for(linha=1;linha<3;linha++)
{
    if(maiorvalorloja < lojas[linha])
    {
        maiorvalorloja = lojas[linha];
        indicemaiorvalorloja = linha;
    }
}
```
### Fluxo lógico
1. Use a Loja 1 como maior valor inicial.
2. Compare com a Loja 2.
3. Se a Loja 2 for maior, atualize o maior valor e o índice.
4. Compare o maior atual com a Loja 3.
5. Ao final, teremos o maior valor e a posição da loja vencedora.
**Analogia:** é como um campeonato. A Loja 1 começa como campeã provisória. Cada nova loja desafia a campeã. Se vender mais, assume a liderança.
## 13. Valor e índice são informações diferentes
O programa precisa guardar duas coisas:
```c
maiorvalorloja
indicemaiorvalorloja
```
- **valor:** quanto foi vendido;
- **índice:** qual loja realizou aquela venda.
A saída usa `+1` novamente:
```c
printf("\nMaior valor encontrado:%d -> na loja->%d",maiorvalorloja,indicemaiorvalorloja+1);
```
Isso converte, por exemplo, o índice `0` em Loja 1.
## 14. Encontrando o trimestre com maior valor
A lógica é a mesma utilizada para as lojas, mas aplicada ao vetor `trimestre`:
```c
maiorvalortrimestre = trimestre[0];
indicemaiorvalortrimestre = 0;
for(coluna=1;coluna<4;coluna++)
{
    if(maiorvalortrimestre < trimestre[coluna])
    {
        maiorvalortrimestre = trimestre[coluna];
        indicemaiorvalortrimestre = coluna;
    }
}
```
O primeiro trimestre começa como maior provisório. Os trimestres seguintes são comparados um a um.
Ao final:
```c
printf("\nTrimestre Maior valor encontrado:%d -> no Trimestre->%d",maiorvalortrimestre,indicemaiorvalortrimestre+1);
```
## 15. Fluxo completo do programa
```text
INÍCIO
  ↓
criar matriz vendas[3][4]
  ↓
receber vendas das 3 lojas × 4 trimestres
  ↓
mostrar matriz de vendas
  ↓
zerar vetor lojas[3]
  ↓
zerar vetor trimestre[4]
  ↓
percorrer matriz novamente
  ↓
para cada venda:
  ├─ somar no total da loja
  └─ somar no total do trimestre
  ↓
mostrar totais das lojas
  ↓
mostrar totais dos trimestres
  ↓
procurar maior valor no vetor lojas
  ↓
guardar valor + índice da loja
  ↓
procurar maior valor no vetor trimestre
  ↓
guardar valor + índice do trimestre
  ↓
mostrar resultados
  ↓
FIM
```
## 16. Conceito central da aula
> A matriz `vendas` contém os **dados detalhados**. Os vetores `lojas` e `trimestre` armazenam **dados resumidos** calculados a partir da matriz. Percorrendo a mesma matriz, o programa consegue agrupar os valores por linha e por coluna.
Em uma frase:
> **Matriz → percorrer → acumular por linha e por coluna → comparar totais → encontrar o maior.**
## 17. O que esta aula acrescenta ao estudo de matrizes
Nas aulas anteriores, a matriz já era percorrida usando dois `for`. Aqui, o mesmo mecanismo passa a ser usado para **produzir informações novas**.
```text
vendas[linha][coluna]
        ↓
valor individual
        ↓
   ┌────┴────┐
   ↓         ↓
lojas      trimestre
   ↓         ↓
total       total
por loja    por período
```
Assim, a matriz não serve apenas para armazenar e mostrar dados: seus valores podem alimentar cálculos, vetores auxiliares e análises.
## 18. Estruturas utilizadas
| Estrutura | Uso nesta aula |
| --- | --- |
| Matriz | Armazenar vendas por loja e trimestre |
| Vetores | Guardar totais das lojas e dos trimestres |
| `for` aninhado | Percorrer todas as células da matriz |
| Acumulador | Somar vendas progressivamente |
| `if` | Comparar valores para encontrar o maior |
| Índice | Identificar qual loja ou trimestre possui o maior valor |
## 19. Checklist de domínio
- [ ] Entendo por que `vendas[3][4]` representa 3 lojas e 4 trimestres.
- [ ] Sei o que `linha` representa.
- [ ] Sei o que `coluna` representa.
- [ ] Consigo explicar `vendas[linha][coluna]`.
- [ ] Entendo por que são usados dois `for` aninhados.
- [ ] Sei por que `lojas` precisa começar com zero.
- [ ] Sei por que `trimestre` precisa começar com zero.
- [ ] Consigo explicar a soma por linha.
- [ ] Consigo explicar a soma por coluna.
- [ ] Entendo a diferença entre `maiorvalorloja` e `indicemaiorvalorloja`.
- [ ] Entendo a busca do maior valor usando `if`.
- [ ] Entendo por que a busca começa em `linha=1` ou `coluna=1` depois de usar a posição zero como valor inicial.
- [ ] Consigo descrever o fluxo completo do programa sem olhar o código.
## 20. Revisão rápida
| Pergunta | Resposta |
| --- | --- |
| Onde ficam as vendas individuais? | `vendas[3][4]` |
| O que uma linha representa? | Uma loja |
| O que uma coluna representa? | Um trimestre |
| Onde fica o total de cada loja? | `lojas[3]` |
| Onde fica o total de cada trimestre? | `trimestre[4]` |
| Como obter o total de uma loja? | Somando horizontalmente a linha correspondente |
| Como obter o total de um trimestre? | Somando verticalmente a coluna correspondente |
| Como encontrar o maior? | Assumir o primeiro como maior e comparar com os seguintes |
## 21. Código-base da aula
O código abaixo foi mantido conforme o material fornecido para esta aula:
```c
#include "stdio.h"
void main()
{
   int vendas[3][4];
   int lojas[3];
   int trimestre[4];
   int linha,coluna;
   int maiorvalorloja,indicemaiorvalorloja;
   int maiorvalortrimestre,indicemaiorvalortrimestre;
   // receber os dados
   for(linha=0;linha<3;linha++)
   {
       for(coluna=0;coluna<4;coluna++)
       {
           printf("\nInforme o valor da Loja:%d trimestre: %d-->",linha+1,coluna+1);
           scanf("%d",&vendas[linha][coluna]);
       }
   }
   printf("\nMostrar Dados da Venda.\n");
   for(linha=0;linha<3;linha++)
   {
       for(coluna=0;coluna<4;coluna++)
       {
           printf("%4d ",vendas[linha][coluna]);
       }
       printf("\n");
   }
   for(linha=0;linha<3;linha++)
   {
       lojas[linha]=0;
   }
   for(coluna=0;coluna<4;coluna++)
   {
       trimestre[coluna]=0;
   }
   for(linha=0;linha<3;linha++)
   {
       for(coluna=0;coluna<4;coluna++)
       {
           lojas[linha]=lojas[linha]+vendas[linha][coluna];
           trimestre[coluna]=trimestre[coluna]+vendas[linha][coluna];
       }
   }
   printf("\nMostrar Dados das Vendas nas Lojas\n");
   for(linha=0;linha<3;linha++)
   {
       printf("\nLoja: %d Vendeu: %d",linha+1,lojas[linha]);
   }
   printf("\nMostrar Dados das Vendas por Trimestre\n");
   for(coluna=0;coluna<4;coluna++)
   {
       printf("\nTrimestre: %d Valor:%d",coluna+1,trimestre[coluna]);
   }
   printf("\nMaior Valor por Loja\n");
   maiorvalorloja = lojas[0];
   indicemaiorvalorloja = 0;
   for(linha=1;linha<3;linha++)
   {
       if(maiorvalorloja < lojas[linha])
       {
           maiorvalorloja = lojas[linha];
           indicemaiorvalorloja = linha;
       }
   }
   printf("\nMaior valor encontrado:%d -> na loja->%d",maiorvalorloja,indicemaiorvalorloja+1);

   printf("\nMaior Valor por Trimestre\n");
   maiorvalortrimestre = trimestre[0];
   indicemaiorvalortrimestre = 0;
   for(coluna=1;coluna<4;coluna++)
   {
       if(maiorvalortrimestre < trimestre[coluna])
       {
           maiorvalortrimestre = trimestre[coluna];
           indicemaiorvalortrimestre = coluna;
       }
   }
   printf("\nTrimestre Maior valor encontrado:%d -> no Trimestre->%d",maiorvalortrimestre,indicemaiorvalortrimestre+1);
}
```
> **Para a prova:** concentre-se principalmente na relação entre **matriz, linha, coluna, vetores acumuladores e busca do maior valor**. Esse é o encadeamento lógico central do programa desta aula.
