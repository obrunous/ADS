# Aula 05 - XI ME²PI

**Data:** 28/08/2026

**Fonte:** [Página do encontro no Notion](https://app.notion.com/p/3aed0f04d539814e805ecca78b86b37d)

> **Banco de Dados I — XI ME²PI**  
> Data: 28/08/2026
## Registro do dia
Nesta data, o encontro da disciplina esteve associado ao **XI ME²PI**. A página original não possuía conteúdo técnico de Banco de Dados registrado.
> A página fica registrada como **evento institucional**, e não como uma aula de SQL ou modelagem. Assim preservamos a cronologia sem inventar matéria.
## Situação da disciplina até aqui
Antes do evento, a sequência registrada era:
1. introdução a Banco de Dados e SGBD;
2. MySQL Workbench e `CREATE DATABASE`;
3. encontro substituído por Linguagem de Programação II;
4. `CREATE TABLE`, `INSERT`, `UPDATE`, `DELETE` e `SELECT`;
5. **XI ME²PI — evento**.
## O que revisar neste ponto
Como não há conteúdo novo documentado nesta data, esta página pode ser usada para consolidar os comandos já vistos:
```sql
CREATE DATABASE nome_banco;

CREATE TABLE tabela (
    id INT,
    nome VARCHAR(100)
);

INSERT INTO tabela (id, nome)
VALUES (1, 'Exemplo');

SELECT * FROM tabela;

UPDATE tabela
SET nome = 'Novo nome'
WHERE id = 1;

DELETE FROM tabela
WHERE id = 1;
```
## Próxima etapa registrada
Na sequência, em 04/09/2026, a disciplina retoma o conteúdo técnico com aprofundamento em **consultas `SELECT`**.
## Checklist de revisão
- [ ] Entendo a diferença entre banco, tabela, coluna e registro.
- [ ] Sei para que serve `CREATE TABLE`.
- [ ] Sei inserir dados com `INSERT`.
- [ ] Sei consultar com `SELECT`.
- [ ] Entendo o risco de `UPDATE` e `DELETE` sem `WHERE`.
## Síntese
> **Situação:** XI ME²PI. Não há um novo conteúdo de Banco de Dados documentado para o encontro; a página registra o evento e mantém a continuidade da disciplina.
