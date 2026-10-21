# Sistema de Controle de Ativos de TI — Contexto central do projeto

Documento central de domínio, análise e direcionamento do projeto, destinado a Bruno e às IAs que apoiam sua evolução.

**Data de consolidação:** 20/10/2026.  
**Fonte:** contexto fornecido por Bruno para esta documentação.  
**Escopo desta entrega:** documentação; nenhuma implementação ou alteração no projeto de software.

## Como interpretar este documento

- **Contexto relatado:** processos atuais e caso real descritos por Bruno. Não representam uma inspeção independente do ERP, das planilhas ou do código.
- **Direcionamento desejado:** fluxo futuro, módulos e stack inicial considerados para o novo sistema.
- **Proposta:** regras e modelos que precisam de análise e validação antes de implementação.
- **PENDENTE DE DECISÃO:** ponto ainda sem definição confirmada, especialmente unicidade, cardinalidades, estados e transições.
- **Estado local informado:** a descrição de que o projeto começa do zero é o estado fornecido por Bruno; o diretório do projeto não foi inspecionado nesta entrega.

Este sistema é distinto do projeto “Aplicativo Mobile e Web de Gerenciamento Pessoal com IA Integrada”. O contexto e a stack deste documento pertencem ao Sistema de Controle de Ativos de TI.

## Sumário

- 1. Identificação do projeto
- 2. Contexto empresarial
- 3. Problema atual
- 4. Novo conceito de estoque
- 5. Cadastro x movimentação
- 6. Utilização de equipamentos
- 7. Caso real identificado
- 8. Frontend, backend e banco
- 9. API
- 10. Módulos previstos
- 11. Entidades conceituais iniciais
- 12. Status
- 13. Regras de negócio iniciais
- 14. Banco de dados
- 15. Dados legados
- 16. Sankhya OM/ERP
- 17. Segurança
- 18. Engenharia de Software
- 19. Desenvolvimento incremental
- 20. Responsabilidades
- 21. Integração com TADS
- 22. Fluxo completo desejado do ativo
- 23. Estado atual do projeto
- 24. Objetivo acadêmico da documentação

---

## 1. Identificação do projeto

Nome:
Sistema de Controle de Ativos de TI

Diretório principal do projeto:

`/Users/brunoalves/Documents/sistema_controle_ativos_TI`

Objetivo:
Criar um sistema web empresarial para controlar ativos de TI durante todo o seu ciclo de vida.

Stack inicial:
- HTML
- CSS
- JavaScript
- PHP
- MySQL

Ferramentas:
- VS Code
- MySQL Workbench
- Git

## 2. Contexto empresarial

O sistema nasce de processos reais existentes na empresa.

Hoje existem controles relacionados a:
- equipamentos
- computadores
- celulares
- linhas telefônicas
- utilização de equipamentos
- empresas
- filiais
- colaboradores
- usuários
- termos em PDF

Existem dados legados em planilhas e processos já existentes em ERP.

## 3. Problema atual

Hoje um aparelho muitas vezes só é cadastrado quando vai ser enviado para uma loja ou colaborador.

Exemplo:

A empresa compra 25 celulares.

Eles chegam fisicamente, mas ainda não existem individualmente no sistema.

Quando um celular vai ser enviado:
- o aparelho é cadastrado
- é gerado um ID
- é vinculado a uma utilização
- é enviado

Problema:
o sistema não consegue mostrar corretamente o saldo físico antes do envio.

Não conseguimos responder facilmente:
- quantos aparelhos entraram
- quantos ainda estão em estoque
- quantos saíram
- quando saíram
- para qual loja
- para qual colaborador
- qual chamado originou a saída
- quem realizou a operação
- qual o histórico do aparelho

## 4. Novo conceito de estoque

O novo sistema deverá controlar o ativo desde o RECEBIMENTO.

Fluxo desejado:

```text
COMPRA
→ RECEBIMENTO
→ ENTRADA NO ESTOQUE
→ CADASTRO DOS ATIVOS
→ DISPONÍVEL EM ESTOQUE
→ CHAMADO / SOLICITAÇÃO
→ SEPARAÇÃO
→ SAÍDA
→ ENVIO
→ UTILIZAÇÃO
→ DEVOLUÇÃO / TRANSFERÊNCIA / MANUTENÇÃO / BAIXA
→ HISTÓRICO
```

