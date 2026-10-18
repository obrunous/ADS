# Aula 10 - DISCENTE, CURSA e DISCIPLINA no MySQL Workbench

**Data:** 25/09/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d53981adaf9bd6c97ca19f5d)

## Modelagem EER no MySQL Workbench
### 1. Tema da aula
Construção de um banco de dados a partir de um **diagrama EER no MySQL Workbench**, começando pela identificação das entidades, seus atributos e o relacionamento entre elas.
O exemplo desenvolvido pelo professor é:
**DISCENTE — CURSA — DISCIPLINA**
Nesse modelo:
- **DISCENTE** é uma entidade.
- **CURSA** é o relacionamento entre as entidades.
- **DISCIPLINA** é uma entidade.
A leitura do modelo é: **um discente cursa uma disciplina**.
---
### 2. Entidade DISCENTE
A entidade **DISCENTE** representa o aluno no modelo apresentado em aula.
Atributos registrados no quadro:
| Atributo | Observação |
| --- | --- |
| COD | Chave primária — PK |
| MATRÍCULA | Matrícula do discente |
| NOME | Nome do discente |
| CPF | CPF do discente |
| ENDEREÇO | Endereço do discente |
| TELEFONE | Telefone do discente |
| EMAIL | E-mail do discente |
A **chave primária (PK)** é utilizada para identificar cada registro de forma única. No modelo apresentado, o atributo indicado como chave primária é **COD**.
---
### 3. Entidade DISCIPLINA
A entidade **DISCIPLINA** representa uma disciplina.
Atributos registrados no quadro:
| Atributo | Observação |
| --- | --- |
| COD | Chave primária — PK |
| NOME | Nome da disciplina |
| CH | Carga horária |
Assim como em DISCENTE, o atributo **COD** aparece como chave primária.
---
### 4. Relacionamento CURSA
O professor representou a ligação entre as entidades da seguinte forma:
**DISCENTE — CURSA — DISCIPLINA**
**CURSA** expressa a associação existente entre um discente e uma disciplina.
No modelo conceitual trabalhado inicialmente:
**DISCENTE** → entidade  
**CURSA** → relacionamento  
**DISCIPLINA** → entidade
Portanto, CURSA descreve a ação que conecta as duas entidades.
---
### 5. Estrutura apresentada para CURSA
Na sequência, o professor representou **CURSA** com uma estrutura intermediária contendo:
| Campo | Observação registrada |
| --- | --- |
| COD | PK |
| COD_DISCENTE | Código relacionado ao discente |
| COD_DISCIPLINA | Código relacionado à disciplina |
Representação da aula:
**DISCENTE — CURSA — DISCIPLINA**
A estrutura de CURSA permite registrar a associação entre os registros de DISCENTE e DISCIPLINA.
> **Importante:** até este ponto do registro da aula, a imagem mostra COD como PK e os campos COD_DISCENTE e COD_DISCIPLINA. A cardinalidade e a marcação explícita desses campos como chaves estrangeiras não foram confirmadas no material fotografado e, por isso, não são registradas aqui como definição do professor.
---
### 6. Do modelo conceitual para a estrutura do banco
A sequência didática observada na aula é:
**Entidades → Relacionamento → Diagrama EER → Estrutura do banco**
Primeiro são identificados os objetos que precisam ser armazenados: **DISCENTE** e **DISCIPLINA**.
Depois é identificado o relacionamento existente entre eles: **CURSA**.
Em seguida, essas estruturas são representadas visualmente no **MySQL Workbench**, preparando o modelo para a implementação física do banco de dados.
---
### 7. Conceitos de Banco de Dados envolvidos
#### Entidade
É aquilo sobre o qual o sistema precisa armazenar informações.
Nesta aula:
**DISCENTE** e **DISCIPLINA**.
#### Atributo
É uma característica armazenada sobre uma entidade.
Exemplos da aula:
**NOME**, **CPF**, **MATRÍCULA**, **EMAIL** e **CH**.
#### Chave primária — PK
É o atributo indicado para identificar cada registro da tabela.
No modelo da aula:
**DISCENTE.COD**  
**DISCIPLINA.COD**  
**CURSA.COD**
#### Relacionamento
Representa uma associação entre entidades.
Nesta aula:
**CURSA**
Relacionando:
**DISCENTE ↔ DISCIPLINA**
---
### 8. Construção no MySQL Workbench
O objetivo prático é começar pelo **diagrama EER**, em vez de iniciar diretamente escrevendo comandos SQL.
No diagrama são representadas as estruturas observadas em aula:
**DISCENTE**
- COD — PK
- MATRÍCULA
- NOME
- CPF
- ENDEREÇO
- TELEFONE
- EMAIL
**CURSA**
- COD — PK
- COD_DISCENTE
- COD_DISCIPLINA
**DISCIPLINA**
- COD — PK
- NOME
- CH
Visualmente, o núcleo do exercício permanece:
**DISCENTE — CURSA — DISCIPLINA**
---
### 9. Exemplo de interpretação
Imagine um discente chamado João e uma disciplina chamada Banco de Dados I.
O modelo precisa armazenar João em **DISCENTE**, Banco de Dados I em **DISCIPLINA** e representar por meio de **CURSA** a associação entre os dois.
Assim, o banco não armazena apenas os dados isolados das entidades; ele também consegue representar como esses dados se relacionam.
---
### 10. Resumo para revisão
O ponto central desta aula é compreender que um banco de dados pode ser planejado visualmente antes da implementação.
O professor partiu de duas entidades:
**DISCENTE** e **DISCIPLINA**
e definiu entre elas o relacionamento:
**CURSA**
Formando:
**DISCENTE — CURSA — DISCIPLINA**
Depois, CURSA foi representado com **COD (PK)**, **COD_DISCENTE** e **COD_DISCIPLINA**, preparando a passagem da modelagem para a estrutura do banco no MySQL Workbench.
#### Para memorizar
**Entidade** = objeto sobre o qual armazenamos dados.  
**Atributo** = característica da entidade.  
**PK** = chave primária que identifica o registro.  
**Relacionamento** = associação entre entidades.  
**Modelo da aula** = **DISCENTE — CURSA — DISCIPLINA**.
> Aula construída com base no conteúdo registrado no quadro e nas explicações acompanhadas durante a aula de 25/09/2026.
