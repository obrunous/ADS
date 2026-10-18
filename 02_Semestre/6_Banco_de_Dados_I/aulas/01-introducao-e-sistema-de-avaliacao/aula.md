# Aula 01 - Introdução e sistema de avaliação

**Data:** 31/07/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d539815b8224f64c7808cbed)

> **Banco de Dados I**
> Professor: Dr. Ronan Assumpção Silva
> Data: 31/07/2026
## Objetivo da aula
Apresentar a disciplina de Banco de Dados I, explicar a ementa e o sistema de avaliação do semestre e introduzir o conceito de banco de dados e de Sistema de Gerenciamento de Banco de Dados (SGBD).
## Ementa da disciplina
A disciplina será desenvolvida progressivamente a partir dos seguintes conteúdos:
- Introdução a Banco de Dados.
- Modelagem e Projeto de Banco de Dados.
- Linguagens de Definição e Manipulação de Dados.
- Desenvolvimento de aplicações de Banco de Dados.
- Normalização.
- SQL Básico.
## Sistema de avaliação
A avaliação da disciplina será composta por quatro partes.
| Atividade | Pontuação | Como funciona |
| --- | --- | --- |
| Listas de exercícios | 10 pontos | Serão 4 listas, entregues sempre na última aula do mês. Serão considerados a entrega no prazo e a execução. |
| Prova objetiva | 40 pontos | Uma prova prevista para o mês de outubro. |
| Projeto prático | 40 pontos | Projeto em equipe de até 3 alunos, avaliado desde a execução até a apresentação. As apresentações começam em novembro. |
| Crítica a outro projeto | 10 pontos | Durante as apresentações, outra equipe será sorteada para realizar críticas e sugestões sobre o projeto apresentado. |
**Total: 100 pontos.**
## Conversão da nota para conceito
- **A:** entre 95 e 100 pontos.
- **B:** entre 85 e 94 pontos.
- **C:** entre 70 e 84 pontos.
- **D:** menos de 70 pontos.
## Recuperação
A recuperação permite aumentar o conceito obtido, porém somente **um conceito acima** do resultado anterior.
## O que é Banco de Dados?
O material introduz banco de dados por meio do conceito de **Sistema de Gerenciamento de Banco de Dados (SGBD)**. Um SGBD é composto por uma coleção de dados inter-relacionados e por um conjunto de programas utilizados para acessar esses dados.
A coleção de dados é normalmente chamada de **banco de dados** e contém informações relevantes para uma organização. O principal objetivo de um SGBD é permitir que essas informações sejam **armazenadas e recuperadas de maneira conveniente e eficiente**.
> **Ideia central da aula:** o banco de dados concentra informações relacionadas, enquanto o SGBD fornece os mecanismos para armazenar, organizar e acessar essas informações.
## Exemplos de aplicações de bancos de dados
### Universidades
Bancos de dados podem armazenar informações de alunos, matrículas em cursos, notas e também dados administrativos, como recursos humanos e contabilidade.
### Companhias aéreas
São utilizados para reservas e informações de agendamento. O material destaca que as companhias aéreas estiveram entre as primeiras organizações a utilizar bases de dados de forma geograficamente distribuída.
### Telecomunicações
São utilizados para manter registros de chamadas, gerar faturas mensais, gerenciar saldos e armazenar informações relacionadas às redes de comunicação.
## Como era e como é hoje
Os primeiros bancos de dados eram acessados por **redes locais**, ficando restritos ao espaço de uma empresa ou filial e sem comunicação ampla com o mundo externo.
Com a expansão da Internet, os bancos de dados passaram a operar em redes maiores e com maior possibilidade de acesso externo.
## Encadeamento da aula
1. Apresentação da disciplina e da ementa.
2. Explicação do sistema de avaliação.
3. Conversão de notas para conceitos e regra de recuperação.
4. Introdução ao conceito de banco de dados e SGBD.
5. Exemplos de aplicações reais.
6. Evolução do acesso aos bancos de dados: de redes locais para redes maiores conectadas pela Internet.
## Fechamento
A aula de 31/07/2026 encerra a parte introdutória da disciplina. A partir da aula seguinte, o material avança para diferenças entre bancos de dados relacionais e não relacionais e para o uso prático de ferramentas como XAMPP e MySQL Workbench.
---
## 🧪 Aplicação prática — Agenda Acadêmica
Nesta disciplina, a **Agenda Acadêmica** será utilizada como projeto-base para transformar os conceitos estudados em uma aplicação real. Neste primeiro dia, a aplicação ainda é **conceitual**: antes de criar tabelas, precisamos compreender qual problema o banco deverá resolver e quais informações o sistema precisará armazenar.
### Problema que o banco deverá resolver
A Agenda Acadêmica precisa persistir informações relacionadas à organização acadêmica do aluno, como usuários, períodos, disciplinas, páginas de anotações e compromissos. Em fases posteriores, o projeto também prevê aulas, faltas, frequência, avaliações, notas ou conceitos.
### Ligação com o conteúdo da aula
- **Banco de dados:** será o conjunto organizado das informações da Agenda Acadêmica.
- **SGBD:** o projeto utilizará **MySQL** para armazenar e recuperar essas informações.
- **Aplicação:** futuramente a aplicação web acessará esses dados por meio do servidor, em vez de manter as informações apenas na interface.
> **Etapa prática alcançada:** definição do problema e identificação inicial dos dados que precisarão ser persistidos. Ainda não vamos criar tabelas; a estrutura será construída conforme os conteúdos forem apresentados na disciplina.
### Caminho do projeto na disciplina
**problema → entidades → atributos → CREATE DATABASE → CREATE TABLE → INSERT → SELECT → UPDATE/DELETE → PK/FK → relacionamentos → DER/EER → normalização → consultas mais avançadas → integração com Node.js.**
