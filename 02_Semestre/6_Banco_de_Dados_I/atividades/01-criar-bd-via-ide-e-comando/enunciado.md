# Atividade 01 - Criar BD via IDE e comando

**Data:** Não informada na página do Notion.

**Fonte:** [Página da atividade no Notion](https://app.notion.com/p/3e3d0f04d53981448191c749583fcd6e)

## 🎯 Objetivo
Compreender como um banco de dados é criado tanto pela interface gráfica do SGBD quanto diretamente por SQL.
## 📋 Enunciado
Criar dois bancos de dados na ordem indicada no título: primeiro pela IDE e depois por comando. Ao final, registrar em print os dois bancos criados.
## 1. Fundamentos
Um **SGBD** é o software responsável por criar, armazenar, consultar e administrar bancos de dados. Em SQL, comandos que criam ou alteram estruturas pertencem à **DDL — Data Definition Language**.
### Comandos fundamentais
```sql
CREATE DATABASE banco_exemplo;
```
Listar bancos disponíveis:
```sql
SHOW DATABASES;
```
Selecionar um banco para trabalhar:
```sql
USE banco_exemplo;
```
Consultar qual banco está selecionado:
```sql
SELECT DATABASE();
```
## 2. Procedimento pela IDE
1. Abrir o MySQL Workbench.
2. Conectar ao servidor MySQL.
3. Localizar a área de schemas.
4. Criar um novo schema pela interface.
5. Aplicar a alteração.
6. Atualizar a árvore de schemas e confirmar a criação.
## 3. Procedimento via SQL
```sql
CREATE DATABASE banco_sql;
SHOW DATABASES;
USE banco_sql;
SELECT DATABASE();
```
## 4. Versão mais segura
Quando não queremos erro caso o banco já exista:
```sql
CREATE DATABASE IF NOT EXISTS banco_sql;
```
## 5. O que observar
A IDE não substitui SQL: normalmente ela executa operações equivalentes no SGBD por meio de uma interface visual. Saber SQL permite compreender exatamente o que está sendo solicitado ao servidor.
## 🏢 Contexto empresarial
A criação de bancos e schemas faz parte da preparação da camada de persistência de aplicações corporativas. Scripts também facilitam repetibilidade, documentação e implantação entre ambientes.
> **Sankhya OM:** esta seção é apenas uma analogia de ERP. Nenhuma estrutura específica do Sankhya está sendo afirmada.
## 🧠 Revisão
**Banco → SGBD → DDL → CREATE DATABASE → USE → tabelas.**
## ✅ Checklist
- [x] Criar banco pela IDE
- [x] Criar banco por SQL
- [x] Conferir os bancos
- [x] Registrar evidência
- [x] Atividade entregue
