# Código completo - Banco de Dados I

**Data:** Não informada na página do Notion.

**Fonte:** [Página Código Completo no Notion](https://app.notion.com/p/3e3d0f04d539815dbd7df0ead68f7d9b)

> Página central para reunir os scripts SQL completos trabalhados nas atividades da disciplina. Os registros usados nos exemplos são fictícios/didáticos quando não correspondem a dados originais confirmados.
## 1. Banco Cliente — estrutura inicial
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
('Ana Souza', 'Rua das Flores, 100', '111111111'),
('Bruno Lima', 'Rua Paraná, 200', '222222222'),
('Carla Alves', 'Rua Curitiba, 300', '333333333'),
('Diego Santos', 'Rua Colombo, 400', '444444444'),
('Eduarda Silva', 'Rua Brasil, 500', '555555555'),
('Felipe Costa', 'Rua São Paulo, 600', '666666666'),
('Gabriela Rocha', 'Rua Londrina, 700', '777777777'),
('Henrique Martins', 'Rua Maringá, 800', '888888888'),
('Isabela Ferreira', 'Rua Pinhais, 900', '999999999'),
('João Oliveira', 'Rua Araucária, 1000', '101010101');
```
## 2. Consultas — Cliente
```sql
SELECT * FROM Cliente;

SELECT DISTINCT Nome, Endereco
FROM Cliente;

SELECT Cod, Nome, Endereco
FROM Cliente
WHERE Cod = 3;

SELECT Cod, Nome, Endereco
FROM Cliente
WHERE Cod >= 2
  AND Cod <= 8;

SELECT Cod, Nome
FROM Cliente
ORDER BY Nome ASC;
```
## 3. UPDATE e DELETE
```sql
-- Conferir antes
SELECT * FROM Cliente
WHERE Cod = 1;

-- Atualizar
UPDATE Cliente
SET Endereco = 'Novo Endereco, 150'
WHERE Cod = 1;

-- Conferir depois
SELECT * FROM Cliente
WHERE Cod = 1;

-- Conferir antes da exclusão
SELECT * FROM Cliente
WHERE Cod = 10;

-- Excluir
DELETE FROM Cliente
WHERE Cod = 10;

-- Confirmar exclusão
SELECT * FROM Cliente
WHERE Cod = 10;
```
## 4. Ordem_Servico — relacionamento 1:N
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

INSERT INTO Ordem_Servico
(Descricao, data_os, Cliente_Cod)
VALUES
('Instalacao de equipamento', '2026-09-21', 1),
('Manutencao preventiva', '2026-09-22', 1),
('Configuracao de sistema', '2026-09-22', 2);
```
### Modelo
```text
CLIENTE (1) ───────────── (N) ORDEM_SERVICO

CLIENTE                    ORDEM_SERVICO
PK Cod                     PK Cod
   Nome                       Descricao
   Endereco                   data_os
   RG                      FK Cliente_Cod
```
## 5. JOIN — Cliente + Ordem_Servico
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
> O JOIN é uma expansão didática para compreender a utilização prática da chave estrangeira.
## 6. Inspeção da estrutura
```sql
DESCRIBE Cliente;
DESCRIBE Ordem_Servico;
SHOW CREATE TABLE Ordem_Servico;
```
---
## 🎓 BANCO IFPR
## 7. Criação da estrutura
```sql
CREATE DATABASE IF NOT EXISTS IFPR;
USE IFPR;

CREATE TABLE alunos (
    id_aluno INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    data_nascimento DATE NOT NULL,
    cidade VARCHAR(60) NOT NULL,
    estado CHAR(2) NOT NULL,
    curso VARCHAR(100) NOT NULL,
    periodo INT NOT NULL,
    nota DECIMAL(4,2) NOT NULL,
    matriculado BOOLEAN NOT NULL,
    data_matricula DATE NOT NULL
);
```
## 8. Inserção dos 15 registros didáticos
```sql
INSERT INTO alunos
(nome, data_nascimento, cidade, estado, curso, periodo, nota, matriculado, data_matricula)
VALUES
('Ana Souza','2007-03-10','Colombo','PR','TADS',1,8.50,TRUE,'2026-02-02'),
('Carlos Lima','2005-08-21','Curitiba','PR','TADS',2,7.20,TRUE,'2025-02-03'),
('Marina Alves','2008-01-15','Colombo','PR','TADS',1,9.10,TRUE,'2026-02-02'),
('Lucas Rocha','2006-04-18','Pinhais','PR','TADS',3,6.80,TRUE,'2025-02-03'),
('Fernanda Costa','2007-11-25','Colombo','PR','TADS',2,8.90,TRUE,'2025-07-28'),
('Gabriel Silva','2004-09-12','Curitiba','PR','TADS',4,7.50,TRUE,'2024-02-05'),
('Juliana Martins','2008-06-30','Colombo','PR','TADS',1,9.40,TRUE,'2026-02-02'),
('Rafael Oliveira','2005-02-14','Piraquara','PR','TADS',3,5.90,TRUE,'2025-02-03'),
('Camila Ferreira','2007-07-07','Colombo','PR','TADS',2,8.10,TRUE,'2025-07-28'),
('Pedro Santos','2006-12-01','Curitiba','PR','TADS',3,7.80,TRUE,'2025-02-03'),
('Larissa Almeida','2008-10-19','Colombo','PR','TADS',1,8.70,TRUE,'2026-02-02'),
('Matheus Ribeiro','2004-05-23','São José dos Pinhais','PR','TADS',4,6.50,TRUE,'2024-02-05'),
('Beatriz Gomes','2007-02-11','Colombo','PR','TADS',2,9.00,TRUE,'2025-07-28'),
('João Pereira','2005-06-16','Curitiba','PR','TADS',4,7.10,TRUE,'2024-07-29'),
('Amanda Rodrigues','2008-04-08','Colombo','PR','TADS',1,8.30,TRUE,'2026-02-02');
```
## 9. Relatórios — IFPR
```sql
-- Conferência
SELECT * FROM alunos;

SELECT COUNT(*) AS total_alunos
FROM alunos;

-- Nascidos depois de 2006
SELECT COUNT(*) AS nascidos_apos_2006
FROM alunos
WHERE data_nascimento >= '2007-01-01';

-- Moradores de Colombo
SELECT COUNT(*) AS moradores_colombo
FROM alunos
WHERE cidade = 'Colombo';

-- Moradores de outras cidades
SELECT COUNT(*) AS fora_de_colombo
FROM alunos
WHERE cidade <> 'Colombo';

-- Quantidade por curso
SELECT curso, COUNT(*) AS quantidade_alunos
FROM alunos
GROUP BY curso
ORDER BY quantidade_alunos DESC;

-- Nota >= 7
SELECT nome, curso, nota
FROM alunos
WHERE nota >= 7
ORDER BY nota DESC;

-- Quantidade por cidade
SELECT cidade, COUNT(*) AS quantidade_alunos
FROM alunos
GROUP BY cidade
ORDER BY quantidade_alunos DESC;
```
## 10. Mapa dos comandos estudados
```text
CREATE DATABASE
      ↓
USE
      ↓
CREATE TABLE
      ↓
INSERT
      ↓
SELECT
 ├─ DISTINCT
 ├─ WHERE
 ├─ AND
 ├─ ORDER BY
 ├─ COUNT
 └─ GROUP BY
      ↓
UPDATE
      ↓
DELETE
      ↓
PRIMARY KEY
      ↓
FOREIGN KEY
      ↓
RELACIONAMENTO 1:N
      ↓
EER
      ↓
JOIN
```
## 📝 Observação acadêmica
Os scripts desta página consolidam o conteúdo desenvolvido nas atividades. Quando os valores originalmente digitados não estão registrados, foram utilizados dados fictícios para manter o código executável e útil para revisão.
