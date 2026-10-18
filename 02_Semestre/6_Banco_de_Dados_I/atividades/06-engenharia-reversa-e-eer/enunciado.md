# Atividade 06 - Engenharia Reversa, EER, PK e FK

**Data:** Não informada na página do Notion.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d53981c5bb2ec4794ac87290)

## 🎯 Objetivo
Evoluir de tabelas isoladas para um **modelo relacional**, representando visualmente a associação entre Cliente e Ordem_Servico.
## 📋 Enunciado
Realizar engenharia reversa da tabela **Cliente** e adicionar ao diagrama a tabela **Ordem_Servico**:
- Cod — INT, PK, AUTO_INCREMENT
- Descricao — VARCHAR(200), NOT NULL
- data_os — DATE, NOT NULL
- Cliente_Cod — INT, NOT NULL
- Cliente_Cod referencia Cliente.Cod
- nome da FK: **fk_os_cliente**
- relacionamento **1:N**
## 1. Conceito — engenharia reversa
Na engenharia reversa, partimos do banco existente para gerar seu modelo visual. O diagrama **EER (Enhanced Entity-Relationship)** ajuda a visualizar tabelas, atributos, chaves e relacionamentos.
## 2. Modelo lógico
```text
CLIENTE                         ORDEM_SERVICO
------------------              -------------------------
PK  Cod                  1 ── N PK  Cod
    Nome                         Descricao
    Endereco                     data_os
    RG                       FK  Cliente_Cod
```
Interpretação: **um Cliente pode possuir várias Ordens de Serviço; cada Ordem de Serviço referencia um Cliente.**
## 3. Criando Ordem_Servico
```sql
CREATE TABLE Ordem_Servico (
    Cod INT PRIMARY KEY AUTO_INCREMENT,
    Descricao VARCHAR(200) NOT NULL,
    data_os DATE NOT NULL,
    Cliente_Cod INT NOT NULL,
    CONSTRAINT fk_os_cliente
        FOREIGN KEY (Cliente_Cod)
        REFERENCES Cliente(Cod)
);
```
## 4. Chave primária — PK
```sql
Cod INT PRIMARY KEY AUTO_INCREMENT
```
A PK identifica exclusivamente cada ordem de serviço. Dois registros não podem possuir a mesma chave primária.
## 5. Chave estrangeira — FK
```sql
CONSTRAINT fk_os_cliente
    FOREIGN KEY (Cliente_Cod)
    REFERENCES Cliente(Cod)
```
A coluna **Cliente_Cod** armazena a referência ao **Cod** da tabela Cliente.
## 6. Integridade referencial
A FK cria uma dependência entre os dados. Conceitualmente, isso evita que a ordem de serviço faça referência a um cliente inexistente.
## 7. Cardinalidade 1:N
```text
Cliente (1) ─────────── (N) Ordem_Servico
```
Exemplo:
```text
Cliente Cod 1
 ├── OS 1
 ├── OS 2
 └── OS 3
```
O valor do cliente pode aparecer como referência em várias ordens, mas cada registro de Ordem_Servico possui um único Cliente_Cod nesse modelo.
## 8. Inserindo dados relacionados
Primeiro deve existir um cliente válido. Exemplo didático:
```sql
INSERT INTO Cliente (Nome, Endereco, RG)
VALUES ('Cliente Exemplo', 'Rua A, 100', '123456789');
```
Depois, supondo que o cliente criado possua Cod = 1:
```sql
INSERT INTO Ordem_Servico
(Descricao, data_os, Cliente_Cod)
VALUES
('Instalacao de equipamento', '2026-09-21', 1),
('Manutencao preventiva', '2026-09-22', 1);
```
## 9. Consultando o relacionamento
Uma consulta com JOIN permite combinar informações das duas tabelas:
```sql
SELECT
    os.Cod AS codigo_os,
    os.Descricao,
    os.data_os,
    c.Cod AS codigo_cliente,
    c.Nome AS cliente
FROM Ordem_Servico AS os
INNER JOIN Cliente AS c
    ON c.Cod = os.Cliente_Cod
ORDER BY os.Cod;
```
> **JOIN é uma expansão didática para compreender a utilidade da FK; não fazia parte do enunciado original informado.**
## 10. Conferindo as constraints
```sql
DESCRIBE Ordem_Servico;
```
Também é possível inspecionar a definição:
```sql
SHOW CREATE TABLE Ordem_Servico;
```
## 11. Fluxo completo
```text
Tabela Cliente existente
        ↓
Engenharia reversa
        ↓
Diagrama EER
        ↓
Criar Ordem_Servico
        ↓
Definir PK
        ↓
Definir Cliente_Cod
        ↓
Criar FK fk_os_cliente
        ↓
Relacionamento Cliente 1:N Ordem_Servico
```
## 🏢 Aplicação empresarial
Esse padrão é central em bancos relacionais usados por sistemas corporativos: um registro principal se relaciona a diversos registros dependentes. Exemplos conceituais incluem cliente → pedidos, pedido → itens e produto → movimentações.
> **Sankhya OM:** os exemplos acima são acadêmicos/hipotéticos. Não estamos afirmando nomes de tabelas ou campos internos do Sankhya.
## 🧠 Revisão
**PK identifica → FK referencia → relacionamento conecta → integridade referencial mantém coerência → JOIN recupera dados relacionados.**
## ✅ Checklist
- [x] Engenharia reversa
- [x] Cliente no EER
- [x] Ordem_Servico criada
- [x] PK configurada
- [x] FK fk_os_cliente configurada
- [x] Relacionamento 1:N
- [x] Atividade entregue
## 💻 Código completo consolidado — Cliente + Ordem_Servico
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
SELECT DISTINCT Nome, Endereco FROM Cliente;
SELECT Cod, Nome, Endereco FROM Cliente WHERE Cod = 3;
SELECT Cod, Nome, Endereco FROM Cliente WHERE Cod >= 2 AND Cod <= 8;
SELECT Cod, Nome FROM Cliente ORDER BY Nome ASC;