O saldo não deve ser apenas um campo manual.

O saldo deve ser consequência das movimentações.

Exemplo:

Entrada: +25
Saída: -5
Devolução: +1

Saldo atual: 21

Também deve existir controle individual dos aparelhos.

Exemplo:

Equipamento 1001 → Em estoque
Equipamento 1002 → Em uso
Equipamento 1003 → Em manutenção

## 5. Cadastro x movimentação

Separar claramente:

CADASTROS:
- empresa
- filial
- colaborador
- usuário
- equipamento
- tipo de equipamento
- fabricante
- modelo
- linha telefônica
- operadora

MOVIMENTAÇÕES:
- entrada
- saída
- transferência
- entrega
- devolução
- manutenção
- baixa
- utilização

Regra importante:
histórico não deve ser apagado ou sobrescrito.

## 6. Utilização de equipamentos

Existe o conceito de Utilização de Equipamentos.

Ele representa o vínculo entre:
- equipamento
- colaborador
- empresa
- linha telefônica, quando aplicável
- data de entrega
- data de devolução
- responsável pela operação
- data/hora
- observação

Relacionamento conceitual:

```text
EQUIPAMENTO
1:N
UTILIZACAO_EQUIPAMENTO
N:1
COLABORADOR
```

Uma utilização aberta normalmente é aquela sem data de devolução.

## 7. Caso real identificado

Na empresa aconteceu o seguinte:

1. Um equipamento foi cadastrado.
2. Um usuário foi vinculado ao equipamento em Utilização de Equipamentos.
3. Foi gerado um termo em PDF.
4. O PDF mostrava dados do usuário, mas não mostrava os dados do equipamento/utilização.
5. Foi identificado que o equipamento estava INATIVO.
6. O equipamento foi alterado para ATIVO.
7. O PDF foi gerado novamente.
8. As informações apareceram corretamente.

Isso revelou uma dependência entre:
- cadastro
- status ativo/inativo
- utilização
- backend
- banco de dados
- geração de PDF
- regra de negócio

Regra proposta:
equipamento inativo não deve receber nova utilização.

Mas equipamentos inativos devem continuar aparecendo em históricos antigos.

O sistema também deve evitar gerar documentos silenciosamente incompletos.

## 8. Frontend, backend e banco

Arquitetura conceitual:

FRONTEND
HTML + CSS + JavaScript
```text

↓
```

BACKEND
PHP
```text

↓
```

REGRAS DE NEGÓCIO
```text

↓
```

BANCO DE DADOS
MySQL

Conceito simples:

**Frontend = pede**

**Backend = decide, valida e executa**

**Banco = guarda os dados**

Exemplo:

Usuário clica em "Ativar equipamento"

Frontend:
manda o pedido

Backend:
- recebe o pedido
- identifica o equipamento
- valida regras
- executa a operação

Banco:
altera o registro

Backend:
retorna resposta

Frontend:
mostra "Equipamento ativado"

## 9. API

API é a porta organizada pela qual frontend e outros sistemas podem conversar com o backend.

Analogia:

Frontend = cardápio / cliente

API = garçom

Backend = cozinha

Database = estoque/registros

A API não é obrigatória para o sistema funcionar, mas facilita:
- separação de responsabilidades
- integração com outros sistemas
- app futuro
- GLPI
- ERP
- dashboards
- integrações externas

## 10. Módulos previstos

Organizar o sistema em módulos:

### Base
- login
- usuários
- permissões
- empresas
- filiais

### Pessoas
- colaboradores
- empresa
- filial
- situação

### Equipamentos
- cadastro
- tipo
- fabricante
- modelo
- IMEI
- serial
- service tag
- hostname
- ativo/inativo
- status operacional

### Telefonia
- linhas
- números
- tipos
- operadoras
- histórico
- empresa
- usuário

### Estoque
- entrada
- recebimento
- saldo
- movimentação
- saída
- transferência
- devolução
- baixa

### Utilização
- vínculo equipamento/colaborador
- data entrega
- data devolução
- empresa
- linha
- histórico

### Chamados
- referência do chamado
- movimentação relacionada
- destino
- equipamento

