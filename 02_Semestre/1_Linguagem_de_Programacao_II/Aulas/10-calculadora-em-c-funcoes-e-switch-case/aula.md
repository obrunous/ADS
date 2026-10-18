# Aula 10 - Calculadora em C: funções e switch case

**Data:** 05/10/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3b6d0f04d53981979d9ffd036a44c95f)

## Calculadora em C: funções e switch case
**Aula de estudo — Dia 10 — 05/10/2026**
Material baseado na calculadora desenvolvida nesta conversa e nos arquivos locais. Explicação para iniciante; não representa transcrição nem validação do professor.
### 1. O que vamos aprender
- Criar funções que recebem dois números e devolvem um resultado.
- Entender parâmetros, argumentos, tipo de retorno e chamada de função.
- Selecionar uma operação com `switch`, `case` e `break`.
- Separar o programa em arquivos `.c` e `.h`.
- Ler entradas, evitar divisão por zero e compilar os arquivos juntos.
### 2. Primeiro, a ideia da calculadora
A calculadora recebe uma escolha e dois números. A escolha determina a conta: soma, subtração, multiplicação ou divisão. Depois, o programa mostra o resultado com duas casas decimais e termina. Nesta versão, ele faz uma operação por execução.
Com os números 8 e 2, temos: 8 + 2 = 10; 8 − 2 = 6; 8 × 2 = 16; 8 ÷ 2 = 4. Na divisão, o segundo número é o divisor e não pode ser zero.
O caminho é: mostrar menu → ler opção → verificar se está entre 1 e 4 → ler números → entrar no case escolhido → calcular → guardar resultado → mostrar resultado. No case 4, verificar o divisor antes de calcular.
### 3. O que é uma função?
Uma função é um trecho de código com nome e uma tarefa definida. Podemos chamá-la quando precisamos daquela tarefa.
```c
float somar(float a, float b) {
    return a + b;
}
```
Leia essa função por partes:
- O primeiro `float` indica que ela devolve um número que pode ter casas decimais.
- `somar` é o nome da função.
- `float a, float b` são os parâmetros: variáveis que recebem os valores usados na conta.
- As chaves delimitam o corpo da função.
- `return a + b;` calcula a soma, devolve o valor e encerra essa chamada da função.
#### Parâmetros e argumentos
```c
resultado = somar(numero1, numero2);
```
`numero1` e `numero2` são os argumentos enviados na chamada. Dentro da função, seus valores são recebidos em `a` e `b`. Se `numero1` vale 8 e `numero2` vale 2, a função recebe `a = 8` e `b = 2`, devolve 10 e esse valor é guardado em `resultado`.
Neste exemplo, os números são passados por valor: a função recebe cópias. Alterar `a` dentro dela não altera automaticamente `numero1` na `main`.
A função de soma não imprime nada. Ela calcula e retorna; a `main` cuida de mostrar o resultado.
### 4. Organização dos arquivos
```text
linguagem_programacao_2/
    calculadora.c
    minhas_funcoes/
        operacoes.h
        operacoes.c
```
**calculadora.c:** contém a `main`, o menu, as leituras, as verificações e a escolha da operação.
**operacoes.h:** declara as funções, informando seus nomes, parâmetros e tipos de retorno.
**operacoes.c:** define as funções, ou seja, contém os cálculos.
A declaração informa como chamar a função; a definição informa o que ela faz.
### 5. Cabeçalho completo — minhas_funcoes/operacoes.h
```c
#ifndef OPERACOES_H
#define OPERACOES_H

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

#endif
```
Cada linha terminada em ponto e vírgula é um protótipo. Por exemplo, `float somar(float a, float b);` anuncia uma função chamada `somar` que recebe dois `float` e devolve um `float`.
`#ifndef OPERACOES_H`, `#define OPERACOES_H` e `#endif` formam uma proteção para que o conteúdo do cabeçalho não seja processado repetidamente na mesma unidade de compilação. São instruções do pré-processador e não precisam de ponto e vírgula.
### 6. Funções completas — minhas_funcoes/operacoes.c
```c
#include "operacoes.h"

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}
```
`#include "operacoes.h"` inclui as declarações do cabeçalho que está na mesma pasta.
As quatro funções seguem a mesma estrutura. Mudam o nome e o operador: `+`, `-`, `*` e `/`.
Na subtração e na divisão, a ordem importa: `a - b` não é, em geral, igual a `b - a`.
A função `dividir` pressupõe que o divisor seja diferente de zero. Nesta calculadora, a verificação ocorre na `main`, antes da chamada.
### 7. Programa principal completo — calculadora.c
```c
#include <stdio.h>
#include "minhas_funcoes/operacoes.h"

int main(void) {
    int opcao;
    float numero1, numero2, resultado;

    printf("=== CALCULADORA ===\n");
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
        printf("Opcao invalida!\n");
        return 1;
    }

    printf("Digite o primeiro numero: ");
    scanf("%f", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%f", &numero2);

    switch (opcao) {
        case 1:
            resultado = somar(numero1, numero2);
            break;
        case 2:
            resultado = subtrair(numero1, numero2);
            break;
        case 3:
            resultado = multiplicar(numero1, numero2);
            break;
        case 4:
            if (numero2 == 0) {
                printf("Nao e possivel dividir por zero!\n");
                return 0;
            }
            resultado = dividir(numero1, numero2);
            break;
        default:
            printf("Opcao invalida!\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
```
### 8. Entendendo a main por trechos
#### Bibliotecas e ponto de entrada
`#include <stdio.h>` fornece as declarações de funções de entrada e saída, como `printf` e `scanf`.
`#include "minhas_funcoes/operacoes.h"` inclui nosso cabeçalho, usando o caminho relativo à pasta de `calculadora.c`.
`int main(void)` é o ponto de entrada do programa. `void` indica que essa forma de `main` não recebe parâmetros, e `int` indica o tipo do código devolvido ao sistema.
#### Variáveis
`int opcao;` guarda um número inteiro, como 1 ou 4.
`float numero1, numero2, resultado;` cria três variáveis para valores que podem ter casas decimais.
As variáveis não recebem um valor inicial nessa declaração. Nesta versão simples, pressupomos que o usuário digite números válidos: o retorno do scanf não é verificado. Se uma leitura falhar, uma variável pode continuar sem valor definido. Cada case válido atribui resultado antes da impressão.
#### Menu e leitura
`printf` mostra texto; `\n` muda de linha. A leitura ficou separada das condições:
```c
scanf("%d", &opcao);

if (opcao < 1 || opcao > 4) {
    printf("Opcao invalida!\n");
    return 1;
}

printf("Digite o primeiro numero: ");
scanf("%f", &numero1);

printf("Digite o segundo numero: ");
scanf("%f", &numero2);
```
`%d` lê um inteiro; `%f` lê um float. O `&` fornece o endereço da variável para guardar o valor.
O símbolo `||` significa “ou”. Se a opção for menor que 1 ou maior que 4, o programa mostra a mensagem e termina antes de pedir os dois números. Por exemplo, 5 é inválido; 1 e 4 são válidos.
Esta versão não testa se scanf conseguiu ler. Não existe mais a mensagem `Numero invalido!`. Digite números decimais com ponto, como `2.5`. Letras podem causar falha de leitura e comportamento indefinido; não há saída confiável prevista para elas.
#### Proteção da divisão dentro do case 4
```c
case 4:
    if (numero2 == 0) {
        printf("Nao e possivel dividir por zero!\n");
        return 0;
    }
    resultado = dividir(numero1, numero2);
    break;
```
Já estamos no case da divisão, por isso basta comparar `numero2 == 0`. O operador `==` compara valores.
Se o divisor for zero, a mensagem aparece e return encerra a main. Não chama dividir nem imprime Resultado.
Se o divisor não for zero, chama dividir, guarda o valor e sai do switch pelo break.
Nesta versão, divisão por zero termina com código 0; opção numérica fora do menu termina com código 1.
#### Escolha com switch case
`switch (opcao)` examina a opção. O `case 1` chama a soma; o `case 2`, a subtração; o `case 3`, a multiplicação; e o `case 4`, a divisão.
```c
case 1:
    resultado = somar(numero1, numero2);
    break;
```
O `=` guarda o valor retornado em `resultado`. O `break` sai do `switch` e continua o programa depois dele. Sem `break`, a execução pode continuar nos próximos casos e substituir o resultado.
O `default` trata uma opção sem caso correspondente. Aqui é uma proteção adicional: a validação inicial já restringe a opção a 1, 2, 3 ou 4.
**Diferença essencial:** `break` sai do `switch`; `return` sai da função em execução.
#### Saída
```c
printf("Resultado: %.2f\n", resultado);
```
`%.2f` mostra o valor com duas casas decimais. A formatação arredonda a apresentação, mas não transforma o valor armazenado em um número com apenas duas casas.
Há um único `printf` de resultado, compartilhado pelas quatro operações. Por fim, `return 0;` encerra a execução normal.
### 9. Simulação passo a passo
Exemplo: escolher multiplicação e informar 8 e 2.
1. O programa imprime o menu.
2. A leitura guarda 3 em `opcao`.
3. A verificação confirma que 3 está entre 1 e 4.
4. As próximas leituras guardam 8 em `numero1` e 2 em `numero2`.
5. O `switch` entra no `case 3`.
6. `multiplicar(numero1, numero2)` recebe cópias dos valores: `a = 8` e `b = 2`.
7. `return a * b;` devolve 16.
8. A `main` guarda 16 em `resultado`.
9. O `break` sai do `switch`.
10. O programa imprime `Resultado: 16.00` e termina.
#### Exemplo no terminal
Os valores 3, 8 e 2 abaixo são digitados pelo usuário:
```text
=== CALCULADORA ===
1 - Somar
2 - Subtrair
3 - Multiplicar
4 - Dividir
Escolha uma opcao: 3
Digite o primeiro numero: 8
Digite o segundo numero: 2
Resultado: 16.00
```
### 10. Compilação e o erro encontrado na aula
Ao compilar apenas `calculadora.c`, apareceram mensagens como `Undefined symbols for architecture x86_64`, citando `_somar`, `_subtrair`, `_multiplicar` e `_dividir`.
O cabeçalho informa que as funções existem, mas não fornece seus corpos. O ligador precisa encontrar as definições de `operacoes.c` para montar o executável. A menção a x86_64, neste caso, não significa que o processador seja o problema.
#### Comando correto no Terminal
```bash
cd ~/Documents/linguagem_programacao_2
gcc -Wall -Wextra -g3 calculadora.c minhas_funcoes/operacoes.c -o output/calculadora
./output/calculadora
```
`gcc` chama o compilador; `-Wall -Wextra` ativa avisos; `-g3` adiciona informações para depuração; os dois caminhos `.c` fornecem o programa e as operações; `-o output/calculadora` define o executável na pasta output já existente.
O arquivo `.h` é incluído pelos fontes. Não é necessário passá-lo como um programa separado para compilar.
Não inclua `operacoes.c` no lugar do cabeçalho como solução para esse erro: mantenha o `#include` do `.h` e compile os dois `.c`.
#### Configuração usada no VS Code
Foi criada a configuração local `.vscode/settings.json` para a extensão instalada C/C++ Compile Run:
```json
{
    "c-cpp-compile-run.c-linker-flags": "/Users/brunoalves/Documents/linguagem_programacao_2/minhas_funcoes/operacoes.c",
    "c-cpp-compile-run.skip-if-compiled": false
}
```
Abra a pasta `linguagem_programacao_2` no VS Code, selecione `calculadora.c` e use **C/C++: Compile & Run**.
O caminho dessa configuração é específico deste computador. A recompilação foi ativada em toda execução para considerar também alterações nas funções.
A compilação pelo terminal foi verificada sem erros ou avisos após a alteração para `switch case`. O funcionamento do botão do VS Code após a configuração ainda depende da confirmação do usuário.
### 11. Exercícios de prática
Execute o programa novamente a cada caso. Os resultados abaixo são os esperados para conferência.
- [ ] Soma: opção 1, números 8 e 2 → `Resultado: 10.00`.
- [ ] Subtração: opção 2, números 8 e 2 → `Resultado: 6.00`.
- [ ] Multiplicação: opção 3, números 8 e 2 → `Resultado: 16.00`.
- [ ] Divisão: opção 4, números 8 e 2 → `Resultado: 4.00`.
- [ ] Divisão com decimais: opção 4, números 5 e 2 → `Resultado: 2.50`.
- [ ] Divisão por zero: opção 4, números 8 e 0 → `Nao e possivel dividir por zero!`.
- [ ] Opção 9 → `Opcao invalida!`.
- [ ] Explicar por que letras não são tratadas nesta versão: scanf direto não verifica falha de leitura.
#### Perguntas para responder sem consultar
1. Qual a diferença entre parâmetro e argumento?
2. O que a função `somar` devolve quando recebe 4 e 5?
3. Por que usamos `float` nos números e `int` na opção?
4. O que acontece se retirarmos o `break` do primeiro caso?
5. Qual a diferença entre `=` e `==`?
6. Por que incluir o cabeçalho não resolve sozinho a ligação das funções?
7. Em qual trecho a divisão por zero é impedida?
#### Respostas para conferir depois
1. Parâmetro é a variável declarada na função; argumento é o valor ou expressão enviado na chamada.
2. Devolve 9. Se esse resultado for impresso com `%.2f`, aparece `9.00`.
3. A opção representa uma escolha inteira; os números das operações podem ter casas decimais.
4. A execução continua no caso 2, faz a subtração e substitui o resultado antes de encontrar o próximo `break`.
5. `=` atribui um valor; `==` compara dois valores.
6. O cabeçalho traz declarações. As definições estão no outro `.c`, que também precisa participar da compilação.
7. No `if (numero2 == 0)` dentro do `case 4`, antes de chamar `dividir`.
### 12. Teste de mesa do código atual
Teste de mesa é acompanhar manualmente as variáveis e as decisões. Depois, execute e compare com a previsão. Cada execução faz uma única operação.
#### Soma: opção 1, números 8 e 2
| Etapa | opcao | numero1 | numero2 | resultado | Ação |
| --- | --- | --- | --- | --- | --- |
| Declarações | Indefinida | Indefinido | Indefinido | Indefinido | Ainda não houve leitura |
| Ler opção | 1 | — | — | — | 1 está no intervalo válido |
| Ler números | 1 | 8 | 2 | — | Valores armazenados |
| case 1 | 1 | 8 | 2 | — | somar recebe a = 8 e b = 2 |
| Retorno | 1 | 8 | 2 | 10 | A função devolve 10 |
| break | 1 | 8 | 2 | 10 | Sai do switch |
| printf | 1 | 8 | 2 | 10 | Resultado: 10.00 |
O traço significa que o valor ainda não foi atribuído. As variáveis locais a e b pertencem à função chamada.
#### Opção 5: encerrar antes de pedir números
1. scanf guarda 5 em opcao.
2. A condição “menor que 1 ou maior que 4” é verdadeira.
3. Imprime `Opcao invalida!`.
4. return 1 encerra a main. Os números não são solicitados e o switch não é alcançado.
#### Divisão por zero: opção 4, números 8 e 0
1. A opção 4 é aceita.
2. numero1 recebe 8 e numero2 recebe 0.
3. O switch entra no case 4.
4. numero2 == 0 é verdadeiro.
5. Imprime `Nao e possivel dividir por zero!`.
6. return 0 encerra a main. Não calcula nem imprime Resultado.
#### Casos para executar e comparar
Os resultados abaixo são esperados, não representam testes já realizados por você. Existem infinitas combinações numéricas; esta seleção cobre as quatro operações, zeros, sinais, decimais e opções fora do menu.
| Caso | Opção | Primeiro | Segundo | Saída final esperada |
| --- | --- | --- | --- | --- |
| Soma | 1 | 8 | 2 | Resultado: 10.00 |
| Subtração | 2 | 8 | 2 | Resultado: 6.00 |
| Multiplicação | 3 | 8 | 2 | Resultado: 16.00 |
| Divisão | 4 | 8 | 2 | Resultado: 4.00 |
| Soma com zero | 1 | 0 | 5 | Resultado: 5.00 |
| Dois zeros | 1 | 0 | 0 | Resultado: 0.00 |
| Zero menos positivo | 2 | 0 | 5 | Resultado: -5.00 |
| Subtrair zero | 2 | 5 | 0 | Resultado: 5.00 |
| Multiplicar por zero | 3 | 5 | 0 | Resultado: 0.00 |
| Zero multiplicado | 3 | 0 | 5 | Resultado: 0.00 |
| Zero dividido | 4 | 0 | 5 | Resultado: 0.00 |
| Divisor zero | 4 | 5 | 0 | Nao e possivel dividir por zero! |
| Zero por zero | 4 | 0 | 0 | Nao e possivel dividir por zero! |
| Soma negativa | 1 | -8 | 2 | Resultado: -6.00 |
| Dois negativos | 1 | -8 | -2 | Resultado: -10.00 |
| Subtração negativa | 2 | 2 | 8 | Resultado: -6.00 |
| Subtrair negativo | 2 | -8 | -2 | Resultado: -6.00 |
| Produto negativo | 3 | -8 | 2 | Resultado: -16.00 |
| Produto positivo | 3 | -8 | -2 | Resultado: 16.00 |
| Quociente negativo | 4 | -8 | 2 | Resultado: -4.00 |
| Quociente positivo | 4 | -8 | -2 | Resultado: 4.00 |
| Soma decimal | 1 | 2.5 | 1.5 | Resultado: 4.00 |
| Subtração decimal | 2 | 5.75 | 2.25 | Resultado: 3.50 |
| Produto decimal | 3 | 2.5 | 3 | Resultado: 7.50 |
| Divisão decimal | 4 | 5 | 2 | Resultado: 2.50 |
| Arredondamento | 4 | 1 | 3 | Resultado: 0.33 |
| Arredondamento | 4 | 2 | 3 | Resultado: 0.67 |
| Valor pequeno | 4 | 1 | 1000 | Resultado: 0.00 |
| Opção inválida | 0 | Não solicitado | Não solicitado | Opcao invalida! |
| Opção inválida | 5 | Não solicitado | Não solicitado | Opcao invalida! |
| Opção inválida | -1 | Não solicitado | Não solicitado | Opcao invalida! |
| Opção inválida | 100 | Não solicitado | Não solicitado | Opcao invalida! |
Na divisão 1 por 1000, o valor é aproximadamente 0.001, mas a exibição com duas casas resulta em 0.00.
#### Limites das entradas
- Letras na opção ou nos números: leitura pode falhar e deixar variável sem valor definido. Não prever mensagem de erro.
- Decimal com vírgula, como 2,5: pode ler só o 2 e deixar a vírgula para a leitura seguinte.
- 3.5 na opção: pode ler 3 como opção e deixar .5 para a próxima leitura.
- 2abc em um número: pode ler 2 e deixar abc na entrada.
- Apenas Enter: scanf continua aguardando um valor.
Para esta prática inicial, use inteiros na opção e números com ponto nas casas decimais.
#### Meu registro
- [ ] Previ o resultado antes de executar.
- [ ] Executei as quatro operações.
- [ ] Testei divisão por zero.
- [ ] Confirmei que a opção 5 não pede os números.
- [ ] Comparei negativos e decimais com a tabela.
### 13. Revisão e anotações
- [ ] Consigo explicar uma função usando entrada, cálculo e retorno.
- [ ] Consigo acompanhar a execução de um `case`.
- [ ] Sei a responsabilidade de cada um dos três arquivos.
- [ ] Consigo compilar os dois fontes no Terminal.
- [ ] Testei a execução pelo botão do VS Code.
- [ ] Consigo explicar o erro de ligação que apareceu.
**Minhas dúvidas:** espaço para registrar dúvidas durante a revisão.
**Orientações do professor:** espaço para acrescentar as orientações dadas em aula.
**Próxima prática sugerida:** refazer apenas a função de soma e explicar sua chamada antes de reconstruir as outras operações.
