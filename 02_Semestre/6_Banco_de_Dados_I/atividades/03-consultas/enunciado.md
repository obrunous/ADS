# Atividade 03 - Consultas SQL

**Data de entrega registrada:** 18/09/2026.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d53981068653e3bcdff4f38b)

## 🎯 Objetivo
Aprender a recuperar, filtrar, eliminar repetições e ordenar dados armazenados.
## 📋 Enunciado
Executar as consultas propostas pelo professor: **SELECT, DISTINCT, WHERE, AND e ORDER BY**.
## 1. SELECT — consulta básica
```sql
SELECT *
FROM Cliente;
```
O asterisco representa todas as colunas.
Selecionando colunas específicas:
```sql
SELECT Nome, Endereco
FROM Cliente;
```
## 2. DISTINCT — resultados distintos
Estrutura solicitada:
```sql
SELECT DISTINCT Nome, Endereco
FROM Cliente;
```
O DISTINCT remove combinações duplicadas do conjunto retornado.
## 3. WHERE — filtro
```sql
SELECT Cod, Nome, Endereco
FROM Cliente
WHERE Cod = 3;
```
Operadores úteis:
```text
=    igual
<>   diferente
>    maior
<    menor
>=   maior ou igual
<=   menor ou igual
```
## 4. AND — múltiplas condições
```sql
SELECT Cod, Nome, Endereco
FROM Cliente
WHERE Cod >= 2
  AND Cod <= 8;
```
Com AND, todas as condições precisam ser verdadeiras.
## 5. ORDER BY — ordenação
Crescente:
```sql
SELECT Cod, Nome
FROM Cliente
ORDER BY Nome ASC;
```
Decrescente:
```sql
SELECT Cod, Nome
FROM Cliente
ORDER BY Nome DESC;
```
## 6. Consulta combinada
```sql
SELECT DISTINCT Cod, Nome, Endereco
FROM Cliente
WHERE Cod >= 2
  AND Cod <= 8
ORDER BY Nome ASC;
```
### Ordem lógica para leitura
```text
SELECT → FROM → WHERE → ORDER BY
```
## 7. Pensando como relatório
Pergunta: **quais clientes atendem a determinado critério e como quero visualizar o resultado?**
SQL transforma essa pergunta em:
```sql
SELECT colunas
FROM tabela
WHERE criterio
ORDER BY coluna;
```
## 🏢 Aplicação empresarial
Consultas são a base de pesquisas e relatórios: localizar cadastros, restringir registros por condições e ordenar resultados para análise.
> **Sankhya OM:** exemplo conceitual de uso em ERP, sem atribuição de tabelas específicas.
## 🧠 Revisão
**SELECT consulta \| DISTINCT elimina repetição \| WHERE filtra \| AND combina condições \| ORDER BY ordena.**
## ✅ Status
Atividade entregue em 18/09/2026.
