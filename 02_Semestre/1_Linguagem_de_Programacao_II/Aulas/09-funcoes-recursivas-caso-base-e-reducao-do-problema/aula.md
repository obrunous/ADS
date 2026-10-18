# Aula 09 - Funções Recursivas: Caso Base e Redução do Problema

**Data:** 28/09/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3b6d0f04d53981af9a7eedaa4e7294cc)

## Aula 9 — Funções Recursivas em C
> **Objetivo:** entender recursividade começando do zero, sem decorar código.
> Ideia principal: **uma função recebe dados, faz um trabalho e pode devolver um resultado. Uma função recursiva chama ela mesma até chegar a um ponto de parada.**
### 1. Primeiro: o que é uma função?
Uma função é um bloco de código criado para realizar uma tarefa.
Pense sempre assim:
**ENTRADA → PROCESSAMENTO → SAÍDA**
Exemplo simples:
```c
int somar(int n1, int n2)
{
    return n1 + n2;
}
```
#### Lendo a função
```text
int somar(int n1, int n2)

int          -> tipo do valor que será devolvido
somar        -> nome da função
n1 e n2      -> parâmetros
return       -> devolve o resultado
```
Se fizermos:
```c
resultado = somar(3, 4);
```
o computador entende:
```text
n1 = 3
n2 = 4

3 + 4 = 7

return 7

resultado = 7
```
### 2. O que é o `main`?
O `main` também é uma função.
É por ele que o programa começa.
```c
int main(void)
{
    return 0;
}
```
Quando o `main` chama outra função:
```text
main
  |
  | chama a função
  v
função
  |
  | devolve o resultado
  v
main
```
### 3. O que é o protótipo?
Exemplo:
```c
int somar(int n1, int n2);
```
O protótipo avisa ao compilador:
```text
Existe uma função chamada somar.
Ela recebe dois inteiros.
Ela devolve um inteiro.
```
### 4. Variável local e variável global
Antes da recursividade, é importante entender **onde uma variável existe** no programa.
#### Variável local
Uma variável local é declarada **dentro de uma função ou bloco**.
Exemplo:
```c
#include <stdio.h>

int main(void)
{
    int numero = 10;

    printf("%d\n", numero);

    return 0;
}
```
A variável `numero` é local do `main`.
Ela existe apenas dentro do `main`.
#### Outro exemplo com função
```c
int somar(int n1, int n2)
{
    int resultado;

    resultado = n1 + n2;

    return resultado;
}
```
Aqui:
- `n1` é local da função `somar`;
- `n2` é local da função `somar`;
- `resultado` também é local da função `somar`.
O `main` não pode acessar diretamente essa variável `resultado`.
#### Variável global
Uma variável global é declarada **fora de todas as funções**.
Exemplo:
```c
#include <stdio.h>

int numero = 10;

void mostrarNumero(void)
{
    printf("%d\n", numero);
}

int main(void)
{
    mostrarNumero();

    printf("%d\n", numero);

    return 0;
}
```
A variável `numero` foi declarada fora do `main` e fora de `mostrarNumero`.
Por isso, ela pode ser usada pelas funções desse arquivo a partir do ponto em que foi declarada.
> Em C, o termo técnico mais comum é **variável global**. Às vezes alguém pode dizer informalmente "variável pública", mas C não usa `public` e `private` para variáveis comuns como linguagens orientadas a objetos.
#### Comparação simples
| Tipo | Onde é declarada? | Onde pode ser usada? |
| --- | --- | --- |
| Local | Dentro de uma função ou bloco | Somente naquele escopo |
| Global | Fora das funções | Nas funções que estejam no escopo da declaração |
#### Exemplo para enxergar a diferença
```c
#include <stdio.h>

int global = 100;

void teste(void)
{
    int local = 20;

    printf("Global: %d\n", global);
    printf("Local: %d\n", local);
}

int main(void)
{
    teste();

    printf("Global no main: %d\n", global);

    return 0;
}
```
Observe:
```text
global = pode ser acessada em teste() e main()

local = só existe dentro de teste()
```
#### Regra mental
```text
Dentro da função  -> variável local

Fora das funções  -> variável global
```
---
### 5. Agora sim: o que é recursividade?
Recursividade acontece quando uma função **chama ela mesma**.
Exemplo:
```c
int contagem(int numero)
{
    if (numero == 0)
    {
        return 0;
    }

    return contagem(numero - 1);
}
```
Para `contagem(3)`:
```text
contagem(3)
    contagem(2)
        contagem(1)
            contagem(0)
```
> Para entender qualquer função recursiva, procure duas coisas:
> 1. **Caso base / ponto de parada** — onde a função para.
> 2. **Passo recursivo** — onde a função chama ela mesma com um problema menor.
---
## Exemplo da aula — Fatorial
Fatorial significa multiplicar um número pelos anteriores até 1.
```text
5! = 5 × 4 × 3 × 2 × 1
5! = 120
```
Podemos enxergar assim:
```text
5! = 5 × 4!
4! = 4 × 3!
3! = 3 × 2!
2! = 2 × 1!
1! = 1
```
#### Função apresentada na aula
```c
int calcFatorial(int numero)
{
    int x;

    if (numero == 1)
    {
        return 1;
    }
    else
    {
        x = numero * calcFatorial(numero - 1);
        return x;
    }
}
```
#### O que acontece com `calcFatorial(5)`
```text
calcFatorial(5)

5 × calcFatorial(4)

5 × 4 × calcFatorial(3)

5 × 4 × 3 × calcFatorial(2)

5 × 4 × 3 × 2 × calcFatorial(1)

5 × 4 × 3 × 2 × 1

120
```
#### Identificando as partes
**Caso base:**
```c
if (numero == 1)
{
    return 1;
}
```
**Passo recursivo:**
```c
x = numero * calcFatorial(numero - 1);
```
#### Programa completo
```c
#include <stdio.h>

int calcFatorial(int numero);

int main(void)
{
    int numero, resultado;

    printf("Informe numero: ");
    scanf("%d", &numero);

    resultado = calcFatorial(numero);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int calcFatorial(int numero)
{
    int x;

    if (numero == 1)
    {
        return 1;
    }
    else
    {
        x = numero * calcFatorial(numero - 1);
        return x;
    }
}
```
---
## Exercício 2 — Multiplicar dois números usando soma
Objetivo: multiplicar usando **somas sucessivas**.
Exemplo do quadro:
```text
3 × 4

3 + 3 + 3 + 3

12
```
#### Função
```c
int multiplicar(int n1, int n2)
{
    if (n2 == 0)
    {
        return 0;
    }

    return n1 + multiplicar(n1, n2 - 1);
}
```
#### Passo a passo
```text
multiplicar(3, 4)

3 + multiplicar(3, 3)

3 + 3 + multiplicar(3, 2)

3 + 3 + 3 + multiplicar(3, 1)

3 + 3 + 3 + 3 + multiplicar(3, 0)

3 + 3 + 3 + 3 + 0

12
```
**Caso base:**
```c
n2 == 0
```
**Passo recursivo:**
```c
n1 + multiplicar(n1, n2 - 1)
```
#### Programa completo
```c
#include <stdio.h>

int multiplicar(int n1, int n2);

int main(void)
{
    int n1, n2, resultado;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);

    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    resultado = multiplicar(n1, n2);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int multiplicar(int n1, int n2)
{
    if (n2 == 0)
    {
        return 0;
    }

    return n1 + multiplicar(n1, n2 - 1);
}
```
---
## Exercício 3 — Somar todos os números entre 1 e N
Se o usuário digitar `4`:
```text
1 + 2 + 3 + 4 = 10
```
Na recursão podemos pensar:
```text
4 + 3 + 2 + 1
```
#### Função
```c
int somaRecursiva(int numero)
{
    if (numero == 1)
    {
        return 1;
    }

    return numero + somaRecursiva(numero - 1);
}
```
#### Passo a passo
```text
somaRecursiva(4)

4 + somaRecursiva(3)

4 + 3 + somaRecursiva(2)

4 + 3 + 2 + somaRecursiva(1)

4 + 3 + 2 + 1

10
```
**Caso base:**
```c
numero == 1
```
**Passo recursivo:**
```c
numero + somaRecursiva(numero - 1)
```
#### Programa completo
```c
#include <stdio.h>

int somaRecursiva(int numero);

int main(void)
{
    int numero, resultado;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    resultado = somaRecursiva(numero);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int somaRecursiva(int numero)
{
    if (numero == 1)
    {
        return 1;
    }

    return numero + somaRecursiva(numero - 1);
}
```
---
## Exercício 4 — Potência
Objetivo: receber dois números e calcular a potência do primeiro pelo segundo.
Exemplo do quadro:
```text
a = 3
b = 4

3⁴ = 3 × 3 × 3 × 3

81
```
#### Função
```c
int potencia(int base, int expoente)
{
    if (expoente == 0)
    {
        return 1;
    }

    return base * potencia(base, expoente - 1);
}
```
#### Passo a passo
```text
potencia(3, 4)

3 × potencia(3, 3)

3 × 3 × potencia(3, 2)

3 × 3 × 3 × potencia(3, 1)

3 × 3 × 3 × 3 × potencia(3, 0)

3 × 3 × 3 × 3 × 1

81
```
**Caso base:**
```c
expoente == 0
```
**Passo recursivo:**
```c
base * potencia(base, expoente - 1)
```
#### Programa completo
```c
#include <stdio.h>

int potencia(int base, int expoente);

int main(void)
{
    int base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int potencia(int base, int expoente)
{
    if (expoente == 0)
    {
        return 1;
    }

    return base * potencia(base, expoente - 1);
}
```
---
## Exercício 5 — Fibonacci usando recursividade
A sequência de Fibonacci:
```text
0, 1, 1, 2, 3, 5, 8, 13, 21...
```
Cada número é a soma dos dois anteriores.
```text
1 + 1 = 2
1 + 2 = 3
2 + 3 = 5
3 + 5 = 8
```
#### Função
```c
int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
Nesse exemplo:
```text
1º termo = 0
2º termo = 1
3º termo = 1
4º termo = 2
5º termo = 3
...
15º termo = 377
```
#### Exemplo pequeno
```text
fibonacci(5)

