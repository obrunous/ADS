# Aula 11 - Interface em C para receber dados do sistema acadêmico

**Data:** 02/10/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d53981c18224f9c1705a166d)

## Aula 10 — Interface em C para receber dados do sistema acadêmico
> **Objetivo da aula:** criar uma interface em C para receber os atributos definidos na Atividade 07, apenas lendo e armazenando temporariamente os valores digitados pelo usuário. **Nesta atividade ainda não há integração com o MySQL.**
### 1. Continuidade da aula anterior
Esta aula dá continuidade direta ao conteúdo trabalhado em [DISCENTE–CURSA–DISCIPLINA no MySQL Workbench](https://app.notion.com/p/3aed0f04d53981adaf9bd6c97ca19f5d).
Na aula anterior, o modelo acadêmico foi organizado em três estruturas principais:
**DISCENTE — CURSA — DISCIPLINA**
A sequência didática até aqui é:
```text
Modelagem conceitual
        ↓
Diagrama EER
        ↓
Tabelas no MySQL
        ↓
Interface em C
        ↓
Integração C + MySQL (etapa futura)
```
---
### 2. Revisão da Atividade 07
Na Atividade 07 foi construído o modelo do banco **sistema_academico** utilizando as entidades **DISCENTE** e **DISCIPLINA**, ligadas pela estrutura de relacionamento **CURSA**.
#### DISCENTE
Representa o aluno.
| Atributo | Função |
| --- | --- |
| COD | Chave primária — PK |
| MATRICULA | Matrícula do discente |
| NOME | Nome do discente |
| CPF | CPF do discente |
| ENDERECO | Endereço do discente |
| TELEFONE | Telefone do discente |
| EMAIL | E-mail do discente |
#### CURSA
Representa a associação entre um discente e uma disciplina.
| Atributo | Função |
| --- | --- |
| COD | Chave primária — PK |
| COD_DISCENTE | Referência ao discente — FK no modelo da Atividade 07 |
| COD_DISCIPLINA | Referência à disciplina — FK no modelo da Atividade 07 |
| ANO | Ano em que a relação ocorre |
#### DISCIPLINA
Representa uma disciplina do sistema acadêmico.
| Atributo | Função |
| --- | --- |
| COD | Chave primária — PK |
| NOME | Nome da disciplina |
| CH | Carga horária |
| OBRIGATORIA | Indica se a disciplina é obrigatória |
| VAGAS | Quantidade de vagas |
#### Visão do relacionamento
```text
DISCENTE
   |
   | COD_DISCENTE
   v
 CURSA
   ^
   | COD_DISCIPLINA
   |
DISCIPLINA
```
A ideia é que **CURSA registra qual discente está associado a qual disciplina**.
Exemplo:
```text
DISCENTE
COD = 1
NOME = Bruno

DISCIPLINA
COD = 5
NOME = Banco de Dados I

CURSA
COD = 10
COD_DISCENTE = 1
COD_DISCIPLINA = 5
ANO = 2026
```
Leitura: **o discente de código 1 cursa a disciplina de código 5 no ano de 2026**.
---
### 3. Código de conexão C ↔ MySQL apresentado em aula
O professor também explicou a estrutura básica para um programa em C se conectar ao MySQL.
```c
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conexao;

    // Inicializa a estrutura MYSQL
    conexao = mysql_init(NULL);

    if (conexao == NULL) {
        fprintf(stderr, "Erro ao inicializar o MySQL!\n");
        return 1;
    }

    // Tenta conectar ao banco de dados
    // Parâmetros: (conexao, host, usuário, senha, nome_do_banco, porta, unix_socket, flags)
    if (mysql_real_connect(conexao, "localhost", "root", "sua_senha", "seu_banco", 3306, NULL, 0) == NULL) {
        fprintf(stderr, "Erro de conexão: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return 1;
    }

    printf("Conexão realizada com sucesso!\n");

    // Fecha a conexão
    mysql_close(conexao);
    return 0;
}
```
#### O que cada parte representa
- `#include <mysql/mysql.h>`: disponibiliza as estruturas e funções da biblioteca do MySQL para C.
- `MYSQL *conexao;`: declara um ponteiro usado para representar a conexão.
- `mysql_init(NULL)`: inicializa a estrutura de conexão.
- `mysql_real_connect(...)`: tenta estabelecer a conexão com o servidor MySQL.
- `mysql_error(conexao)`: recupera a mensagem de erro da conexão.
- `mysql_close(conexao)`: encerra a conexão.
A ideia geral é:
```text
Programa em C
     ↓
mysql_init()
     ↓
mysql_real_connect()
     ↓
MySQL
     ↓
mysql_close()
```
> Esse código foi explicado como preparação para a integração entre C e MySQL, mas **não deve ser usado na Atividade 08**, porque o enunciado determina que ainda não exista integração com o banco.
---
### 4. Atividade 08
#### Enunciado
> **Crie uma interface no C para receber os atributos criados na atividade 07. Não é para integrar com Banco de Dados ainda. Apenas faça a leitura dos valores digitados pelos usuários.**
Portanto, nesta etapa o programa deve somente:
1. criar variáveis correspondentes aos atributos;
2. mostrar mensagens com `printf()`;
3. receber os valores com `scanf()`;
4. manter esses valores temporariamente na memória do programa;
5. exibir os valores digitados para conferência.
Não há `INSERT`, `UPDATE`, conexão com MySQL ou gravação permanente.
---
### 5. Fluxo da Atividade 08
```text
ENTRADA
Usuário digita os valores
        ↓
PROCESSAMENTO
scanf() lê os valores
        ↓
MEMÓRIA
Variáveis em C armazenam os dados
        ↓
SAÍDA
printf() mostra os valores
```
Enquanto o programa estiver executando, os dados permanecem nas variáveis.
Quando o programa termina, esses valores deixam de existir porque ainda não foram gravados em um banco de dados ou arquivo.
---
### 6. Mapeamento dos atributos para variáveis em C
| Atributo | Tipo usado em C | Motivo |
| --- | --- | --- |
| COD | int | Código numérico |
| MATRICULA | char\[\] | Pode ser tratada como texto |
| NOME | char\[\] | Texto |
| CPF | char\[\] | Identificador; não é usado para cálculos |
| ENDERECO | char\[\] | Texto com possibilidade de espaços |
| TELEFONE | char\[\] | Identificador; pode conter símbolos |
| EMAIL | char\[\] | Texto |
| ANO | int | Valor numérico inteiro |
| CH | int | Carga horária inteira no exercício |
| OBRIGATORIA | char | Pode receber S ou N |
| VAGAS | int | Quantidade inteira |
> Os tipos acima são uma escolha didática para a interface em C desta atividade. Eles não alteram os tipos definidos no banco da Atividade 07.
---
### 7. Código completo da Atividade 08
```c
#include <stdio.h>

int main() {

    // DISCENTE
    int cod_discente;
    char matricula[20];
    char nome_discente[100];
    char cpf[20];
    char endereco[100];
    char telefone[20];
    char email[100];

    // CURSA
    int cod_cursa;
    int fk_discente;
    int fk_disciplina;
    int ano;

    // DISCIPLINA
    int cod_disciplina;
    char nome_disciplina[100];
    int ch;
    char obrigatoria;
    int vagas;

    printf("====================================\n");
    printf("         SISTEMA ACADEMICO\n");
    printf("====================================\n");

    printf("\n--- DISCENTE ---\n");

    printf("Codigo: ");
    scanf("%d", &cod_discente);

    printf("Matricula: ");
    scanf(" %19[^\n]", matricula);

    printf("Nome: ");
    scanf(" %99[^\n]", nome_discente);

    printf("CPF: ");
    scanf(" %19[^\n]", cpf);

    printf("Endereco: ");
    scanf(" %99[^\n]", endereco);

    printf("Telefone: ");
    scanf(" %19[^\n]", telefone);

    printf("Email: ");
    scanf(" %99[^\n]", email);

    printf("\n--- DISCIPLINA ---\n");

    printf("Codigo: ");
    scanf("%d", &cod_disciplina);

    printf("Nome: ");
    scanf(" %99[^\n]", nome_disciplina);

    printf("Carga horaria: ");
    scanf("%d", &ch);

    printf("Obrigatoria (S/N): ");
    scanf(" %c", &obrigatoria);

    printf("Vagas: ");
    scanf("%d", &vagas);

    printf("\n--- CURSA ---\n");

    printf("Codigo: ");
    scanf("%d", &cod_cursa);

    printf("Codigo do discente: ");
    scanf("%d", &fk_discente);

    printf("Codigo da disciplina: ");
    scanf("%d", &fk_disciplina);

    printf("Ano: ");
    scanf("%d", &ano);

    printf("\n====================================\n");
    printf("         DADOS INFORMADOS\n");
    printf("====================================\n");

    printf("\nDISCENTE\n");
    printf("Codigo: %d\n", cod_discente);
    printf("Matricula: %s\n", matricula);
    printf("Nome: %s\n", nome_discente);
    printf("CPF: %s\n", cpf);
    printf("Endereco: %s\n", endereco);
    printf("Telefone: %s\n", telefone);
    printf("Email: %s\n", email);

    printf("\nDISCIPLINA\n");
    printf("Codigo: %d\n", cod_disciplina);
    printf("Nome: %s\n", nome_disciplina);
    printf("Carga horaria: %d\n", ch);
    printf("Obrigatoria: %c\n", obrigatoria);
    printf("Vagas: %d\n", vagas);

    printf("\nCURSA\n");
    printf("Codigo: %d\n", cod_cursa);
    printf("Codigo Discente: %d\n", fk_discente);
    printf("Codigo Disciplina: %d\n", fk_disciplina);
    printf("Ano: %d\n", ano);

    return 0;
}
```
---
### 8. Entendendo o código
#### `#include <stdio.h>`
Disponibiliza as funções de entrada e saída utilizadas nesta atividade:
- `printf()` → saída de dados;
- `scanf()` → entrada de dados.
#### Variáveis numéricas
Exemplo:
```c
int ano;
```
A variável `ano` pode guardar um número inteiro, como 2026.
#### Variáveis de texto
Exemplo:
```c
char nome_discente[100];
```
Cria um vetor de caracteres capaz de armazenar uma sequência de texto.
#### `printf()`
Exibe uma mensagem:
```c
printf("Nome: ");
```
#### `scanf()`
Realiza a leitura:
```c
scanf("%d", &ano);
```
Se o usuário digitar 2026, o valor será armazenado em `ano`.
#### O operador `&`
Para tipos simples como `int` e `char`, o `scanf()` recebe o endereço da variável:
```c
scanf("%d", &ano);
scanf(" %c", &obrigatoria);
```
Nos vetores de caracteres usados como strings, o nome do vetor já representa o endereço inicial:
```c
scanf(" %99[^\n]", nome_discente);
```
#### Leitura de texto com espaços
Usar:
```c
scanf("%s", nome_discente);
```
faria a leitura parar no primeiro espaço.
Por isso foi utilizado:
```c
scanf(" %99[^\n]", nome_discente);
```
Assim um nome como **Bruno Alves da Silva** pode ser lido por completo até o usuário pressionar Enter.
---
### 9. Quantidade de entradas
A interface recebe todos os atributos da Atividade 07:
```text
DISCENTE   = 7 atributos
CURSA      = 4 atributos
DISCIPLINA = 5 atributos

TOTAL      = 16 valores
```
---
### 10. Exemplo de execução
Exemplo hipotético:
```text
--- DISCENTE ---
Codigo: 1
Matricula: 20260001
Nome: Bruno Alves
CPF: 000.000.000-00
Endereco: Rua Exemplo 100
Telefone: 41999999999
Email: bruno@email.com

--- DISCIPLINA ---
Codigo: 5
Nome: Banco de Dados I
Carga horaria: 80
Obrigatoria (S/N): S
Vagas: 40

--- CURSA ---
Codigo: 10
Codigo do discente: 1
Codigo da disciplina: 5
Ano: 2026
```
Nesse momento, todos esses valores existem somente nas variáveis do programa.
---
### 11. O que ainda NÃO acontece
Nesta atividade não há:
- conexão com o MySQL;
- `mysql_init()`;
- `mysql_real_connect()`;
- `INSERT`;
- `UPDATE`;
- `DELETE`;
- persistência dos dados.
O fluxo atual termina em:
```text
USUÁRIO
   ↓
PROGRAMA EM C
   ↓
VARIÁVEIS NA MEMÓRIA
```
---
### 12. Próxima etapa: integração C + MySQL
O código de conexão mostrado pelo professor prepara a próxima evolução do exercício.
O fluxo futuro tende a ser:
```text
USUÁRIO
   ↓
printf() / scanf()
   ↓
VARIÁVEIS EM C
   ↓
mysql_real_connect()
   ↓
COMANDO SQL
   ↓
MySQL
   ↓
sistema_academico
```
Conceitualmente, os dados sairão das variáveis em C e poderão participar de operações SQL no banco.
O importante é separar as responsabilidades:
**C** recebe e manipula os dados na aplicação.  
**SQL** descreve a operação desejada no banco.  
**MySQL** armazena e gerencia os dados.
---
### 13. Relação com Entrada → Processamento → Saída
#### Entrada
```c
scanf(...)
```
O usuário fornece os dados.
#### Processamento
Nesta atividade, o processamento é simples: os valores são armazenados nas variáveis.
#### Saída
```c
printf(...)
```
O programa apresenta informações na tela.
Portanto:
```text
ENTRADA → PROCESSAMENTO → SAÍDA
```
---
### 14. Conexão com sistemas empresariais
**Exemplo didático de ERP:** imagine uma tela de cadastro de produto.
O usuário informa código, descrição, preço e estoque. A aplicação primeiro precisa receber os valores e, em uma etapa posterior, persisti-los no banco.
Nesta aula ocorre a mesma ideia em escala reduzida:
```text
Interface
   ↓
Entrada dos dados
   ↓
Variáveis da aplicação
   ↓
Banco de dados (etapa futura)
```
Essa lógica aparece constantemente em sistemas corporativos e ERPs. Aqui ela está sendo praticada com o modelo acadêmico **DISCENTE — CURSA — DISCIPLINA**.
---
### 15. O que memorizar
> **Atividade 07:** modelamos e criamos as estruturas do banco.
> 
> **Código de conexão:** aprendemos como C pode abrir uma conexão com o MySQL.
> 
> **Atividade 08:** criamos a interface em C e apenas lemos os atributos.
> 
> **Próxima evolução:** usar os dados recebidos em C para executar operações SQL no MySQL.
#### Resumo rápido
```text
Atividade 07
BANCO / MODELO
DISCENTE — CURSA — DISCIPLINA
        ↓
Atividade 08
INTERFACE EM C
printf() + scanf()
        ↓
Próxima etapa
C + MYSQL
Conexão + SQL
```
### 16. Checklist da Atividade 08
- [ ] Declarar os atributos de DISCENTE.
- [ ] Declarar os atributos de DISCIPLINA.
- [ ] Declarar os atributos de CURSA.
- [ ] Usar `printf()` para solicitar os valores.
- [ ] Usar `scanf()` para realizar as leituras.
- [ ] Ler os 16 atributos.
- [ ] Compilar e testar o programa.
- [ ] Conferir se textos com espaços são lidos corretamente.
- [ ] Não realizar conexão com o banco nesta atividade.
- [ ] Não usar comandos SQL nesta atividade.
