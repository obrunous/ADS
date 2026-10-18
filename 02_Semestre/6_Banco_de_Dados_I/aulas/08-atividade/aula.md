# Aula 08 - Atividades 03 e 04: Consultas e Banco IFPR

**Data:** 18/09/2026

**Fonte:** [Página do encontro](https://app.notion.com/p/3aed0f04d539815eaa16ccbf84bb6fa2), que direciona para [Atividades 03 e 04](https://app.notion.com/p/3dcd0f04d5398101a845ed5ab68a7e16).

Observação: o título da página informa 18/09/2026; a propriedade Data informa 17/09/2026. Divergência preservada para conferência.

> **Entrega e apresentação:** 18/09/2026
> Professor: Ronan Assumpção Silva
## Atividade 03 — Consultas
1. `SELECT * FROM nome_tabela;`
2. `SELECT DISTINCT Nome, Endereço FROM Cliente;`
3. `SELECT coluna1, coluna2 FROM nome_tabela WHERE condição;`
4. `SELECT coluna1, coluna2 FROM nome_tabela WHERE condição1 AND condição2 AND condição3;`
5. `SELECT coluna1, coluna2 FROM nome_tabela ORDER BY coluna1, coluna2 ASC|DESC;`
## Atividade 04 — Banco IFPR
- Criar um banco de dados chamado `IFPR`.
- Criar uma tabela com **10 atributos**.
- Utilizar tipos como `INT`, `VARCHAR`, `DATE` e outros pertinentes.
- Inserir **15 registros** utilizando um único `INSERT` com múltiplos registros.
- Fazer **5 consultas** como se fossem utilizadas para montar um relatório.
## Estrutura planejada
Tabela `alunos` com: `id_aluno`, `nome`, `data_nascimento`, `cidade`, `estado`, `curso`, `periodo`, `nota`, `matriculado` e `data_matricula`.
## Consultas trabalhadas
```sql
SELECT * FROM alunos;

SELECT DISTINCT nome, cidade
FROM alunos;

SELECT nome, cidade
FROM alunos
WHERE cidade = 'Colombo';

SELECT nome, cidade, nota
FROM alunos
WHERE cidade = 'Colombo'
AND nota >= 7
AND matriculado = TRUE;

SELECT nome, nota
FROM alunos
ORDER BY nota DESC;
```
## Para a apresentação
- [ ] Criar o banco `IFPR`
- [ ] Criar a tabela com 10 atributos
- [ ] Inserir os 15 registros
- [ ] Executar as consultas da Atividade 03
- [ ] Executar as 5 consultas de relatório da Atividade 04
- [ ] Validar tudo no MySQL Workbench
- [ ] Apresentar ao professor
---
## Material de estudo — Todas as consultas SQL
Material de estudo das Atividades 03 e 04. Professor: Ronan Assumpção Silva.
## Como usar
Para executar, copie a consulta desejada para o MySQL Workbench, selecione apenas essa consulta e clique no primeiro raio. Os comandos usam `IFPR.alunos`, portanto não dependem de selecionar previamente o banco.
As consultas abaixo leem os dados. Não é necessário executar novamente o CREATE TABLE ou o INSERT. Os resultados esperados referem-se aos 15 alunos fictícios do script original; mudanças nos dados podem alterar os resultados.
## Atividade 03 — Consultas básicas
### Mostrar todos os alunos
```sql
SELECT * FROM IFPR.alunos;
```
O asterisco seleciona todas as colunas; cada linha representa um aluno.
### Mostrar combinações distintas de nome e cidade
```sql
SELECT DISTINCT nome, cidade
FROM IFPR.alunos;
```
DISTINCT elimina repetições da combinação das duas colunas. Nomes diferentes na mesma cidade continuam aparecendo.
### Consultar alunos de Colombo
```sql
SELECT nome, cidade
FROM IFPR.alunos
WHERE cidade = 'Colombo';
```
WHERE filtra as linhas que atendem à condição.
### Combinar três condições
```sql
SELECT nome, cidade, nota
FROM IFPR.alunos
WHERE cidade = 'Colombo'
AND nota >= 7
AND matriculado = TRUE;
```
AND exige que todas as condições sejam verdadeiras: morar em Colombo, ter nota a partir de 7 e estar matriculado.
### Ordenar alunos pela nota
```sql
SELECT nome, nota
FROM IFPR.alunos
ORDER BY nota DESC, nome ASC;
```
DESC ordena da maior nota para a menor; ASC ordena os nomes alfabeticamente quando as notas empatam.
## Atividade 04 — Cinco consultas para apresentar
### 1. Quantos alunos nasceram depois de 2006?
```sql
SELECT COUNT(*) AS nascidos_apos_2006
FROM IFPR.alunos
WHERE data_nascimento >= '2007-01-01';
```
COUNT(\*) conta as linhas. A data inclui todos os nascidos a partir de 1º de janeiro de 2007. Resultado esperado com os dados originais: 0.
### 2. Quantos moram em Colombo e quantos não moram?
```sql
SELECT
    SUM(cidade = 'Colombo') AS moram_em_colombo,
    SUM(cidade <> 'Colombo') AS nao_moram_em_colombo
FROM IFPR.alunos;
```
No MySQL, uma comparação verdadeira vale 1 e uma falsa vale 0. SUM soma esses valores. \<\> significa diferente. Resultado esperado: 7 em Colombo e 8 fora. A coluna cidade foi definida como NOT NULL.
### 3. Quantos alunos existem em cada curso?
```sql
SELECT curso, COUNT(*) AS quantidade_alunos
FROM IFPR.alunos
GROUP BY curso;
```
GROUP BY reúne os alunos por curso, e COUNT conta cada grupo. Resultado esperado: 5 alunos por curso.
### 4. Qual é a média das notas de cada curso?
```sql
SELECT curso, ROUND(AVG(nota), 2) AS media_notas
FROM IFPR.alunos
GROUP BY curso;
```
AVG calcula a média; ROUND arredonda para duas casas decimais. A consulta inclui todos os alunos, independentemente da matrícula.
### 5. Quais alunos têm nota igual ou superior a 7?
```sql
SELECT nome, curso, nota
FROM IFPR.alunos
WHERE nota >= 7
ORDER BY nota DESC;
```
Filtra as notas a partir de 7 e apresenta as maiores primeiro. Resultado esperado: 11 alunos; inclui também quem não está matriculado.
## Consultas complementares do arquivo original
### Alunos matriculados em ordem alfabética
```sql
SELECT nome, curso, periodo
FROM IFPR.alunos
WHERE matriculado = TRUE
ORDER BY nome ASC;
```
Lista apenas os alunos com matrícula ativa.
### Matriculados com nota a partir de 7
```sql
SELECT nome, curso, nota
FROM IFPR.alunos
WHERE matriculado = TRUE AND nota >= 7
ORDER BY nota DESC;
```
Combina o filtro de matrícula com o filtro de nota.
### Matriculados com nota abaixo de 7
```sql
SELECT nome, curso, nota
FROM IFPR.alunos
WHERE matriculado = TRUE AND nota < 7
ORDER BY nota ASC;
```
Mostra primeiro as menores notas, para acompanhamento.
### Alunos de Análise e Desenvolvimento de Sistemas
```sql
SELECT nome, cidade, periodo, nota
FROM IFPR.alunos
WHERE curso = 'Análise e Desenvolvimento de Sistemas'
ORDER BY periodo ASC, nome ASC;
```
Filtra um curso e ordena por período e depois por nome.
### Matriculados residentes em Colombo
```sql
SELECT nome, curso, cidade, data_matricula
FROM IFPR.alunos
WHERE cidade = 'Colombo' AND matriculado = TRUE
ORDER BY nome ASC;
```
Lista os moradores de Colombo que estão matriculados.
### Contar moradores de Colombo separadamente
```sql
SELECT COUNT(*) AS moradores_colombo
FROM IFPR.alunos
WHERE cidade = 'Colombo';
```
Versão separada da contagem de moradores: resultado esperado 7.
### Contar moradores de outras cidades separadamente
```sql
SELECT COUNT(*) AS moradores_outras_cidades
FROM IFPR.alunos
WHERE cidade <> 'Colombo';
```
Versão separada da contagem de não moradores: resultado esperado 8.
## Consultas de conferência
### Verificar se a tabela existe
```sql
SELECT TABLE_SCHEMA, TABLE_NAME
FROM information_schema.TABLES
WHERE TABLE_SCHEMA = 'IFPR' AND TABLE_NAME = 'alunos';
```
Consulta o catálogo do servidor. Uma linha indica que a tabela foi encontrada.
### Conferir os dez atributos
```sql
DESCRIBE IFPR.alunos;
```
Mostra os nomes das colunas, tipos, chave e outras características da tabela.
### Conferir os quinze registros
```sql
SELECT COUNT(*) AS total_registros
FROM IFPR.alunos;
```
O total confirmado na atividade foi 15.
### Mostrar todos os dados por identificador
```sql
SELECT * FROM IFPR.alunos
ORDER BY id_aluno;
```
Mostra todas as colunas e ordena os alunos pelo identificador.
## Vocabulário rápido
| Comando | Função |
| --- | --- |
| SELECT | Escolher as colunas ou cálculos exibidos. |
| FROM | Indicar a tabela consultada. |
| WHERE | Filtrar linhas. |
| AND | Exigir várias condições ao mesmo tempo. |
| DISTINCT | Eliminar combinações repetidas no resultado. |
| `COUNT(*)` | Contar linhas. |
| SUM | Somar valores. |
| AVG | Calcular a média. |
| ROUND | Arredondar um número. |
| AS | Dar um nome à coluna do resultado. |
| GROUP BY | Agrupar linhas para calcular por grupo. |
| ORDER BY | Ordenar o resultado. |
| ASC / DESC | Ordenar de forma crescente / decrescente. |