### Termos
- geração em PDF
- usuário
- equipamento
- IMEI
- serial
- data
- empresa
- responsável

### Auditoria
- quem fez
- o que fez
- quando
- registro afetado
- valor anterior
- valor novo

### Dashboard e relatórios
- total de equipamentos
- equipamentos em estoque
- equipamentos em uso
- equipamentos em manutenção
- equipamentos inativos
- por empresa
- por filial
- por modelo
- por colaborador
- entradas
- saídas
- movimentações

## 11. Entidades conceituais iniciais

Considerar inicialmente:

- EMPRESA
- FILIAL
- COLABORADOR
- USUARIO_SISTEMA
- TIPO_EQUIPAMENTO
- FABRICANTE
- MODELO_EQUIPAMENTO
- EQUIPAMENTO
- EQUIPAMENTO_COMPUTADOR
- EQUIPAMENTO_MOVEL
- LINHA_TELEFONICA
- OPERADORA
- ENTRADA_ESTOQUE
- MOVIMENTACAO_ESTOQUE
- UTILIZACAO_EQUIPAMENTO
- CHAMADO
- AUDITORIA

IMPORTANTE:
não transformar automaticamente isso em tabelas físicas.

Primeiro analisar:
- entidades
- atributos
- chaves
- relacionamentos
- cardinalidades
- normalização
- integridade
- histórico

## 12. Status

Separar:

ATIVO / INATIVO

de

STATUS OPERACIONAL.

Exemplos possíveis de status operacional:

- EM_ESTOQUE
- RESERVADO
- EM_TRANSITO
- EM_USO
- EM_MANUTENCAO
- DEVOLVIDO
- BAIXADO

Esses status ainda precisam ser validados antes de implementação definitiva.

## 13. Regras de negócio iniciais

Registrar como propostas:

- equipamento inativo não deve receber nova utilização
- equipamento em uso não deve ser entregue novamente
- IMEI deve ser analisado para unicidade
- serial deve ser analisado para unicidade
- service tag deve ser analisado para unicidade
- hostname deve ser analisado para unicidade
- utilização encerrada deve manter histórico
- saída deve registrar destino
- saída deve registrar data
- saída deve registrar responsável
- saída pode ser relacionada a chamado
- devolução deve encerrar a utilização atual
- movimentações importantes devem gerar histórico
- histórico não deve ser apagado

Onde houver dúvida, marcar como:
PENDENTE DE DECISÃO

## 14. Banco de dados

Aplicar conceitos de Banco de Dados:

- entidade
- atributo
- domínio
- tupla
- relação
- esquema
- instância
- chave primária
- chave candidata
- chave estrangeira
- integridade de entidade
- integridade referencial
- cardinalidade
- relacionamento
- normalização
- dependência funcional
- SQL
- DDL
- DML
- SELECT
- JOIN
- INSERT
- UPDATE
- DELETE
- NULL
- transações
- histórico
- auditoria

## 15. Dados legados

Existem dados legados provenientes de controles como:

- Cadastro de Equipamentos
- Cadastro de Linha Telefônica
- Utilização de Equipamentos

Não assumir que todos os dados estão corretos.

Fluxo antes da migração:

```text
ANALISAR
→ SANEAR
→ VALIDAR
→ CORRIGIR
→ IMPORTAR
```

## 16. Sankhya OM/ERP

Parte do aprendizado e entendimento do domínio vem do Sankhya OM/ERP.

Nunca inventar:
- tabelas Sankhya
- campos físicos
- APIs
- endpoints
- classes
- parâmetros
- regras internas
- estrutura física do banco

Sempre separar:

[OBSERVADO]
informação realmente vista na tela/documentação fornecida.

[MODELO DIDÁTICO]
estrutura criada apenas para estudar Banco de Dados ou Engenharia de Software.

[INFORMAÇÃO REAL DO SANKHYA]
informação confirmada na documentação oficial.

Nunca transformar inferência em afirmação sobre a estrutura interna do Sankhya.

## 17. Segurança

Aplicar desde o início:

- prepared statements
- validação no backend
- controle de acesso
- hash de senha
- configuração separada
- tratamento de erros
- auditoria
- princípio do menor privilégio

