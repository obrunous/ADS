# Aula 02 - Matrizes Aplicadas: Sistema de Reservas de Cinema

**Data:** 10/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3b6d0f04d53981d2ac6efe791e14b61e)

> **Objetivo da aula:** aplicar matrizes em um problema real de programação: representar uma sala de cinema, inicializar assentos, visualizar a sala, reservar lugares, contabilizar assentos e controlar o sistema por meio de um menu.
## 1. Visão geral do sistema
Nesta aula, a matriz deixa de ser apenas um exercício abstrato e passa a representar uma situação real: **uma sala de cinema**.
A sala utilizada possui:
- **10 linhas**;
- **20 colunas**;
- **200 assentos** no total.
A estrutura principal é:
```c
int sala[10][20];
```
Cada posição da matriz representa um assento.
> **Analogia:** pense na matriz como o mapa físico da sala. Cada célula é uma poltrona. `sala[linha][coluna]` indica exatamente qual assento estamos consultando ou alterando.
## 2. Representação dos assentos
O sistema utiliza valores numéricos para representar o estado de cada assento:
```text
0 → assento livre
1 → assento ocupado/reservado
```
Assim, por exemplo:
```c
sala[3][7] = 0;
```
significa que o assento da linha 3 e coluna 7 está livre.
Depois de uma reserva:
```c
sala[3][7] = 1;
```
passa a significar que esse lugar está ocupado.
## 3. Estrutura lógica do projeto
O sistema foi construído em etapas, cada uma responsável por uma função específica:
1. declarar a matriz da sala;
2. inicializar todos os assentos;
3. visualizar a sala;
4. reservar um assento;
5. contabilizar livres e ocupados;
6. criar um menu para controlar as opções.
Os arquivos trabalhados foram organizados conceitualmente assim:
```text
matriz.c
inicializar.c
visualizar.c
reservar.c
contabilizar.c
menu.c
```
## 4. Declaração da matriz
A base do sistema é:
```c
int sala[10][20];
```
Isso cria 200 posições.
Os índices são:
```text
linhas:  0 até 9
colunas: 0 até 19
```
> Uma sala com 10 linhas termina no índice 9. Uma sala com 20 colunas termina no índice 19.
## 5. Inicialização da sala
Antes de utilizar a matriz, todos os assentos precisam começar com um estado conhecido.
A lógica é preencher toda a matriz com `0`.
```c
for (int linha = 0; linha < 10; linha++) {
    for (int coluna = 0; coluna < 20; coluna++) {
        sala[linha][coluna] = 0;
    }
}
```
### Fluxo lógico
```text
começar na linha 0
→ percorrer todas as 20 colunas
→ colocar 0 em cada assento
→ passar para a linha seguinte
→ repetir até a linha 9
```
### Analogia — funcionário preparando a sala
Imagine um funcionário entrando no cinema antes da sessão.
Ele começa na primeira fileira e verifica **assento por assento**.
```text
assento 1 → livre
assento 2 → livre
assento 3 → livre
...
```
Quando termina uma fileira, ele passa para a próxima.
É exatamente o que os dois `for` fazem.
> O `for` externo muda de fileira. O `for` interno percorre cada assento daquela fileira.
## 6. Visualização da sala
Depois de preencher a matriz, precisamos mostrar seu conteúdo ao usuário.
A lógica volta a usar dois `for` aninhados:
```c
for (int linha = 0; linha < 10; linha++) {
    for (int coluna = 0; coluna < 20; coluna++) {
        printf("%d ", sala[linha][coluna]);
    }
    printf("\n");
}
```
A primeira execução, com todos os assentos livres, apresenta uma matriz de zeros.
### Por que existe um `printf("\n")` fora do segundo `for`?
Porque primeiro precisamos imprimir todos os assentos da linha atual.
Depois que as 20 colunas forem exibidas, fazemos a quebra de linha.
```text
linha atual
→ imprime coluna 0
→ coluna 1
→ coluna 2
→ ...
→ coluna 19
→ quebra de linha
→ próxima linha
```
## 7. Reserva de um assento
O próximo passo é permitir que o usuário escolha um lugar.
O sistema solicita:
```text
linha
coluna
```
Esses valores indicam diretamente uma posição da matriz.
Exemplo:
```text
linha = 4
coluna = 12
```
A posição correspondente é:
```c
sala[4][12]
```
Para efetivar a reserva:
```c
sala[linha][coluna] = 1;
```
### Analogia
Imagine uma atendente olhando o mapa da sala.
O cliente diz:
> “Quero o assento da fileira 4, posição 12.”
A atendente localiza exatamente aquela célula e muda seu estado de **livre para ocupado**.
## 8. Validação dos limites
Antes de acessar a matriz, precisamos verificar se a posição existe.
Os limites válidos são:
```text
linha: 0 até 9
coluna: 0 até 19
```
A validação lógica é:
```c
if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 20) {
    // posição válida
}
```
Aqui usamos `&&` porque **todas as condições precisam ser verdadeiras ao mesmo tempo**.
Para uma posição ser válida:
```text
a linha precisa ser >= 0
E menor que 10
E a coluna precisa ser >= 0
E menor que 20
```
## 9. Verificação de assento ocupado
Antes de reservar, também devemos verificar o estado atual do assento.
```c
if (sala[linha][coluna] == 0) {
    sala[linha][coluna] = 1;
} else {
    printf("Assento ocupado.\n");
}
```
A lógica é:
```text
usuário escolhe posição
→ assento está livre?
    → sim: reservar
    → não: informar que já está ocupado
```
## 10. Uso do `do...while`
Na parte de reserva, foi utilizado o `do...while` para repetir a tentativa até que a reserva seja concluída corretamente.
Estrutura geral:
```c
do {
    // pedir linha e coluna
    // validar posição
    // tentar reservar
} while (/* condição de repetição */);
```
A principal característica do `do...while` é que o bloco é executado **pelo menos uma vez**.
### Analogia
O cliente precisa escolher um assento.
A atendente pergunta uma primeira vez obrigatoriamente.
Se a posição for inválida ou já estiver ocupada, ela pergunta novamente.
```text
escolher assento
→ deu certo?
    → sim: encerra
    → não: tenta novamente
```
## 11. Contabilização dos assentos
Outra etapa do sistema é contar quantos assentos estão livres e quantos estão ocupados.
Para isso, percorremos toda a matriz novamente.
Exemplo conceitual:
```c
int livres = 0;
int ocupados = 0;

for (int linha = 0; linha < 10; linha++) {
    for (int coluna = 0; coluna < 20; coluna++) {
        if (sala[linha][coluna] == 0) {
            livres++;
        } else {
            ocupados++;
        }
    }
}
```
### Fluxo lógico
```text
pegar um assento
→ valor é 0?
    → sim: livres++
    → não: ocupados++
→ próximo assento
```
### Analogia
Imagine o funcionário fazendo uma conferência antes da sessão.
Ele olha cada poltrona no mapa e anota:
```text
livre → soma 1 no contador de livres
ocupada → soma 1 no contador de ocupados
```
Depois de visitar os 200 assentos, temos o total exato.
## 12. O menu do sistema
Depois de construir as partes separadamente, elas são organizadas em um menu.
A estrutura utiliza `switch`.
Exemplo conceitual:
```c
switch (opcao) {
    case 1:
        // visualizar sala
        break;

    case 2:
        // reservar assento
        break;

    case 3:
        // contabilizar assentos
        break;

    case 4:
        // outra operação
        break;

    case 5:
        // sair
        break;

    default:
        printf("Opcao invalida.\n");
}
```
## 13. O que o `switch` faz?
O `switch` escolhe um caminho de execução com base na opção digitada.
```text
opção 1 → executa case 1
opção 2 → executa case 2
opção 3 → executa case 3
...
opção inválida → default
```
### Por que usamos `break`?
O `break` encerra o `case` atual e impede que o programa continue executando os casos seguintes.
## 14. Menu dentro de `do...while`
O menu precisa reaparecer depois de cada operação.
Por isso ele pode ser colocado dentro de um `do...while`.
```c
do {
    // mostrar menu
    // ler opcao

    switch (opcao) {
        // casos
    }

} while (opcao != 5);
```
O programa só termina quando o usuário escolhe a opção de saída.
### Analogia
É como um caixa eletrônico:
```text
mostra opções
→ usuário escolhe
→ sistema executa
→ volta ao menu
→ usuário escolhe novamente
```
Somente ao escolher **Sair** o atendimento termina.
## 15. Fluxo completo do sistema
```text
INÍCIO
  ↓
criar matriz sala[10][20]
  ↓
inicializar todos os assentos com 0
  ↓
mostrar menu
  ↓
ler opção
  ↓
SWITCH
  ├─ visualizar sala
  ├─ reservar assento
  │    ↓
  │  pedir linha e coluna
  │    ↓
  │  validar posição
  │    ↓
  │  verificar disponibilidade
  │    ↓
  │  alterar 0 para 1
  │
  ├─ contabilizar livres e ocupados
  └─ sair
  ↓
voltar ao menu
  ↓
opção == sair?
  ├─ não → menu novamente
  └─ sim → FIM
```
## 16. Estruturas de programação utilizadas
| Estrutura | Função no sistema |
| --- | --- |
| Matriz | Representar os assentos da sala |
| `for` aninhado | Percorrer linhas e colunas |
| `if/else` | Validar condições e verificar estado do assento |
| `do...while` | Repetir reservas e manter o menu em execução |
| `switch` | Escolher qual operação executar |
| Contadores | Somar quantidade de assentos livres e ocupados |
## 17. Evolução em relação à Aula 1
Na Aula 1, a matriz era utilizada principalmente para criar padrões numéricos.
Nesta aula, a mesma estrutura ganha **significado real**.
```text
AULA 1
matriz[linha][coluna]
→ posição numérica

AULA 2
sala[linha][coluna]
→ assento real do cinema
```
A ideia fundamental continua a mesma:
```text
percorrer matriz
→ localizar posição
→ consultar valor
→ tomar decisão
→ alterar valor quando necessário
```
## 18. Conceito central da aula
> **Frase-chave:** a matriz representa o estado da sala. Cada posição corresponde a um assento. Os laços percorrem os assentos; as condições analisam seu estado; a reserva altera o valor da posição; os contadores resumem a ocupação; e o menu controla o fluxo geral do programa.
## 19. Checklist de domínio
- [ ] Sei explicar por que `sala[10][20]` representa 200 assentos.
- [ ] Sei dizer quais são os índices válidos de linha e coluna.
- [ ] Sei explicar por que todos os assentos começam com `0`.
- [ ] Sei explicar os dois `for` usados para percorrer a sala.
- [ ] Sei acessar um assento por `sala[linha][coluna]`.
- [ ] Sei explicar como uma reserva transforma `0` em `1`.
- [ ] Sei validar linha e coluna antes de acessar a matriz.
- [ ] Sei verificar se um assento já está ocupado.
- [ ] Sei explicar o papel do `do...while`.
- [ ] Sei explicar o funcionamento do `switch`.
- [ ] Sei explicar a função do `break`.
- [ ] Sei contabilizar assentos livres e ocupados.
- [ ] Consigo explicar o caminho do programa do início ao fim.
## 20. Revisão rápida
| Parte | Lógica |
| --- | --- |
| Sala | `int sala[10][20]` |
| Livre | `0` |
| Ocupado | `1` |
| Inicializar | preencher toda matriz com `0` |
| Visualizar | percorrer e imprimir |
| Reservar | `sala[linha][coluna] = 1` |
| Validar posição | linha `0–9` e coluna `0–19` |
| Contabilizar | percorrer matriz e incrementar contadores |
| Menu | `switch` dentro de `do...while` |
| Sair | encerrar repetição do menu |
