# Aula 09 - Chaves primária e estrangeira

**Data:** 21/09/2026

**Fonte:** [Página da aula no Notion](https://app.notion.com/p/3e2d0f04d53981b399e6dd209f7cc5a7)

[Imagem original do slide — referência interna do Notion](notion-file-block://a0b6ad30-3591-433d-b477-19c24f7d9f5d/c0bf735f-655a-4fa7-82fe-378646067e66?space_id=868c8a0f-731f-4650-9568-b8f82eef1040&name=relacionamento-cliente-ordem-servico-21-09-2026.png)

> A imagem permanece como referência ao Notion; não foi baixada para esta pasta.
## Objetivo da aula
Entender como duas tabelas se relacionam por meio de uma **chave primária (PK)** e uma **chave estrangeira (FK)**. Ao final, você deve conseguir ler cada parte do `CREATE TABLE`, identificar a tabela principal e a tabela dependente, e prever o que acontece quando um cliente é excluído.
**Fonte da aula:** foto do slide apresentada em 21/09/2026. O cenário `Cliente` e `Ordem_Servico` é um exemplo didático do professor, não uma estrutura confirmada do Sankhya OM.
## 1. Antes do SQL: o problema que o relacionamento resolve
Imagine dois cadastros:
- `Cliente`: guarda os dados de cada cliente.
- `Ordem_Servico`: guarda cada serviço solicitado e a identificação do cliente responsável.
Um cliente pode ter várias ordens de serviço. Cada ordem do exemplo aponta para, no máximo, um cliente. Esse é um relacionamento **um para muitos (1:N)**.
```text
Cliente (1) ────── (N) Ordem_Servico
Cod = 10                 cod = 101, cliente_cod = 10
                         cod = 102, cliente_cod = 10
```
O número `10` identifica o cliente. Nas ordens, `cliente_cod = 10` é a ligação com ele. Não precisamos copiar nome e endereço do cliente em cada ordem.
## 2. Vocabulário essencial
- **Tabela:** estrutura que organiza registros do mesmo tipo. Exemplo: `Cliente`.
- **Coluna ou atributo:** característica armazenada em cada registro. Exemplo: `Nome`.
- **Linha ou registro:** uma ocorrência concreta. Exemplo: o cliente de `Cod = 10`.
- **Chave primária (PK):** coluna ou conjunto de colunas que identifica cada linha de forma única. Seus valores não podem se repetir nem ser `NULL`.
- **Chave estrangeira (FK):** coluna da tabela dependente que referencia uma chave da tabela principal. Seus valores, quando não forem `NULL`, precisam corresponder a valores existentes na chave referenciada.
- **Tabela principal ou pai:** neste exemplo, `Cliente`. Ela contém o `Cod` referenciado.
- **Tabela dependente ou filha:** neste exemplo, `Ordem_Servico`. Ela contém `cliente_cod`.
- **Integridade referencial:** regra que evita ligações inválidas, como uma ordem apontar para um cliente inexistente.
## 3. Código do slide em uma forma executável no MySQL
A estrutura abaixo preserva a ideia do slide. Foram feitos ajustes de escrita: `Endereco` aparece sem acento e os comandos receberam ponto e vírgula. A observação sobre `CASCADE` foi separada do SQL.
```sql
CREATE TABLE Cliente (
    Cod INT NOT NULL,
    Nome VARCHAR(255) NOT NULL,
    Endereco VARCHAR(255) DEFAULT NULL,
    RG INT DEFAULT NULL,
    PRIMARY KEY (Cod)
) ENGINE=InnoDB;

CREATE TABLE Ordem_Servico (
    cod INT PRIMARY KEY AUTO_INCREMENT,
    data_os DATE NOT NULL,
    cliente_cod INT,
    CONSTRAINT fk_os_cliente
        FOREIGN KEY (cliente_cod)
        REFERENCES Cliente(Cod)
        ON DELETE RESTRICT
) ENGINE=InnoDB;
```
**Ordem de criação:** `Cliente` vem primeiro, porque `Ordem_Servico` faz referência a ela. `InnoDB` foi explicitado porque esse mecanismo aplica restrições de chave estrangeira no MySQL.
## 4. Lendo a tabela Cliente, parte por parte
`CREATE TABLE Cliente (` significa “crie uma tabela chamada Cliente”. O parêntese abre a lista de colunas e restrições.
`Cod INT NOT NULL,` define uma coluna chamada `Cod`. `INT` armazena números inteiros. `NOT NULL` exige um valor. Na foto aparece `INT(11)`; o `11` é uma largura de exibição antiga do MySQL, não o limite de 11 dígitos nem o tamanho em bytes. Esse atributo está obsoleto no MySQL moderno; por isso, aqui usamos `INT`.
`Nome VARCHAR(255) NOT NULL,` define um texto de comprimento variável de até 255 caracteres, obrigatório. `VARCHAR(255)` não obriga o nome a ter 255 caracteres; define o máximo.
`Endereco VARCHAR(255) DEFAULT NULL,` define um texto opcional. `DEFAULT NULL` indica que, se nenhum endereço for informado, o valor padrão será `NULL`. `NULL` representa ausência de valor; não é a palavra “NULL” nem uma string vazia. No slide, o identificador aparece como `Endereço`.
`RG INT DEFAULT NULL,` define um valor inteiro opcional no exemplo do slide. **Observação de modelagem:** RG é um identificador, não uma quantidade usada em cálculos. Em um sistema real, normalmente seria avaliado um tipo textual para preservar formatação e possíveis zeros à esquerda. Essa observação melhora a modelagem, mas não altera o que o professor mostrou.
`PRIMARY KEY (Cod)` torna `Cod` a chave primária. Isso impede dois clientes com o mesmo `Cod` e permite localizar um cliente sem ambiguidade.
`)` fecha a definição da tabela. `ENGINE=InnoDB` escolhe o mecanismo de armazenamento que aplica a FK neste exemplo. O ponto e vírgula `;` encerra o comando SQL. As vírgulas separam definições dentro dos parênteses; não há vírgula após a última definição.
## 5. Lendo a tabela Ordem_Servico, parte por parte
`CREATE TABLE Ordem_Servico (` cria a tabela das ordens. O sublinhado faz parte do nome escolhido para a tabela.
`cod INT PRIMARY KEY AUTO_INCREMENT,` define o identificador único de cada ordem. `PRIMARY KEY` é a mesma regra de unicidade vista em `Cliente`; `AUTO_INCREMENT` faz o MySQL gerar o próximo número ao inserir uma nova ordem sem informar `cod`. **Atenção:** `cod` identifica a ordem; `cliente_cod` identifica o cliente relacionado. São papéis diferentes.
`data_os DATE NOT NULL,` define uma data obrigatória para a ordem. `DATE` guarda data, sem hora. Um valor típico é `'2026-09-21'` no formato ano-mês-dia.
`cliente_cod INT,` define a coluna que receberá o `Cod` do cliente. Ela usa um tipo compatível com `Cliente.Cod`. Como o slide não colocou `NOT NULL`, uma ordem pode ter `cliente_cod = NULL` nessa estrutura. Se a regra do negócio exigir sempre um cliente, a coluna precisaria ser declarada `INT NOT NULL`.
`CONSTRAINT fk_os_cliente` dá um nome à restrição. O nome ajuda a reconhecê-la em mensagens de erro e na manutenção do banco. Ele não é o nome da coluna.
`FOREIGN KEY (cliente_cod)` declara que `cliente_cod` é a chave estrangeira da tabela `Ordem_Servico`. A FK é definida na tabela dependente, que guarda a referência.
`REFERENCES Cliente(Cod)` informa o destino da referência: tabela `Cliente`, coluna `Cod`. Leia o trecho completo como: “o valor de `Ordem_Servico.cliente_cod` deve apontar para `Cliente.Cod`”.
`ON DELETE RESTRICT` estabelece a reação quando alguém tenta excluir um cliente que possui ordens relacionadas. A exclusão desse cliente é rejeitada; as ordens e o cliente permanecem.
`)` fecha a tabela e `;` encerra o segundo comando. A FK não cria uma cópia do cliente: ela guarda somente o valor da ligação.
## 6. Chave primária e chave estrangeira lado a lado
| Tabela | Coluna | Papel | Exemplo |
| --- | --- | --- | --- |
| `Cliente` | `Cod` | PK: identifica o cliente | `10` |
| `Ordem_Servico` | `cod` | PK: identifica a ordem | `101` |
| `Ordem_Servico` | `cliente_cod` | FK: aponta para o cliente | `10` |
As duas tabelas têm suas próprias chaves primárias. A ligação ocorre entre `Ordem_Servico.cliente_cod` e `Cliente.Cod`. Os nomes das colunas não precisam ser iguais; os tipos devem ser compatíveis e a referência deve apontar para uma chave adequada.
## 7. O que o banco permite ou rejeita
Suponha que exista `Cliente.Cod = 10`.
1. **Inserir cliente 10:** permitido, se não houver outro cliente com `Cod = 10` e os campos obrigatórios forem preenchidos.
2. **Inserir uma ordem com `cliente_cod = 10`:** permitido, pois o cliente existe.
3. **Inserir uma ordem com `cliente_cod = 99`:** rejeitado se não existir `Cliente.Cod = 99`. A FK impede uma referência órfã.
4. **Inserir uma ordem com `cliente_cod = NULL`:** permitido por esta definição, pois a coluna não foi declarada `NOT NULL`.
5. **Excluir o cliente 10 enquanto houver ordem ligada a ele:** rejeitado por `ON DELETE RESTRICT`.
6. **Excluir um cliente sem ordens ligadas:** permitido, desde que nenhuma outra restrição do banco impeça a operação.
Essas regras são aplicadas pelo banco, inclusive se a operação vier de outra aplicação conectada ao mesmo banco.
## 8. RESTRICT e CASCADE: qual é a diferença?
A foto menciona `ON DELETE RESTRICT` e diz que existe a opção `CASCADE`.
| Regra | Se o cliente tem ordens e alguém tenta excluí-lo |
| --- | --- |
| `ON DELETE RESTRICT` | O MySQL recusa a exclusão do cliente. As ordens permanecem. |
| `ON DELETE CASCADE` | O MySQL exclui o cliente e também as ordens que o referenciam. |
A regra é escrita **na FK da tabela dependente**, mas é acionada pela tentativa de excluir uma linha **da tabela principal**. `CASCADE` pode apagar dados associados, por isso a escolha depende das regras do negócio. Em processos que precisam manter histórico de atendimento, excluir automaticamente ordens costuma exigir uma análise cuidadosa.
`ON DELETE` trata exclusões. `ON UPDATE`, que não aparece no slide, trata alterações na chave referenciada. São situações diferentes.
## 9. Consultas de leitura para visualizar o relacionamento
As consultas abaixo são para estudo. Elas apenas leem dados; não inserem, alteram ou excluem registros.
```sql
SELECT Cod, Nome
FROM Cliente;

SELECT cod, data_os, cliente_cod
FROM Ordem_Servico;

SELECT
    os.cod AS ordem,
    os.data_os,
    c.Cod AS cliente_codigo,
    c.Nome AS cliente_nome
FROM Ordem_Servico AS os
JOIN Cliente AS c
    ON os.cliente_cod = c.Cod;
```
Na última consulta, `JOIN` reúne as linhas das duas tabelas. `AS os` e `AS c` criam apelidos curtos. `ON os.cliente_cod = c.Cod` indica a condição da junção. A FK protege a integridade dos dados; o `JOIN` é a instrução de consulta que mostra os dados relacionados. Uma não substitui a outra.
## 10. Ligação com um ERP
**Exemplo hipotético de ERP:** uma empresa cadastra parceiros e registra pedidos. Cada pedido guarda o identificador do parceiro responsável. Esse caso ajuda a entender o mesmo padrão 1:N da aula: um parceiro pode aparecer em vários pedidos. A regra sobre excluir parceiros com pedidos depende de requisitos como histórico, auditoria e legislação aplicável. Este exemplo não afirma nomes de tabelas, campos ou regras específicas do Sankhya OM.
## 11. Erros comuns ao estudar este slide
- Confundir `Ordem_Servico.cod` com `Ordem_Servico.cliente_cod`: a primeira identifica a ordem; a segunda aponta para o cliente.
- Achar que `INT(11)` limita o número a 11 dígitos: não limita.
- Achar que `DEFAULT NULL` e `NOT NULL` fazem a mesma coisa: o primeiro permite ausência; o segundo exige valor.
- Declarar a FK antes de existir a tabela referenciada: crie `Cliente` primeiro.
- Pensar que a FK faz o `JOIN` automaticamente: a consulta precisa pedir a junção.
- Tratar `CASCADE` como uma opção sempre segura: ela pode remover várias linhas relacionadas.
- Copiar a observação do slide como parte do SQL: comentários e explicações devem ficar fora do comando ou usar sintaxe de comentário válida.
## 12. Exercícios de compreensão
1. Qual coluna identifica de forma única um cliente?
2. Qual coluna identifica de forma única uma ordem de serviço?
3. Qual coluna cria a ligação entre as duas tabelas?
4. Uma ordem pode apontar para um `Cod` que não existe em `Cliente`? Explique.
5. Na estrutura do slide, `cliente_cod` pode ser `NULL`? Qual mudança exigiria um cliente em toda ordem?
6. Se o cliente 10 tem duas ordens, o que acontece ao tentar excluí-lo com `RESTRICT`?
7. O que mudaria se a FK usasse `ON DELETE CASCADE`?
8. Para mostrar o nome do cliente ao lado da data da ordem, a consulta precisa de FK, `JOIN` ou ambos? Explique a função de cada um.
### Respostas para conferir depois de tentar
1. `Cliente.Cod`.
2. `Ordem_Servico.cod`.
3. `Ordem_Servico.cliente_cod`, que referencia `Cliente.Cod`.
4. Não, quando a FK está ativa; o banco rejeita a referência sem cliente correspondente.
5. Sim, porque não há `NOT NULL`; declarar `cliente_cod INT NOT NULL` exigiria valor.
6. A exclusão é rejeitada; cliente e ordens permanecem.
7. As ordens relacionadas seriam excluídas junto com o cliente.
8. A FK mantém a integridade da ligação; o `JOIN` reúne os dados para exibição. O `JOIN` é necessário na consulta, e a FK é a regra de integridade definida na tabela.
## Fontes
- Foto do slide da aula de 21/09/2026, fornecida pelo aluno.
- [Manual MySQL 8.4 — Restrições de chave estrangeira](https://dev.mysql.com/doc/refman/8.4/en/create-table-foreign-keys.html)
- [Manual MySQL 8.4 — CREATE TABLE e AUTO_INCREMENT](https://dev.mysql.com/doc/refman/8.4/en/create-table.html)
- [Manual MySQL 8.4 — Atributos numéricos e largura de exibição](https://dev.mysql.com/doc/refman/8.4/en/numeric-type-attributes.html)
- [Manual MySQL 8.4 — CHAR e VARCHAR](https://dev.mysql.com/doc/refman/8.4/en/char.html)
## 13. A segunda foto: o diagrama EER no MySQL Workbench
A foto mostra a representação **visual** das tabelas `cliente` e `ordem_servico` no MySQL Workbench. É a mesma estrutura de relacionamento estudada no slide SQL: `ordem_servico.cliente_cod` referencia `cliente.Cod`. O desenho ajuda a enxergar a relação, enquanto o `CREATE TABLE` mostra como ela é declarada em SQL.
### Como ler as caixas
- Cada caixa representa **uma tabela**.
- O nome no topo identifica a tabela: `cliente` à esquerda e `ordem_servico` à direita.
- Cada linha dentro da caixa é uma **coluna**, acompanhada de seu tipo: `INT(11)`, `VARCHAR(255)` ou `DATE`.
- O ícone de **chave** ao lado de `cliente.Cod` e de `ordem_servico.cod` marca as respectivas chaves primárias. Cada tabela tem sua própria PK.
- A coluna `ordem_servico.cliente_cod` é a chave estrangeira usada para ligar a ordem ao cliente. O ícone dela não substitui a definição `FOREIGN KEY ... REFERENCES ...`; a ligação é confirmada pela linha entre as tabelas e pelo modelo.
- A faixa `Indexes` é a área do diagrama onde o Workbench mostra índices. Ela não é uma terceira tabela nem contém registros de clientes ou ordens.
### Como ler a linha entre as caixas
A linha parte da tabela `cliente`, lado **1**, e chega à tabela `ordem_servico`, lado **N** (o símbolo parecido com um pé de galinha). Isso representa a possibilidade de **um cliente estar associado a várias ordens de serviço**. Uma ordem com `cliente_cod` preenchido aponta para um cliente específico.
A linha **tracejada** mostrada na foto indica, na terminologia do Workbench, um relacionamento **não identificador**: `ordem_servico` tem sua própria chave primária `cod`, e `cliente_cod` não faz parte dessa PK. Se a chave do cliente participasse da identificação primária da ordem, o relacionamento poderia ser modelado como identificador, representado por linha contínua.
**Atenção à obrigatoriedade:** a cardinalidade 1:N descreve a quantidade possível de ordens por cliente. No SQL do slide, `cliente_cod` não recebeu `NOT NULL`; por isso, o banco também permite uma ordem sem cliente informado. O desenho sozinho não deve ser usado para concluir que essa coluna é obrigatória. Para ter certeza, confira a definição da coluna e as propriedades do relacionamento no Workbench.
### Ligando o desenho ao SQL
| No diagrama | No SQL do slide | Significado |
| --- | --- | --- |
| Caixa `cliente` | `CREATE TABLE Cliente` | Cadastro principal |
| Chave ao lado de `Cod` | `PRIMARY KEY (Cod)` | Identificador único do cliente |
| Caixa `ordem_servico` | `CREATE TABLE Ordem_Servico` | Registro das ordens |
| Chave ao lado de `cod` | `cod INT PRIMARY KEY AUTO_INCREMENT` | Identificador único da ordem |
| Coluna `cliente_cod` e linha de ligação | `FOREIGN KEY (cliente_cod) REFERENCES Cliente(Cod)` | Referência ao cliente |
| Linha tracejada | `cliente_cod` fora da PK de `Ordem_Servico` | Relacionamento não identificador |
**Exemplo visual:** se a caixa `cliente` contém o cliente de `Cod = 10`, várias linhas de `ordem_servico` podem mostrar `cliente_cod = 10`. Cada ordem continua tendo um `cod` próprio, como 101 e 102.
### Engenharia reversa no Workbench
Sua anotação menciona engenharia reversa. Ela é o caminho para **gerar um modelo/diagrama a partir de tabelas que já existem no banco**. O movimento contrário é partir de um modelo e gerar o SQL para criar as tabelas. É importante não confundir apenas *desenhar* as caixas com criar fisicamente as tabelas no servidor; o diagrama pode representar um modelo que ainda não foi aplicado ao banco.
### Campo `descricao` mencionado nas anotações
Sua anotação também propõe adicionar `descricao` à ordem de serviço para registrar o conteúdo da OS. Como exemplo didático, ele poderia ser declarado `descricao VARCHAR(255)`, se esse limite atender ao conteúdo esperado. Esse campo **não aparece na segunda foto**; é uma proposta de evolução do exercício, não uma coluna já confirmada no diagrama fotografado.
### Fontes para os símbolos do Workbench
- [Manual MySQL Workbench — Relacionamentos em diagramas EER](https://dev.mysql.com/doc/workbench/en/wb-relationship-tools.html)
- [Manual MySQL Workbench — Tabelas e ícones no diagrama](https://dev.mysql.com/doc/workbench/en/wb-using-table-tool.html)
- [Manual MySQL Workbench — Editor do relacionamento](https://dev.mysql.com/doc/workbench/en/wb-relationship-editor.html)
- [Manual MySQL Workbench — Engenharia reversa](https://dev.mysql.com/doc/workbench/en/wb-reverse-engineer-live.html)