SELECT * FROM Cliente WHERE Cod = 1;
UPDATE Cliente SET Endereco = 'Novo Endereco, 150' WHERE Cod = 1;
SELECT * FROM Cliente WHERE Cod = 1;

SELECT * FROM Cliente WHERE Cod = 10;
DELETE FROM Cliente WHERE Cod = 10;
SELECT * FROM Cliente WHERE Cod = 10;

CREATE TABLE Ordem_Servico (
 Cod INT PRIMARY KEY AUTO_INCREMENT,
 Descricao VARCHAR(200) NOT NULL,
 data_os DATE NOT NULL,
 Cliente_Cod INT NOT NULL,
 CONSTRAINT fk_os_cliente
  FOREIGN KEY (Cliente_Cod)
  REFERENCES Cliente(Cod)
);

INSERT INTO Ordem_Servico (Descricao,data_os,Cliente_Cod)
VALUES
('Instalacao de equipamento','2026-09-21',1),
('Manutencao preventiva','2026-09-22',1),
('Configuracao de sistema','2026-09-22',2);

SELECT
 os.Cod AS codigo_os,
 os.Descricao,
 os.data_os,
 c.Cod AS codigo_cliente,
 c.Nome AS cliente
FROM Ordem_Servico AS os
INNER JOIN Cliente AS c
 ON c.Cod = os.Cliente_Cod
ORDER BY os.Cod;

DESCRIBE Cliente;
DESCRIBE Ordem_Servico;
SHOW CREATE TABLE Ordem_Servico;
```
## 🧭 Estrutura resultante
```text
CLIENTE
PK  Cod
    Nome
    Endereco
    RG
      │
      │ 1:N
      ▼
ORDEM_SERVICO
PK  Cod
    Descricao
    data_os
FK  Cliente_Cod
```
**Relacionamento:** Cliente **1:N** Ordem_Servico.
> Os dados inseridos são fictícios/didáticos. A estrutura de Ordem_Servico segue o enunciado informado da Atividade 06.