fibonacci(4) + fibonacci(3)

2 + 1

3
```
**Casos base:**
```c
n == 1
n == 2
```
**Passo recursivo:**
```c
fibonacci(n - 1) + fibonacci(n - 2)
```
#### Programa completo — 15º termo
```c
#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    int termo = 15;
    int resultado;

    resultado = fibonacci(termo);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int fibonacci(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
---
## O padrão dos exercícios
| Problema | Caso base | Como fica menor? |
| --- | --- | --- |
| Fatorial | `numero == 1` | `numero - 1` |
| Multiplicação | `n2 == 0` | `n2 - 1` |
| Soma 1 até N | `numero == 1` | `numero - 1` |
| Potência | `expoente == 0` | `expoente - 1` |
| Fibonacci | `n == 1` ou `n == 2` | `n - 1` e `n - 2` |
### Como pensar antes de programar
Sempre responda estas perguntas:
1. O que entra na função?
2. O que deve sair da função?
3. Qual é o menor caso possível?
4. Qual é o ponto de parada?
5. Como transformar o problema em um problema menor?
6. Onde a função chama ela mesma?
### Ordem de estudo recomendada
- [ ] Entender `main`
- [ ] Entender função
- [ ] Entender parâmetros
- [ ] Entender `return`
- [ ] Entender protótipo
- [ ] Entender chamada de função
- [ ] Identificar caso base
- [ ] Acompanhar recursão no papel
- [ ] Escrever recursão
> **Resumo final:** recursividade não é um código diferente ou mágico. É apenas uma função normal que chama ela mesma com valores menores até alcançar uma condição que encerra as chamadas.
### Revisão prática
Faça no papel, sem computador:
```text
calcFatorial(4)
multiplicar(3, 4)
somaRecursiva(4)
potencia(3, 4)
fibonacci(5)
```
Expanda as chamadas uma por uma até encontrar o caso base.
