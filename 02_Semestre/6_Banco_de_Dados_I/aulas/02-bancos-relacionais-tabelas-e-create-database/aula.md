# Aula 02 - Bancos relacionais, tabelas e CREATE DATABASE

**Data:** 07/08/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3aed0f04d539813fb1edd58725dfd3e9)

> **Banco de Dados I**
> Professor: Dr. Ronan Assumpção Silva
> Data: 07/08/2026
## Objetivo da aula
Avançar da introdução conceitual da disciplina para o primeiro contato prático com o ambiente de banco de dados, diferenciando bancos relacionais e não relacionais e configurando o MySQL para criar e manipular um banco de dados.
## 1. Bancos de dados relacionais e não relacionais
A aula inicia com a apresentação das **diferenças entre bancos de dados relacionais e não relacionais**.
### Banco de dados relacional
No modelo relacional, as informações são organizadas em **tabelas**. Essas tabelas estruturam os dados em linhas e colunas e servem de base para o trabalho posterior com SQL.
### Banco de dados não relacional
O material apresenta o tema em contraste com o modelo relacional, introduzindo a ideia de que nem todo banco de dados precisa organizar suas informações segundo a estrutura tradicional de tabelas.
> **Ponto central da aula:** compreender que existem diferentes formas de organizar dados e que, nesta disciplina, o ambiente prático utilizado será o MySQL.
## 2. Ferramentas utilizadas
O professor apresenta duas ferramentas para o ambiente prático:
- **XAMPP** — utilizado para iniciar o serviço do MySQL.
- **MySQL Workbench** — utilizado para conectar-se ao MySQL, visualizar bancos existentes, criar novos bancos e executar comandos SQL.
## 3. Iniciando o MySQL pelo XAMPP
Antes de utilizar o MySQL Workbench, o serviço do banco de dados precisa estar em execução.
### Situação 1 — MySQL desligado
Quando o botão exibido no XAMPP está como **Start**, o MySQL está desligado.
### Situação 2 — MySQL ligado
Após iniciar o serviço, o botão passa a mostrar **Stop**. Isso indica que o banco de dados MySQL está em execução.
> A lógica é simples: **Start = serviço parado** e **Stop = serviço em execução**.
## 4. Abrindo o MySQL Workbench
Depois de iniciar o MySQL, o próximo passo é abrir o **MySQL Workbench**.
O Workbench funciona como a interface gráfica utilizada para trabalhar com o servidor MySQL. A partir dele é possível criar conexões, visualizar schemas, executar comandos e acompanhar a estrutura do banco de dados.
## 5. Criando uma conexão com o MySQL
Na tela inicial do Workbench, o professor orienta a criação de uma nova conexão.
### Passo 1 — adicionar conexão
Na área **MySQL Connections**, clicar no botão **+**.
### Passo 2 — definir o nome
O material utiliza o nome:
```text
ConexaoBDMySQL
```
### Passo 3 — testar a conexão
Clicar em **Test Connection**.
Durante o teste, o material mostra uma mensagem de aviso de compatibilidade. A orientação apresentada é clicar em **Continue Anyway**.
Em seguida, aparece a confirmação de sucesso da conexão entre o **MySQL Workbench** e o **Banco de Dados MySQL**.
### Passo 4 — concluir
Após o teste bem-sucedido, clicar em **OK** para salvar a conexão.
## 6. Conexão criada com sucesso
Depois da configuração, a conexão **ConexaoBDMySQL** passa a aparecer na tela inicial do Workbench.
Ao abrir essa conexão, o usuário entra no ambiente no qual os bancos de dados serão criados e manipulados.
## 7. Identificando os bancos de dados existentes
Dentro do Workbench, o professor orienta clicar em **Schemas**.
A seção **Schemas** apresenta os bancos de dados já registrados no servidor MySQL.
> No contexto do MySQL mostrado no material, o termo **schema** é utilizado para representar o banco de dados listado no servidor.
## 8. Criando um novo banco de dados
O material demonstra a criação de um novo banco de dados utilizando a interface gráfica do Workbench.
### Passo 1 — criar novo schema
Clicar na opção **Create new schema in the connected server**.
### Passo 2 — nomear o banco
O professor utiliza o padrão:
```text
BD_SeuNome
```
### Passo 3 — aplicar
Após informar o nome:
1. Clicar em **Apply**.
2. Conferir o comando SQL que será executado.
3. Clicar novamente em **Apply**.
4. Finalizar o processo.
O Workbench mostra que, por trás da interface gráfica, está sendo executada uma instrução SQL de criação do schema.
## 9. Conferindo a criação em Schemas
Depois da criação, o novo banco deve aparecer na lista de **Schemas**.
Se ele ainda não estiver visível, o professor orienta utilizar o botão de **atualização** da lista.
## 10. Definindo o banco como padrão
Depois que o banco foi criado, ele deve ser definido como schema padrão.
### Procedimento
1. Clicar com o botão direito sobre o banco criado.
2. Selecionar **Set as Default Schema**.
Essa etapa é indicada no material como **obrigatória**.
O schema padrão passa a ser o banco sobre o qual os próximos comandos serão executados, salvo quando outro banco for explicitamente informado.
## 11. Introdução à aba Query
Com o banco criado e selecionado como padrão, o professor introduz a área de comandos SQL do Workbench.
Na aba **Query**, é possível escrever instruções SQL e executá-las diretamente no servidor.
### Execução de uma instrução
O material orienta usar o botão de execução identificado pelo **relâmpago com a letra I**.
Esse recurso executa somente a instrução na qual o cursor está posicionado naquele momento.
### Regra importante
As instruções SQL devem ser encerradas com **ponto e vírgula**:
```sql
;
```
> **Atenção:** ao escrever comandos SQL no Workbench, lembre-se de encerrar cada instrução com ponto e vírgula.
## 12. Fluxo completo praticado na aula
```text
Iniciar o MySQL no XAMPP
↓
Abrir o MySQL Workbench
↓
Criar uma conexão
↓
Testar a conexão
↓
Abrir Schemas
↓
Criar um novo banco de dados
↓
Definir o banco como Default Schema
↓
Abrir a aba Query
↓
Executar instruções SQL
```
## Conceitos essenciais do dia
- **MySQL**: sistema de banco de dados utilizado nas aulas práticas.
- **MySQL Workbench**: interface utilizada para administrar e trabalhar com o MySQL.
- **Schema**: banco de dados visualizado na seção Schemas do Workbench.
- **Conexão**: configuração que permite ao Workbench acessar o servidor MySQL.
- **Default Schema**: banco definido como padrão para a execução das próximas instruções.
- **Query**: área na qual os comandos SQL são escritos e executados.
## Resumo da aula
Nesta aula, o conteúdo avançou da comparação entre **bancos relacionais e não relacionais** para a preparação efetiva do ambiente de desenvolvimento. O professor apresentou o XAMPP e o MySQL Workbench, mostrou como iniciar o MySQL, configurar e testar uma conexão, identificar os schemas existentes, criar um novo banco de dados, defini-lo como padrão e começar a utilizar a aba **Query** para execução de instruções SQL.
> **Marco de aprendizagem:** ao final desta aula, o ambiente MySQL está configurado e pronto para que as próximas aulas avancem para a criação de tabelas e manipulação dos dados.
---
## 🧪 Aplicação prática — Agenda Acadêmica
Nesta aula, o conteúdo já permite dar o **primeiro passo técnico** no banco da Agenda Acadêmica. Como o projeto será implementado com **MySQL**, podemos criar o banco que servirá de contêiner para as tabelas desenvolvidas nas próximas aulas.
### 1. Banco relacional no projeto
A Agenda Acadêmica possui informações naturalmente relacionadas entre si: um usuário possui períodos; períodos organizam disciplinas; disciplinas possuem páginas e compromissos. Por isso, o projeto será trabalhado como um **banco de dados relacional**.
### 2. Criando o banco da Agenda Acadêmica
Aplicando o conceito de `CREATE DATABASE` estudado no dia:
```sql
CREATE DATABASE agenda_academica;
```
Depois da criação, no MySQL Workbench, o banco pode ser localizado em **Schemas** e definido como **Default Schema** para os próximos exercícios.
### 3. O que ainda não será criado
Mesmo que a documentação do projeto já preveja estruturas como `usuarios`, `periodos`, `disciplinas`, `paginas` e eventos/tarefas, **não vamos antecipar a criação dessas tabelas nesta aula**. O objetivo é respeitar a progressão da disciplina.
> **Etapa prática alcançada:** problema definido → escolha do modelo relacional → criação do banco `agenda_academica`. Próximo passo: transformar as informações do sistema em tabelas quando `CREATE TABLE` for trabalhado.
### Progresso do projeto
**problema → entidades → atributos → `CREATE DATABASE` ✅ → CREATE TABLE → INSERT → SELECT → UPDATE/DELETE → PK/FK → relacionamentos → DER/EER → normalização → consultas mais avançadas → integração com Node.js.**
