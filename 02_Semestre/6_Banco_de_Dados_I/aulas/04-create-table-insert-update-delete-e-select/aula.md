# Aula 04 - CREATE TABLE, INSERT, UPDATE, DELETE e SELECT

**Data:** 21/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d5398161a635f85de3284ddd)

> **Banco de Dados I**
> Professor: Dr. Ronan Assumpção Silva
> Data: 21/08/2026
## 🎯 Objetivo da aula
Avançar da criação do banco de dados para a criação e manipulação de tabelas, utilizando os principais comandos SQL trabalhados no dia: `CREATE TABLE`, `INSERT`, `UPDATE`, `DELETE` e `SELECT`.
---
## 1. Continuação do banco criado anteriormente
Na aula anterior, foi criado um banco de dados e definido um schema padrão. Nesta aula, o foco passa a ser a estrutura interna desse banco: as **tabelas** e os dados armazenados nelas.
### Estrutura básica
- **Banco de dados / Schema** → contém tabelas.
- **Tabela** → organiza os dados em linhas e colunas.
- **Colunas** → representam atributos.
- **Linhas** → representam registros.
---
## 2. CREATE TABLE — criando uma tabela
O comando `CREATE TABLE` pertence à linguagem de definição de dados e é usado para criar a estrutura de uma nova tabela.
### Estrutura geral
```sql
CREATE TABLE nome_tabela (
    coluna1 TIPO,
    coluna2 TIPO,
    coluna3 TIPO
);
```
### Exemplo didático
```sql
CREATE TABLE pessoa (
    id INT,
    nome VARCHAR(100),
    rg VARCHAR(20),
    data_nascimento DATE
);
```
### Leitura do comando
- `CREATE TABLE` → cria uma nova tabela.
- `pessoa` → nome escolhido para a tabela.
- `id`, `nome`, `rg`, `data_nascimento` → atributos/colunas.
- `INT`, `VARCHAR` e `DATE` → tipos de dados das colunas.
> A tabela define a **estrutura**. Os dados serão adicionados depois com `INSERT`.
---
## 3. Conferindo a criação da tabela no MySQL Workbench
Depois de executar a instrução SQL, a tabela pode ser conferida na área **Schemas** do MySQL Workbench.
Caso a tabela não apareça imediatamente, deve-se utilizar o botão de **atualizar**.
A navegação segue a hierarquia:
```text
Schema
└── Tables
    └── Tabela
        └── Columns
```
Essa visualização permite conferir o banco, as tabelas existentes e suas respectivas colunas.
---
## 4. INSERT — inserindo registros
Depois que a tabela existe, podemos adicionar dados utilizando `INSERT`.
### Estrutura geral
```sql
INSERT INTO nome_tabela (coluna1, coluna2)
VALUES (valor1, valor2);
```
### Exemplo
```sql
INSERT INTO pessoa (id, nome, rg, data_nascimento)
VALUES (1, 'Ronan', '8...', '2001-01-17');
```
### Conceito
O `INSERT` adiciona uma nova **linha** à tabela. Essa linha corresponde a um novo registro ou instância.
---
## 5. SELECT — consultando os dados
O comando `SELECT` é usado para recuperar informações armazenadas em uma tabela.
### Consultar todos os dados
```sql
SELECT * FROM pessoa;
```
O símbolo `*` representa todas as colunas da tabela.
### Consultar colunas específicas
```sql
SELECT nome, rg
FROM pessoa;
```
Nesse caso, somente os atributos `nome` e `rg` são retornados.
---
## 6. UPDATE — alterando dados existentes
O comando `UPDATE` modifica dados que já estão armazenados.
### Estrutura geral
```sql
UPDATE nome_tabela
SET coluna = novo_valor
WHERE condição;
```
### Exemplo
```sql
UPDATE pessoa
SET nome = 'João'
WHERE id = 1;
```
> O `WHERE` define quais registros serão alterados. Sem uma condição adequada, o comando pode modificar várias linhas da tabela.
---
## 7. DELETE — excluindo registros
O comando `DELETE` remove registros existentes de uma tabela.
### Estrutura geral
```sql
DELETE FROM nome_tabela
WHERE condição;
```
### Exemplo
```sql
DELETE FROM pessoa
WHERE id = 1;
```
Assim como no `UPDATE`, a condição `WHERE` determina qual registro será afetado.
---
## 8. Relação entre os comandos estudados
```text
CREATE TABLE
↓
Cria a estrutura da tabela
↓
INSERT
↓
Adiciona registros
↓
SELECT
↓
Consulta os registros
↓
UPDATE
↓
Altera registros
↓
DELETE
↓
Remove registros
```
### Classificação prática
| Comando | Função |
| --- | --- |
| `CREATE TABLE` | Criar a estrutura de uma tabela. |
| `INSERT` | Inserir novos registros. |
| `SELECT` | Consultar dados. |
| `UPDATE` | Alterar registros existentes. |
| `DELETE` | Excluir registros. |
---
## 9. Geração do Diagrama Entidade-Relacionamento pelo MySQL Workbench
O material do professor também mostra o processo de gerar um modelo EER a partir do banco já criado.
### Etapas apresentadas
1. Fechar a conexão ativa, quando necessário.
2. Acessar a opção **Create EER Model from Script**.
3. Escolher a conexão `ConexaoBDMySQL`.
4. Avançar nas etapas com **Next**.
5. Selecionar somente o banco criado.
6. Executar o processo.
7. Finalizar com **Finish**.
Ao final, o Workbench gera automaticamente o diagrama a partir da estrutura SQL existente.
> O material destaca que o processo inverso também é possível: o modelo pode servir de base para gerar a estrutura SQL.
---
## ✅ Resumo da Aula 4
- Evolução do **banco** para a criação de **tabelas**.
- `CREATE TABLE` cria a estrutura da tabela.
- `INSERT` adiciona registros.
- `SELECT` consulta dados.
- `UPDATE` modifica registros.
- `DELETE` remove registros.
- O MySQL Workbench permite conferir tabelas e colunas pela área **Schemas**.
- O Workbench também permite gerar um **Diagrama Entidade-Relacionamento/EER** a partir da estrutura SQL existente.
---
## 🧩 Sequência acumulada até aqui
```text
Dia 1 → Conceitos de Banco de Dados e SGBD
Dia 2 → MySQL, conexão, schemas e CREATE DATABASE
Dia 3 → Aula substituída por Linguagem de Programação II
Dia 4 → CREATE TABLE + manipulação básica de dados
```
---
## 🧪 Aplicação prática — Agenda Acadêmica
Agora o conteúdo da disciplina permite começar a estruturar efetivamente o banco `agenda_academica`. A prática acompanha exatamente os comandos trabalhados no dia: criar uma tabela, inserir dados, consultar, alterar e excluir registros.
### 1. Primeira tabela do projeto — `usuarios`
A documentação da Agenda Acadêmica prevê cadastro e autenticação de usuários. Portanto, `usuarios` é uma boa primeira tabela para aplicar `CREATE TABLE` sem antecipar relacionamentos ainda não estudados.
```sql
USE agenda_academica;

CREATE TABLE usuarios (
    id INT,
    nome VARCHAR(100),
    email VARCHAR(150)
);
```
Neste momento, `id`, `nome` e `email` são os **atributos** e cada usuário inserido será um **registro**. Chaves primárias, restrições e relacionamentos serão acrescentados quando esses assuntos forem estudados.
### 2. INSERT — cadastrando um usuário
```sql
INSERT INTO usuarios (id, nome, email)
VALUES (1, 'Bruno Alves', 'bruno@email.com');
```
A Agenda Acadêmica passa a possuir seu primeiro registro de teste.
### 3. SELECT — conferindo o registro
```sql
SELECT * FROM usuarios;
```
Ou selecionando somente os dados necessários:
```sql
SELECT nome, email FROM usuarios;
```
### 4. UPDATE — corrigindo um dado
```sql
UPDATE usuarios
SET email = 'bruno.novo@email.com'
WHERE id = 1;
```
### 5. DELETE — removendo um registro de teste
```sql
DELETE FROM usuarios
WHERE id = 1;
```
### 6. Próximas tabelas previstas
Conforme a disciplina avançar, a estrutura poderá crescer progressivamente para representar `periodos`, `disciplinas`, `paginas` e compromissos; posteriormente, poderão ser incorporadas estruturas de gestão acadêmica como `aulas`, `faltas` e `avaliacoes`.
> **Etapa prática alcançada:** banco criado → primeira tabela criada → primeiro ciclo CRUD básico praticado com `INSERT`, `SELECT`, `UPDATE` e `DELETE`. Não antecipamos PK/FK ou relacionamentos.
### Progresso do projeto
**problema → entidades → atributos → `CREATE DATABASE` ✅ → `CREATE TABLE` ✅ → `INSERT` ✅ → `SELECT` ✅ → `UPDATE/DELETE` ✅ → PK/FK → relacionamentos → DER/EER → normalização → consultas mais avançadas → integração com Node.js.**
