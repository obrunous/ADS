# Aula 06 - Consulta SELECT

**Data:** 04/09/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d5398128b1c2c36b88d23491)

> **Banco de Dados I**
> Professor: Dr. Ronan Assumpção Silva
> Data: 04/09/2026
## 🎯 Objetivo da aula
Aprofundar o uso do comando `SELECT`, entendendo como consultar os dados armazenados nas tabelas e como selecionar exatamente as informações desejadas.
---
## 1. O papel do SELECT
O comando `SELECT` é utilizado para **consultar dados** em uma tabela.
Ele faz parte da linguagem SQL e permite visualizar registros já armazenados no banco de dados.
A estrutura mais básica é:
```sql
SELECT * FROM nome_da_tabela;
```
### Entendendo o comando
- `SELECT` → indica que será feita uma consulta.
- `*` → seleciona todas as colunas.
- `FROM` → indica de qual tabela os dados serão buscados.
- `nome_da_tabela` → representa a tabela consultada.
---
## 2. Consultando todas as colunas
Quando usamos `*`, o MySQL retorna todas as colunas da tabela.
Exemplo:
```sql
SELECT * FROM pessoa;
```
Se a tabela `pessoa` possuir as colunas `id`, `nome`, `rg` e `data_nascimento`, todas serão exibidas.
> O `*` é útil para visualizar rapidamente todo o conteúdo da tabela, principalmente durante testes e aprendizagem.
---
## 3. Selecionando colunas específicas
Nem sempre é necessário retornar todas as informações.
Podemos escolher apenas as colunas desejadas:
```sql
SELECT nome, rg FROM pessoa;
```
Nesse caso, a consulta retorna somente `nome` e `rg`.
### Vantagem
Selecionar apenas as colunas necessárias deixa a consulta mais clara e evita retornar dados que não serão utilizados.
---
## 4. Relação entre tabela, atributos e consulta
Até este ponto da disciplina, a estrutura pode ser entendida assim:
```text
BANCO DE DADOS
└── TABELAS
    ├── COLUNAS → atributos
    └── LINHAS → registros
```
O `SELECT` lê os registros armazenados nessas tabelas.
Exemplo conceitual:
| id | nome | cidade |
| --- | --- | --- |
| 1 | Ana | Curitiba |
| 2 | Bruno | Colombo |
Consulta:
```sql
SELECT nome, cidade FROM pessoa;
```
Resultado esperado:
| nome | cidade |
| --- | --- |
| Ana | Curitiba |
| Bruno | Colombo |
---
## 5. Execução no MySQL Workbench
No MySQL Workbench, as consultas são escritas na aba de **Query**.
Após escrever o comando, ele deve ser executado para que o resultado apareça na área de saída.
Exemplo:
```sql
SELECT * FROM pessoa;
```
O resultado exibido representa os registros atualmente armazenados na tabela.
> Lembrete importante do material anterior: os comandos SQL devem ser encerrados com ponto e vírgula (`;`).
---
## 6. Progressão do conteúdo até aqui
A sequência prática da disciplina está ficando assim:
```text
CREATE DATABASE
      ↓
CREATE TABLE
      ↓
INSERT
      ↓
SELECT
      ↓
UPDATE
      ↓
DELETE
```
O foco desta aula é consolidar o `SELECT`, porque a consulta é a principal forma de **ler e verificar** os dados armazenados no banco.
---
## 7. Exercícios de fixação
### Exercício 1
Considere uma tabela chamada `aluno`.
Escreva um comando para consultar todos os registros:
```sql
SELECT * FROM aluno;
```
### Exercício 2
Consulte apenas as colunas `nome` e `email`:
```sql
SELECT nome, email FROM aluno;
```
### Exercício 3
Explique a diferença entre:
```sql
SELECT * FROM aluno;
```
e
```sql
SELECT nome FROM aluno;
```
**Resposta:** o primeiro retorna todas as colunas da tabela; o segundo retorna somente a coluna `nome`.
---
## ✅ Resumo da aula
- `SELECT` é utilizado para consultar dados.
- `SELECT *` retorna todas as colunas.
- É possível selecionar apenas colunas específicas.
- `FROM` indica a tabela consultada.
- O resultado da consulta representa os registros armazenados na tabela.
- O `SELECT` dá continuidade ao conteúdo de criação, inserção, alteração e exclusão de dados.
---
## 📌 Sequência acumulada da disciplina
**Dia 1:** Introdução, avaliação e conceito de banco de dados.

**Dia 2:** Bancos relacionais, tabelas, MySQL Workbench e `CREATE DATABASE`.

**Dia 3:** Aula substituída por Linguagem de Programação II.

**Dia 4:** `CREATE TABLE`, `INSERT`, `UPDATE`, `DELETE` e introdução ao `SELECT`.

**Dia 5:** XI ME²PI.

**Dia 6:** aprofundamento em consultas com `SELECT`.
---
## 🧪 Aplicação prática — Agenda Acadêmica
Nesta aula, a Agenda Acadêmica será utilizada para **consolidar consultas com `SELECT`**. Em vez de avançar para relacionamentos ou novas estruturas ainda não trabalhadas, vamos consultar a tabela `usuarios` criada na prática anterior.
### Preparando registros para consulta
```sql
INSERT INTO usuarios (id, nome, email)
VALUES
    (1, 'Bruno Alves', 'bruno@email.com'),
    (2, 'Ana Souza', 'ana@email.com'),
    (3, 'Joao Silva', 'joao@email.com');
```
### 1. Consultando todos os dados
```sql
SELECT * FROM usuarios;
```
Essa consulta permite conferir todos os registros e atributos atualmente armazenados na tabela.
### 2. Consultando somente nomes
```sql
SELECT nome FROM usuarios;
```
Aqui o banco continua possuindo todos os atributos, mas a consulta solicita somente a coluna `nome`.
### 3. Consultando nome e e-mail
```sql
SELECT nome, email
FROM usuarios;
```
Essa consulta representa melhor uma situação de aplicação: retornar somente os campos necessários para uma determinada tela ou operação.
### Relação com o sistema
Quando a Agenda Acadêmica possuir sua interface web, o usuário não escreverá esses comandos diretamente. A aplicação solicitará os dados ao servidor e, posteriormente, o backend executará consultas no MySQL. Nesta etapa da disciplina, porém, estamos aprendendo diretamente a linguagem que permite recuperar essas informações.
> **Etapa prática alcançada:** consolidamos a leitura dos dados reais do projeto com `SELECT *` e seleção de colunas específicas. Filtros, relacionamentos e consultas mais avançadas serão incorporados somente quando aparecerem na disciplina.
### Progresso do projeto
**problema → entidades → atributos → `CREATE DATABASE` ✅ → `CREATE TABLE` ✅ → `INSERT` ✅ → `SELECT` ✅ → `UPDATE/DELETE` ✅ → PK/FK → relacionamentos → DER/EER → normalização → consultas mais avançadas → integração com Node.js.**
