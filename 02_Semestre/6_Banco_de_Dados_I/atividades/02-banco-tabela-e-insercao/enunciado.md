# Atividade 02 - Banco, Tabela e Inserção

**Data:** Não informada na página do Notion.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d53981eaa2f2fc3c8b5d04dc)

## 🎯 Objetivo
Evoluir da criação do banco para a definição de uma tabela e persistência de registros.
## 📋 Enunciado
Executar, em ordem: **criação do banco → criação da tabela Clientes → inserção de 10 registros** e apresentar ao professor.
## 1. Modelo mental
```text
BANCO
└── TABELA CLIENTE
    ├── colunas / atributos
    └── linhas / registros
```
## 2. Criando o banco
```sql
CREATE DATABASE IF NOT EXISTS aula_clientes;
USE aula_clientes;
```
## 3. Criando a tabela
Exemplo didático coerente com os exercícios da disciplina:
```sql
CREATE TABLE Cliente (
    Cod INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(100) NOT NULL,
    Endereco VARCHAR(150),
    RG VARCHAR(20)
);
```
### Entendendo a definição
- **INT**: número inteiro.
- **VARCHAR(n)**: texto de tamanho variável.
- **PRIMARY KEY**: identifica exclusivamente um registro.
- **AUTO_INCREMENT**: gera valores sequenciais para a chave.
- **NOT NULL**: impede valor nulo naquela coluna.
## 4. Inserindo registros
Uma linha:
```sql
INSERT INTO Cliente (Nome, Endereco, RG)
VALUES ('Ana Souza', 'Rua A, 100', '123456789');
```
Várias linhas:
```sql
INSERT INTO Cliente (Nome, Endereco, RG)
VALUES
('Bruno Lima', 'Rua B, 200', '234567890'),
('Carla Alves', 'Rua C, 300', '345678901'),
('Diego Santos', 'Rua D, 400', '456789012');
```
Os nomes e documentos acima são fictícios e servem apenas para estudo.
## 5. Conferindo
```sql
SELECT * FROM Cliente;
```
Conferir estrutura:
```sql
DESCRIBE Cliente;
```
## 6. Categorias SQL
Nesta atividade aparecem duas ideias:
- **DDL**: CREATE DATABASE e CREATE TABLE definem estruturas.
- **DML**: INSERT adiciona dados.
## 🏢 Aplicação empresarial
Cadastros de clientes, produtos e parceiros dependem da mesma ideia relacional: uma estrutura define os atributos aceitos e os registros representam ocorrências reais do negócio.
> **Sankhya OM:** analogia conceitual de ERP; não são tabelas oficiais documentadas do produto.
## 🧠 Revisão
**CREATE DATABASE → USE → CREATE TABLE → INSERT → SELECT.**
## ✅ Checklist
- [x] Banco criado
- [x] Tabela criada
- [x] Registros inseridos
- [x] Dados conferidos
- [x] Atividade entregue
## 💻 Código completo — Banco Cliente
> Script consolidado para estudo. Os dados são fictícios.
```sql
CREATE DATABASE IF NOT EXISTS aula_clientes;
USE aula_clientes;

CREATE TABLE Cliente (
    Cod INT PRIMARY KEY AUTO_INCREMENT,
    Nome VARCHAR(100) NOT NULL,
    Endereco VARCHAR(150),
    RG VARCHAR(20)
);

INSERT INTO Cliente (Nome, Endereco, RG)
VALUES
('Ana Souza','Rua das Flores, 100','111111111'),
('Bruno Lima','Rua Paraná, 200','222222222'),
('Carla Alves','Rua Curitiba, 300','333333333'),
('Diego Santos','Rua Colombo, 400','444444444'),
('Eduarda Silva','Rua Brasil, 500','555555555'),
('Felipe Costa','Rua São Paulo, 600','666666666'),
('Gabriela Rocha','Rua Londrina, 700','777777777'),
('Henrique Martins','Rua Maringá, 800','888888888'),
('Isabela Ferreira','Rua Pinhais, 900','999999999'),
('João Oliveira','Rua Araucária, 1000','101010101');

SELECT * FROM Cliente;
DESCRIBE Cliente;
```
> Os valores fictícios não são uma reprodução dos registros originalmente digitados na entrega.
