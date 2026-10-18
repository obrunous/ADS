# Atividade 04 - Banco IFPR e Relatórios

**Data de entrega registrada:** 18/09/2026.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d53981a7a105eaf1badceabe)

## 🎯 Objetivo
Integrar criação de banco, modelagem de tabela, tipos de dados, inserção múltipla e consultas orientadas a relatórios.
## 📋 Enunciado
Criar o banco **IFPR**, uma tabela com **10 atributos**, utilizar tipos como INT, VARCHAR e DATE, inserir **15 registros em um INSERT múltiplo** e produzir **5 consultas** semelhantes a relatórios.
## 1. Criando o banco
```sql
CREATE DATABASE IF NOT EXISTS IFPR;
USE IFPR;
```
## 2. Criando a tabela alunos
```sql
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
### Tipos utilizados
- **INT**: inteiros.
- **VARCHAR**: textos variáveis.
- **CHAR(2)**: texto de tamanho fixo.
- **DATE**: datas.
- **DECIMAL(4,2)**: valores decimais com precisão definida.
- **BOOLEAN**: condição lógica verdadeira/falsa.
## 3. Inserção múltipla
Modelo:
```sql
INSERT INTO alunos
(nome, data_nascimento, cidade, estado, curso, periodo, nota, matriculado, data_matricula)
VALUES
('Ana Souza', '2007-03-10', 'Colombo', 'PR', 'TADS', 1, 8.50, TRUE, '2026-02-02'),
('Carlos Lima', '2005-08-21', 'Curitiba', 'PR', 'TADS', 2, 7.20, TRUE, '2025-02-03'),
('Marina Alves', '2008-01-15', 'Colombo', 'PR', 'TADS', 1, 9.10, TRUE, '2026-02-02');
```
Na atividade completa, o mesmo padrão é utilizado até totalizar **15 registros**. Os dados de exemplo são fictícios.
## 4. Relatório 1 — nascidos depois de 2006
```sql
SELECT COUNT(*) AS nascidos_apos_2006
FROM alunos
WHERE data_nascimento >= '2007-01-01';
```
## 5. Relatório 2 — moradores de Colombo
```sql
SELECT COUNT(*) AS moradores_colombo
FROM alunos
WHERE cidade = 'Colombo';
```
## 6. Relatório 3 — não moradores de Colombo
```sql
SELECT COUNT(*) AS fora_de_colombo
FROM alunos
WHERE cidade <> 'Colombo';
```
## 7. Relatório 4 — quantidade por curso
```sql
SELECT curso, COUNT(*) AS quantidade
FROM alunos
GROUP BY curso
ORDER BY quantidade DESC;
```
## 8. Relatório 5 — notas iguais ou superiores a 7
```sql
SELECT nome, curso, nota
FROM alunos
WHERE nota >= 7
ORDER BY nota DESC;
```
## 9. COUNT e GROUP BY
**COUNT(\*)** conta registros. **GROUP BY** agrupa linhas com valores em comum para produzir resultados agregados.
Exemplo:
```sql
SELECT cidade, COUNT(*) AS quantidade
FROM alunos
GROUP BY cidade;
```
## 10. Validação dos dados
```sql
SELECT * FROM alunos;
DESCRIBE alunos;
SELECT COUNT(*) AS total_registros FROM alunos;
```
O último comando permite verificar se os 15 registros foram inseridos.
## 🏢 Aplicação empresarial
Aqui aparece um fluxo muito próximo da análise de dados corporativos: **dados operacionais → filtros/agrupamentos → informação gerencial**. Em um ERP, o mesmo princípio pode ser aplicado conceitualmente a vendas, estoque, financeiro ou logística.
> **Sankhya OM:** analogia conceitual; não são tabelas oficiais do produto.
## 🧠 Revisão
**DDL cria a estrutura → INSERT grava os dados → SELECT consulta → WHERE filtra → COUNT agrega → GROUP BY consolida → ORDER BY organiza.**
## ✅ Status
Atividade entregue em 18/09/2026.
## 💻 Código completo — Banco IFPR
> Script consolidado: criação, 15 registros didáticos, validação e relatórios.
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

INSERT INTO alunos
(nome,data_nascimento,cidade,estado,curso,periodo,nota,matriculado,data_matricula)
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

SELECT * FROM alunos;
SELECT COUNT(*) AS total_alunos FROM alunos;
DESCRIBE alunos;

SELECT COUNT(*) AS nascidos_apos_2006
FROM alunos
WHERE data_nascimento >= '2007-01-01';

SELECT COUNT(*) AS moradores_colombo
FROM alunos
WHERE cidade = 'Colombo';

SELECT COUNT(*) AS fora_de_colombo
FROM alunos
WHERE cidade <> 'Colombo';

SELECT curso, COUNT(*) AS quantidade_alunos
FROM alunos
GROUP BY curso
ORDER BY quantidade_alunos DESC;

SELECT nome, curso, nota
FROM alunos
WHERE nota >= 7
ORDER BY nota DESC;

SELECT cidade, COUNT(*) AS quantidade_alunos
FROM alunos
GROUP BY cidade
ORDER BY quantidade_alunos DESC;
```
> Os 15 registros são dados didáticos consolidados, não uma reprodução literal dos dados originalmente digitados.