Nunca:
- concatenar entrada do usuário diretamente em SQL
- armazenar senha em texto puro
- expor credenciais do banco no frontend
- permitir conexão direta JavaScript → MySQL

## 18. Engenharia de Software

O projeto deve seguir:

```text
ENTENDER
→ ANALISAR
→ MODELAR
→ ESPECIFICAR
→ IMPLEMENTAR
→ TESTAR
→ VALIDAR
→ DOCUMENTAR
→ EVOLUIR
```

Antes de cada funcionalidade:

1. entender o problema
2. escrever requisito
3. definir regra de negócio
4. identificar entidades
5. analisar impacto no banco
6. definir fluxo
7. definir backend
8. definir frontend
9. definir testes
10. implementar
11. validar
12. documentar

## 19. Desenvolvimento incremental

Não implementar tudo de uma vez.

Cada tarefa deve ser pequena e possuir:

- código da tarefa
- objetivo
- contexto
- escopo
- arquivos envolvidos
- requisitos
- regras de negócio
- critérios de aceite
- testes
- resultado esperado

Exemplo:

TEC-001
Preparar estrutura inicial do projeto

TEC-002
Configurar conexão segura com MySQL

TEC-003
Criar módulo de empresas

TEC-004
Criar módulo de equipamentos

TEC-005
Criar movimentação de estoque

Cada tarefa deve ser concluída, testada e validada antes da próxima.

## 20. Responsabilidades

### Bruno
- executor humano
- analista do processo real
- conhece o ambiente da empresa
- executa comandos
- testa
- valida
- identifica problemas
- toma decisões junto com a engenharia

### ChatGPT
- Engenharia de Software
- arquitetura
- requisitos
- regras de negócio
- modelagem
- DER
- decisões técnicas
- divisão das tarefas
- revisão da implementação

### Claude / Codex / IA programadora
- implementação
- criação de arquivos
- PHP
- JavaScript
- HTML
- CSS
- SQL
- testes
- refatoração solicitada

A IA programadora não deve alterar a arquitetura global sem validação.

## 21. Integração com TADS

Este sistema também é projeto de aprendizado do curso de Tecnologia em Análise e Desenvolvimento de Sistemas.

Relacionar o projeto, quando fizer sentido, com:

- Algoritmos
- Banco de Dados
- Engenharia de Software
- Desenvolvimento Web
- Estrutura de Dados
- Orientação a Objetos
- Redes
- Sistemas Operacionais
- Segurança
- Gestão de Projetos
- Estatística
- Inteligência Artificial

Não adicionar tecnologias artificialmente apenas para cumprir disciplinas.

O foco é aplicar os conceitos.

## 22. Fluxo completo desejado do ativo

Representar no documento:

```text
COMPRA
↓
RECEBIMENTO
↓
ENTRADA
↓
CADASTRO
↓
ESTOQUE
↓
SOLICITAÇÃO
↓
CHAMADO
↓
SEPARAÇÃO
↓
SAÍDA
↓
ENVIO
↓
LOJA / COLABORADOR
↓
UTILIZAÇÃO
↓
DEVOLUÇÃO
↓
ESTOQUE
```

Também prever:

```text
UTILIZAÇÃO
→ TRANSFERÊNCIA
```

```text
UTILIZAÇÃO
→ MANUTENÇÃO
```

```text
UTILIZAÇÃO
→ BAIXA
```

## 23. Estado atual do projeto

O projeto local:

`/Users/brunoalves/Documents/sistema_controle_ativos_TI`

está começando do zero.

Ainda não existe implementação consolidada.

Já existe bastante levantamento de domínio.

Portanto a próxima etapa NÃO deve ser gerar o sistema inteiro.

Próximas etapas:

1. consolidar requisitos
2. consolidar regras de negócio
3. fechar processos
4. definir entidades
5. definir relacionamentos
6. definir cardinalidades
7. desenhar DER v1.0
8. definir arquitetura inicial
9. dividir desenvolvimento em módulos
10. começar implementação incremental

## 24. Objetivo acadêmico da documentação

Esse arquivo também pertence à disciplina de Engenharia de Software.

Por isso organize o documento relacionando:

```text
problema
→ requisito
→ regra de negócio
→ caso de uso
→ entidade
→ arquitetura
→ implementação
→ teste
```

