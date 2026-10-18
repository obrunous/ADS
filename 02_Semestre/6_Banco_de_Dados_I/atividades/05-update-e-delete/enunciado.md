# Atividade 05 - UPDATE e DELETE

**Data:** Não informada na página do Notion.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d539818ea260ecac905ef249)

## 🎯 Objetivo
Aprender a alterar e excluir registros de maneira controlada, compreendendo o papel crítico da cláusula WHERE.
## 📋 Enunciado
Demonstrar com prints o uso adequado de **UPDATE** e **DELETE**.
## 1. UPDATE — atualização
Sintaxe:
```sql
UPDATE tabela
SET coluna = valor
WHERE condição;
```
Exemplo:
```sql
UPDATE Cliente
SET Nome = 'Bruno Alves'
WHERE Cod = 1;
```
Alterando mais de uma coluna:
```sql
UPDATE Cliente
SET Nome = 'Bruno Alves',
    Endereco = 'Rua Exemplo, 100'
WHERE Cod = 1;
```
## 2. Procedimento profissional para UPDATE
### Antes
```sql
SELECT *
FROM Cliente
WHERE Cod = 1;
```
### Alteração
```sql
UPDATE Cliente
SET Endereco = 'Novo Endereco'
WHERE Cod = 1;
```
### Depois
```sql
SELECT *
FROM Cliente
WHERE Cod = 1;
```
Assim, os prints documentam **estado anterior → comando → estado posterior**.
## 3. DELETE — exclusão
Sintaxe:
```sql
DELETE FROM tabela
WHERE condição;
```
Exemplo:
```sql
DELETE FROM Cliente
WHERE Cod = 10;
```
## 4. Procedimento profissional para DELETE
### Conferir alvo
```sql
SELECT *
FROM Cliente
WHERE Cod = 10;
```
### Excluir
```sql
DELETE FROM Cliente
WHERE Cod = 10;
```
### Confirmar
```sql
SELECT *
FROM Cliente
WHERE Cod = 10;
```
Se a última consulta não retornar a linha, o registro não está mais presente.
## ⚠️ O risco de esquecer WHERE
```sql
UPDATE Cliente
SET Nome = 'Teste';
```
Esse comando tenta atualizar **todos os registros**.
```sql
DELETE FROM Cliente;
```
Esse comando tenta excluir **todos os registros** da tabela.
Por isso, em operações direcionadas, confirme o filtro antes de executar.
## 5. DML
UPDATE e DELETE são operações de **manipulação de dados**. Diferentemente de CREATE TABLE, elas atuam sobre registros armazenados.
## 🏢 Aplicação empresarial
Em sistemas corporativos, atualização é rotina; exclusão exige ainda mais controle porque registros podem participar de relacionamentos ou possuir relevância histórica e fiscal.
> **Sankhya OM:** o comportamento concreto de exclusão/alteração depende das regras do produto; esta é uma explicação acadêmica de SQL.
## 🧠 Revisão
**SELECT antes → validar WHERE → UPDATE/DELETE → SELECT depois.**
## ✅ Status
Atividade entregue.
