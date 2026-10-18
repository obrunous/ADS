# Aula 06 - Funções em C: Parâmetros, Retorno e Modularização

**Data da aula:** 31/08/2026

**Referência da disciplina:** [Página no Notion](https://app.notion.com/p/3b6d0f04d53981c093c8f2212afc727b).

**Base desta versão:** exercícios 001 a 006 construídos nesta conversa. Este material registra nossa prática e as dúvidas discutidas; não é uma transcrição da aula do professor. A página do Notion não foi alterada.

## 1. O que estamos aprendendo

Uma função é um bloco de código com nome, criado para realizar uma tarefa. Nos exercícios, separamos o programa em partes:

- A `main` lê os dados, chama as funções e coordena as decisões.
- As funções de cálculo recebem valores e devolvem resultados.
- As funções de exibição recebem valores e mostram mensagens.

Nosso percurso foi:

| Exercício | Tema                       | Aprendizado principal                                        |
| ---------- | -------------------------- | ------------------------------------------------------------ |
| 001        | Positivo, negativo ou zero | Receber um inteiro e retornar uma classificação            |
| 002        | Maioridade                 | Validar a entrada e interpretar um retorno lógico           |
| 003        | Média e aprovação       | Combinar validação, cálculo e decisão em três funções |
| 004        | IMC                        | Diferenciar função com retorno de função `void`        |
| 005        | Identificação por letra  | Receber `char` e exibir mensagens dentro da função       |
| 006        | Calculadora                | Selecionar e chamar quatro funções de cálculo             |

## 2. Entrada, processamento e saída de uma função

Observe o cálculo do IMC:

```c
float calcularIMC(float peso, float altura){
    return peso / (altura * altura);
}
```

- **Entrada:** os parâmetros `peso` e `altura`.
- **Processamento:** dividir o peso pela altura ao quadrado.
- **Saída:** o número decimal devolvido pelo `return`.

Exemplo: recebe `80` e `2`, calcula `80 / (2 * 2)` e retorna `20.0`.

Essa função não mostra o resultado na tela. A saída de uma função pode ser um valor retornado para outro trecho do programa. Para aparecer na tela, precisamos de `printf`.

## 3. Como ler a definição de uma função

```c
int classificarNumero(int numero){
    if(numero > 0){
        return 1;
    } else if(numero < 0){
        return -1;
    } else {
        return 0;
    }
}
```

Em `int classificarNumero(int numero)`:

- O primeiro `int` é o tipo do valor devolvido.
- `classificarNumero` é o nome da função.
- `int numero` declara o parâmetro recebido.
- As chaves contêm o funcionamento da função.

O tipo do retorno e o tipo do parâmetro têm papéis diferentes. Escrever apenas `classificarNumero(numero)` na definição omite o tipo do parâmetro.

## 4. Argumentos, parâmetros e cópia dos valores — exercício 001

Na `main`, usamos um nome diferente para enxergar a passagem do valor:

```c
int a;
int resultado;

printf("Informe um numero inteiro:\n");
scanf("%d", &a);

resultado = classificarNumero(a);
```

`a` é o argumento usado na chamada. `numero` é o parâmetro da função. Eles não precisam ter o mesmo nome.

Ao digitar `-8`, acontece:

1. A variável `a`, da `main`, recebe `-8`.
2. A chamada passa uma cópia desse valor para `numero`.
3. A função verifica que `numero < 0` e retorna `-1`.
4. A variável `resultado`, da `main`, recebe `-1`.

```text
a = -8 → classificarNumero(a) → numero = -8 → return -1 → resultado = -1
```

`numero` pertence à função. Alterar esse parâmetro não altera automaticamente `a`.

Os retornos `1`, `-1` e `0` são uma convenção deste exercício. A função devolve um código que a `main` interpreta:

```c
if(resultado == 1){
    printf("POSITIVO\n");
} else if(resultado == -1){
    printf("NEGATIVO\n");
} else {
    printf("ZERO\n");
}
```

## 5. Protótipo, implementação e chamada

São três coisas diferentes:

```c
/* Protótipo: apresenta a função. */
int classificarNumero(int numero);
```

```c
/* Implementação: define o funcionamento. */
int classificarNumero(int numero){
    if(numero > 0){
        return 1;
    } else if(numero < 0){
        return -1;
    } else {
        return 0;
    }
}
```

```c
/* Chamada: executa a função com um argumento. */
resultado = classificarNumero(a);
```

O protótipo termina em `;`. A implementação possui corpo entre chaves.

O compilador precisa conhecer a declaração da função antes da chamada. No mesmo arquivo, podemos definir a função inteira antes da `main`, dispensando um protótipo separado. Se a definição vier depois da `main`, declaramos o protótipo antes dela.

## 6. Separação em arquivos `.h` e `.c`

Nos exercícios, passamos a usar:

```text
pasta-do-exercicio/
├── prototypes.h
├── implementation.c
└── main.c
```

O nome da implementação também apareceu como `implementations.c`. No exercício 001, escolhemos os nomes mais descritivos `function_prototypes.h` e `function_implementations.c`. Os nomes podem variar; os caminhos nos `#include` e no comando de compilação precisam corresponder aos arquivos reais.

| Arquivo              | Responsabilidade                                        |
| -------------------- | ------------------------------------------------------- |
| `prototypes.h`     | Declarar os nomes, parâmetros e retornos das funções |
| `implementation.c` | Implementar o funcionamento das funções               |
| `main.c`           | Receber dados e coordenar a execução                  |

Na `main` e na implementação, incluímos o cabeçalho:

```c
#include "prototypes.h"
```

Isso apresenta as declarações e permite verificar sua compatibilidade com as definições. Usamos `#include <stdio.h>` nos arquivos que chamam `printf` ou `scanf`.

A ordem recomendada para estudar é: escrever o protótipo, implementar a função e depois construir a `main`. É uma organização de trabalho, não uma obrigação da linguagem.

## 7. Validar antes de chamar — exercício 002

A função de maioridade recebe uma idade e retorna `1` para maior de idade ou `0` para menor:

```c
int ehMaiorDeIdade(int idade){
    if(idade >= 18){
        return 1;
    } else {
        return 0;
    }
}
```

Na `main`, a idade negativa é rejeitada antes da chamada:

```c
if(idade < 0){
    printf("Idade invalida!\n");
} else {
    resultado = ehMaiorDeIdade(idade);

    if(resultado == 1){
        printf("Maior de idade.\n");
    } else {
        printf("Menor de idade.\n");
    }
}
```

Comparar `idade == 1` significa perguntar se a pessoa tem um ano. Comparar `resultado == 1` significa verificar a resposta da função.

Também podemos chamar diretamente na condição:

```c
if(idade < 0){
    printf("Idade invalida!\n");
} else if(ehMaiorDeIdade(idade) == 1){
    printf("Maior de idade.\n");
} else {
    printf("Menor de idade.\n");
}
```

As duas formas funcionam. Guardar em `resultado` deixa as etapas explícitas e permite reutilizar o retorno. A chamada direta é mais curta. Em ambas, a idade negativa impede a chamada.

## 8. Três funções trabalhando juntas — exercício 003

Usamos uma função para cada responsabilidade:

```c
int notaValida(float nota){
    if(nota >= 0 && nota <= 10){
        return 1;
    } else {
        return 0;
    }
}

float calcularMedia(float nt1, float nt2, float nt3, float nt4){
    return (nt1 + nt2 + nt3 + nt4) / 4;
}

int estaAprovado(float media){
    if(media >= 6){
        return 1;
    } else {
        return 0;
    }
}
```

O `&&` significa E: uma nota válida precisa atender aos dois limites. Notas exatamente iguais a 0 e 10 são válidas.

A `main` coordena as chamadas:

```c
if(notaValida(nota1) == 0 || notaValida(nota2) == 0 ||
   notaValida(nota3) == 0 || notaValida(nota4) == 0){
    printf("Nota invalida!\n");
} else {
    media = calcularMedia(nota1, nota2, nota3, nota4);
    printf("Media: %.2f\n", media);

    resultado = estaAprovado(media);

    if(resultado == 1){
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
}
```

O `||` significa OU: basta uma nota inválida para impedir o cálculo. Na avaliação das condições, C pode parar assim que já sabe que o resultado do OU é verdadeiro.

Um erro que encontramos foi somar a terceira nota duas vezes, esquecendo a quarta. Com `4, 5, 6, 9`, a média correta é `6.00`, portanto o aluno está aprovado. Testar notas diferentes ajudou a revelar esse erro.

## 9. O novo elemento: `void` — exercício 004

Compare os dois protótipos:

```c
float calcularIMC(float peso, float altura);
void mostrarClassificacaoIMC(float imc);
```

A primeira função devolve um `float`. A segunda não devolve um valor; ela executa uma ação.

```c
void mostrarClassificacaoIMC(float imc){
    if(imc > 30){
        printf("Obeso\n");
    } else {
        printf("Normal\n");
    }
}
```

Essas categorias reproduzem apenas a regra simplificada do exercício. Exatamente 30 entra no `else`.

Na `main`:

```c
if(peso <= 0 || altura <= 0){
    printf("Peso ou altura invalido!\n");
} else {
    imc = calcularIMC(peso, altura);
    printf("IMC: %.2f\n", imc);
    mostrarClassificacaoIMC(imc);
}
```

A sequência é:

1. `calcularIMC` calcula e devolve o valor.
2. A `main` guarda esse valor em `imc`.
3. O `printf` da `main` mostra o número.
4. `mostrarClassificacaoIMC` recebe o número e executa seu próprio `printf`.

A chamada de uma função `void` não é atribuída a uma variável. Ela pode mostrar uma mensagem, mas não fornece um valor de retorno.

`void` não proíbe `return;` sem valor, que pode encerrar uma função antecipadamente. Nossos exemplos terminam naturalmente na chave final.

## 10. Receber uma letra e mostrar a resposta — exercício 005

```c
void mostrarIdentificacao(char letra){
    if(letra == 'M'){
        printf("Masculino\n");
    } else if(letra == 'F'){
        printf("Feminino\n");
    } else {
        printf("Invalido\n");
    }
}
```

A leitura e a chamada na `main` ficam assim:

```c
scanf(" %c", &letra);
mostrarIdentificacao(letra);
```

O espaço antes de `%c` ignora espaços e quebras de linha que estiverem pendentes na entrada. Usamos aspas simples para um caractere, como `'M'`, e aspas duplas para um texto, como `"Masculino"`.

Neste exercício, somente `M` e `F` maiúsculos são aceitos.

A condição que apareceu na tentativa inicial era:

```c
letra != 'M' || letra != 'F'
```

Ela é sempre verdadeira: se a letra é `M`, já é diferente de `F`; se é `F`, já é diferente de `M`. Para expressar “diferente das duas”, usaríamos `&&`. Na solução, a própria função trata todas as alternativas, dispensando essa validação na `main`.

## 11. Calculadora com quatro funções — exercício 006

Os protótipos:

```c
float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
```

As implementações:

```c
float somar(float a, float b){
    return a + b;
}

float subtrair(float a, float b){
    return a - b;
}

float multiplicar(float a, float b){
    return a * b;
}

float dividir(float a, float b){
    return a / b;
}
```

O `main.c` completo, no formato trabalhado:

```c
#include <stdio.h>
#include "prototypes.h"

int main(void){
    float num1, num2;
    float resultado;
    char operador;

    printf("Informe o primeiro numero:\n");
    scanf("%f", &num1);

    printf("Informe o operador (+, -, *, /):\n");
    scanf(" %c", &operador);

    printf("Informe o segundo numero:\n");
    scanf("%f", &num2);

    if(operador == '+'){
        resultado = somar(num1, num2);
        printf("Resultado: %.2f\n", resultado);
    } else if(operador == '-'){
        resultado = subtrair(num1, num2);
        printf("Resultado: %.2f\n", resultado);
    } else if(operador == '*'){
        resultado = multiplicar(num1, num2);
        printf("Resultado: %.2f\n", resultado);
    } else if(operador == '/'){
        if(num2 == 0){
            printf("Nao e possivel dividir por zero.\n");
        } else {
            resultado = dividir(num1, num2);
            printf("Resultado: %.2f\n", resultado);
        }
    } else {
        printf("Operacao invalida.\n");
    }

    return 0;
}
```

A divisão só é chamada com divisor diferente de zero. O operador `%` calcula resto da divisão entre inteiros; ele não pode ser aplicado a esses parâmetros `float` e não verifica se o divisor é zero.

Os exemplos pressupõem entradas numéricas no formato pedido. Ainda não estamos verificando o retorno do `scanf` para tratar letras no lugar de números.

## 12. Compilar arquivos juntos e entender `*.c`

Incluir o cabeçalho apresenta as declarações. Para montar o programa, precisamos compilar também o arquivo que contém as implementações.

Dentro da pasta do exercício:

```bash
mkdir -p output
gcc -Wall -Wextra -g3 main.c implementation.c -o output/main
./output/main
```

Se o arquivo se chamar `implementations.c`, use esse nome no comando.

Podemos selecionar todos os arquivos C da pasta atual:

```bash
gcc -Wall -Wextra -g3 *.c -o output/main
```

`*` representa qualquer nome. O terminal expande `*.c` para os arquivos que terminam em `.c`, por exemplo `main.c implementation.c`. O `.h` entra pelos `#include`.

Essa seleção não percorre subpastas. Para compilar todos os `.c` juntos, eles devem pertencer ao mesmo programa e conter apenas uma definição de `main` no conjunto.

Na nossa prática, configuramos o **Run Code**, com o atalho **Control + Option + N**, para compilar os `.c` da pasta do arquivo aberto. O comando usa `clang`, cria `output` e executa `output/main`. Já o botão **C/C++: Compile & Run** acionado durante os erros compilava apenas o arquivo aberto. São comandos de extensões diferentes.

## 13. Erros que encontramos e como interpretá-los

| Erro ou aviso                   | O que aconteceu                                            | Ajuste                                     |
| ------------------------------- | ---------------------------------------------------------- | ------------------------------------------ |
| `call to undeclared function` | A declaração não estava visível antes da chamada       | Incluir o `.h` correto ou declarar antes |
| `Undefined symbols`           | A implementação ficou fora da compilação               | Compilar os arquivos `.c` juntos         |
| `prototypes.h file not found` | O arquivo foi criado como `prototypes.c`                 | Corrigir a extensão e o `#include`      |
| Parâmetro sem tipo             | Foi escrito `mostrarClassificacaoIMC(imc)` no protótipo | Declarar `float imc`                     |
| `unused parameter` na média  | A quarta nota não foi usada                               | Somar as quatro notas corretas             |
| Aviso de formato do `printf`  | Havia `%.2f` sem argumento correspondente                | Passar `resultado` após a string        |
| `expected ';'`                | Um `printf` terminava com `:`                          | Trocar por `;`                           |
| `else` fora de lugar          | Uma chave fechou o bloco antes da hora                     | Conferir qual bloco cada chave fecha       |
| Nome de função diferente      | Protótipo, chamada e definição não coincidiam          | Usar exatamente o mesmo nome               |

Exemplo correto de impressão:

```c
printf("Resultado: %.2f\n", resultado);
```

Não basta escrever `%.2f`: é preciso fornecer o valor. O formato mostra duas casas decimais, sem mudar o valor armazenado na variável.

## 14. Testes usados na nossa prática

| Exercício | Entrada                                         | Resultado esperado                     |
| ---------- | ----------------------------------------------- | -------------------------------------- |
| 001        | `5`, `-3`, `0`, em execuções separadas  | Positivo, negativo, zero               |
| 002        | `-4`, `5`, `18`, em execuções separadas | Inválida, menor, maior                |
| 003        | Notas `4, 5, 6, 9`                            | Média 6.00; aprovado                  |
| 003        | Quatro notas 5                                  | Média 5.00; reprovado                 |
| 003        | Quatro notas 0 ou quatro notas 10               | Extremos aceitos                       |
| 003        | Uma nota -1 ou 11                               | Nota inválida; sem média             |
| 004        | Peso 80 e altura 2                              | IMC 20.00; Normal                      |
| 004        | Peso 120 e altura 2                             | IMC 30.00; Normal                      |
| 004        | Peso 124 e altura 2                             | IMC 31.00; Obeso                       |
| 004        | Peso ou altura zero ou negativo                 | Dados inválidos; sem cálculo         |
| 005        | `M`, `F`, `m`, `f`, `X`               | Masculino, Feminino, demais inválidos |
| 006        | `8 + 2`, `8 - 2`, `8 * 2`, `8 / 2`      | 10.00, 6.00, 16.00, 4.00               |
| 006        | `8 / 0`                                       | Divisão por zero rejeitada            |
| 006        | `8 ? 2`                                       | Operação inválida                   |

Esses casos foram conferidos durante a construção dos exercícios. Eles registram aquela verificação; novas alterações nos códigos exigem nova conferência.

## 15. Refazer sozinho

Dentro de cada exercício, podemos criar uma pasta `tentativa_sozinho` com novos arquivos vazios:

```text
006/
└── tentativa_sozinho/
    ├── prototypes.h
    ├── implementation.c
    └── main.c
```

Leia apenas o enunciado e reconstrua nesta ordem:

1. Identifique o que cada função recebe e devolve.
2. Escreva os protótipos.
3. Implemente uma função por vez.
4. Faça a leitura na `main`.
5. Valide as entradas exigidas pelo enunciado.
6. Chame as funções e apresente os resultados.
7. Compile e teste os limites.

Ao usar Run Code, abra o `main.c` da tentativa. Como `*.c` seleciona a pasta atual, os arquivos da solução anterior não entram nessa compilação.

## 16. Checklist de entendimento

- [ ] Distingo protótipo, implementação e chamada.
- [ ] Sei identificar tipo de retorno e tipos dos parâmetros.
- [ ] Entendo por que `a` na `main` pode virar `numero` na função.
- [ ] Sei acompanhar uma cópia do argumento até o parâmetro.
- [ ] Entendo que `return` devolve um valor e encerra a chamada.
- [ ] Distingo retornar um número de imprimir uma mensagem.
- [ ] Sei por que uma chamada `void` não é atribuída a `resultado`.
- [ ] Sei validar uma entrada antes de chamar a função.
- [ ] Diferencio `&&` de `||`.
- [ ] Sei usar o retorno em uma variável ou diretamente numa condição.
- [ ] Sei a responsabilidade dos arquivos `.h` e `.c`.
- [ ] Entendo por que compilar só a `main` pode gerar erro de ligação.
- [ ] Sei o significado de `*.c` e por que não devo juntar programas com várias `main`.
- [ ] Consigo refazer os exercícios sem copiar os exemplos.