O documento deve servir como histórico da evolução do projeto.

### Rastreabilidade inicial para refinamento

A tabela a seguir é um **modelo didático proposto**, não uma especificação aprovada nem uma definição de tabelas físicas. Todos os vínculos precisam ser validados com o processo real.

| Problema ou necessidade | Requisito candidato | Regra proposta ou pendência | Caso de uso candidato | Entidades conceituais | Arquitetura e implementação futura | Teste/critério de aceite candidato |
| --- | --- | --- | --- | --- | --- | --- |
| Ativos só aparecem quando são enviados | Registrar recebimento e identificar os ativos antes da saída | Definir quando a entrada passa a compor o saldo; PENDENTE DE DECISÃO | Registrar Recebimento | ENTRADA_ESTOQUE, EQUIPAMENTO, MOVIMENTACAO_ESTOQUE | Backend PHP valida e registra a operação em MySQL, com transação | Receber 25 aparelhos deve permitir identificar os 25 e consultar o saldo correspondente |
| Saldo físico não é confiável | Calcular saldo pelas movimentações válidas | Definir estoque/local considerado e efeitos de transferência, manutenção e baixa; PENDENTE DE DECISÃO | Consultar Estoque | EQUIPAMENTO, MOVIMENTACAO_ESTOQUE | Consulta no backend com regras de movimentação e integridade | No cenário informado: entrada 25, saída 5 e devolução 1 resultam em saldo 21 |
| Risco de entrega duplicada | Validar disponibilidade antes de abrir utilização | Equipamento em uso não deve ser entregue novamente; regra proposta | Entregar Equipamento | EQUIPAMENTO, UTILIZACAO_EQUIPAMENTO, COLABORADOR | Validação no backend e controle transacional; estratégia de concorrência a definir | Uma segunda tentativa de entrega do mesmo ativo em uso deve ser recusada sem criar vínculo inconsistente |
| Termo gerado sem todos os dados | Validar os dados necessários antes de gerar PDF | Inativo não recebe nova utilização; histórico antigo deve permanecer consultável; propostas a validar | Gerar Termo | EQUIPAMENTO, UTILIZACAO_EQUIPAMENTO, COLABORADOR | Backend consulta o vínculo, valida consistência e gera o documento | Dado ausente deve gerar erro claro; inativação posterior não deve ocultar dados de utilização histórica |
| Necessidade de rastrear operações | Registrar autor, data/hora e alteração | Histórico não deve ser apagado; definir retenção e permissões; PENDENTE DE DECISÃO | Consultar Histórico | USUARIO_SISTEMA, AUDITORIA, MOVIMENTACAO_ESTOQUE | Registro de auditoria associado à operação no backend | Uma movimentação concluída deve permitir identificar autor, momento, ativo e alteração |

### Pendências centrais para a próxima revisão

- Validar o processo completo com os responsáveis da empresa antes de fechar requisitos e DER.
- Definir diferenças e transições entre ativo/inativo e status operacional.
- Confirmar se pode existir mais de uma utilização aberta por equipamento e como impedir conflitos concorrentes.
- Definir o alcance da unicidade de IMEI, serial, service tag e hostname, incluindo dados ausentes e possíveis múltiplos identificadores.
- Determinar o vínculo da utilização com empresa, filial, colaborador e linha telefônica, com suas cardinalidades e histórico.
- Definir tipos de movimentação, origem/destino e efeito de cada tipo no saldo por local e no saldo total.
- Definir campos obrigatórios do termo e tratamento de documentos históricos quando cadastros mudarem.
- Confirmar escopo de chamados: referência externa ou módulo próprio; nenhuma integração foi definida.
- Analisar e sanear as planilhas antes de planejar importação.
- Refinar requisitos, regras, casos de uso e critérios de aceite antes de criar tabelas ou implementar módulos.

### Registro desta consolidação

Esta versão reúne o contexto fornecido por Bruno, preserva as 24 áreas solicitadas e acrescenta uma matriz inicial de rastreabilidade e pendências para orientar revisões. Não confirma estrutura interna do Sankhya, não define DER físico e não declara funcionalidades implementadas. Alterações futuras devem registrar a decisão, sua origem, a data e os artefatos afetados.
