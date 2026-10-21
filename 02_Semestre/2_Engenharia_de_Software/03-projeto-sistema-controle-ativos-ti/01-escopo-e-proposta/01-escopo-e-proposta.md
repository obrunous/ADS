# 01 — Escopo e proposta do projeto

## 1. Identificação

| Campo | Informação |
| --- | --- |
| Nome do projeto | Sistema de Controle de Ativos de TI |
| Tipo de solução | Sistema web de gestão e controle de ativos |
| Contexto acadêmico | Tecnologia em Análise e Desenvolvimento de Sistemas — Engenharia de Software |
| Responsável pela elaboração | Bruno |
| Versão | 0.3 — proposta geral com os controles principais |
| Data | 20/10/2026 |
| Situação | Proposta inicial para análise e validação |

## 2. Apresentação da proposta

O projeto propõe o desenvolvimento de um sistema web para uma empresa que atualmente utiliza planilhas para controlar seus ativos de TI. A solução deverá centralizar os cadastros e os registros de entradas, saídas e demais movimentações, permitindo acompanhar os equipamentos disponíveis, sua localização e seus responsáveis.

A solução será organizada a partir de três controles principais: Cadastro de Equipamentos, Cadastro de Linhas Telefônicas e Utilização de Equipamentos. Esses controles serão relacionados aos cadastros de colaboradores, empresas, locais e usuários autorizados.

A proposta é reunir essas informações em um ambiente organizado, no qual os usuários autorizados possam registrar operações, consultar dados e acompanhar o histórico dos ativos. O sistema deverá apoiar a rotina da empresa e facilitar o acesso a informações para controle e tomada de decisão.

## 3. Contexto da empresa

A empresa utiliza equipamentos de tecnologia em suas atividades, como computadores, notebooks, monitores, celulares e outros dispositivos. Esses ativos podem permanecer em estoque ou ser destinados a setores, unidades e colaboradores.

O controle é realizado por meio de planilhas, nas quais são registrados dados dos equipamentos, das linhas telefônicas e de sua utilização por colaboradores ou unidades da empresa. Conforme a quantidade de ativos e operações aumenta, manter os registros atualizados e consultar as informações se torna mais trabalhoso.

Esse cenário representa a empresa considerada nesta proposta. Os detalhes de sua estrutura e de seus procedimentos serão levantados nas etapas seguintes.

## 4. Problema identificado

O uso de planilhas separadas dificulta a centralização e a atualização das informações sobre os ativos. Para saber quais equipamentos estão disponíveis, onde se encontram e quem está responsável por eles, pode ser necessário consultar e comparar diferentes registros.

Entre as dificuldades que o projeto pretende tratar estão:

- informações distribuídas em arquivos diferentes;
- cadastros incompletos, duplicados ou desatualizados;
- dificuldade para acompanhar entradas e saídas;
- dificuldade para identificar a localização e o responsável por um equipamento;
- falta de uma consulta organizada ao histórico de movimentações;
- trabalho manual para elaborar controles e relatórios;
- maior possibilidade de inconsistências durante a atualização dos dados.

A proposta busca melhorar esse processo por meio de uma solução centralizada. A frequência e o impacto dessas dificuldades deverão ser confirmados no levantamento com a empresa.

## 5. Objetivo geral

Desenvolver um sistema web para centralizar o cadastro e o controle dos ativos de TI de uma empresa, permitindo registrar entradas, saídas e movimentações, acompanhar a disponibilidade dos equipamentos e consultar seu histórico.

## 6. Objetivos específicos

1. Organizar os cadastros de equipamentos e as informações necessárias ao seu controle.
2. Organizar as linhas telefônicas e acompanhar sua associação a responsáveis e equipamentos, quando aplicável.
3. Registrar a entrada de novos ativos e sua disponibilidade em estoque.
4. Registrar saídas, entregas, devoluções e transferências.
5. Relacionar os equipamentos aos seus locais e responsáveis.
6. Consultar a situação e a localização dos ativos.
7. Preservar o histórico das movimentações realizadas.
8. Disponibilizar consultas e relatórios que auxiliem a gestão.
9. Controlar o acesso dos usuários às funcionalidades do sistema.
10. Reduzir a dependência de planilhas dispersas e facilitar a atualização das informações.

## 7. Público-alvo e usuários

O sistema será destinado aos profissionais responsáveis pelo cadastro, movimentação e gestão dos ativos da empresa. A divisão abaixo apresenta perfis propostos; as permissões definitivas serão validadas no levantamento.

| Perfil proposto | Participação prevista |
| --- | --- |
| Operador de TI ou responsável pelos ativos | Manter cadastros autorizados, registrar entradas e saídas, vincular equipamentos e linhas, registrar devoluções e consultar o histórico |
| Gestor | Acompanhar estoque, utilização e distribuição dos ativos; consultar relatórios e informações gerenciais |
| Administrador do sistema | Administrar contas de acesso e permissões conforme as responsabilidades definidas pela empresa |
| Colaborador responsável pelo ativo | Ter a utilização do equipamento e da linha registrada em seu nome, quando aplicável; acesso direto ao sistema ainda será avaliado |

### Usuário do sistema e responsável pelo equipamento

O **usuário do sistema** é a pessoa que possui uma conta de acesso e realiza operações permitidas. O **colaborador responsável pelo equipamento** é a pessoa à qual o ativo está vinculado para utilização. Uma mesma pessoa pode exercer os dois papéis, mas receber um equipamento não exige, por si só, uma conta no sistema.

Por exemplo, um operador de TI pode registrar a entrega de um notebook a outro colaborador. O registro deverá permitir identificar tanto quem recebeu o notebook quanto quem realizou o lançamento. Essa distinção facilita o acompanhamento da responsabilidade pelo ativo e do histórico das operações.

As permissões deverão considerar as ações que cada perfil pode realizar, como consultar, cadastrar, atualizar, registrar movimentações e administrar acessos. O papel de administrador de contas não concede automaticamente autorização para todas as operações de negócio.

## 8. Escopo do sistema

### 8.1. Três controles principais e cadastros de apoio

A proposta usa como referência os três controles citados no contexto do projeto. Eles orientam a organização funcional da solução, mas ainda não definem o desenho final das telas, os campos obrigatórios ou as regras específicas de cada operação.

#### Cadastro de Equipamentos

Reunir a identificação e as características dos equipamentos da empresa, permitindo cadastrar, consultar e atualizar suas informações. O controle deverá ajudar a reconhecer cada ativo e acompanhar sua situação e localização.

Entre as informações a considerar estão identificação interna, tipo, fabricante, modelo e identificadores aplicáveis ao equipamento. A definição dos campos será ajustada à necessidade de cada categoria, sem exigir os mesmos dados para todos os ativos.

O cadastro identifica o equipamento; as entradas, saídas e demais movimentações registram o que acontece com ele ao longo do tempo.

#### Cadastro de Linhas Telefônicas

Organizar as linhas utilizadas pela empresa, incluindo número, operadora e situação, além das referências organizacionais necessárias. Permitir consultar a linha e acompanhar seus vínculos com responsáveis e equipamentos, quando aplicável.

Uma linha e um aparelho são elementos distintos: a linha pode mudar de aparelho ou de responsável. O sistema deverá apoiar o acompanhamento dessas alterações sem perder a informação dos vínculos anteriores. As possibilidades e os limites de associação serão definidos na análise de requisitos.

#### Utilização de Equipamentos

Registrar o vínculo entre o equipamento e o colaborador ou destino responsável por sua utilização, com referência à empresa ou unidade e à linha telefônica quando pertinente.

Esse controle deverá permitir acompanhar entregas, períodos de utilização e devoluções. Deverá também identificar o usuário que registrou a operação e manter o histórico das utilizações anteriores. Dados como datas, observações e responsáveis serão detalhados conforme o processo da empresa.

Documentos de entrega ou responsabilidade poderão apoiar esse controle, conforme necessidade e modelo a definir no levantamento.

#### Cadastros de apoio

Os três controles deverão utilizar informações organizadas de empresas, unidades, locais, colaboradores, tipos de equipamentos, fabricantes, modelos, operadoras e usuários do sistema, conforme necessário.

Esses cadastros apoiam a padronização dos registros e evitam a repetição desnecessária de informações. Sua existência como telas independentes e sua organização final serão definidas na modelagem da solução.

#### Relação entre os controles

| Controle | Pergunta principal que ajuda a responder |
| --- | --- |
| Cadastro de Equipamentos | Qual é o equipamento e quais são suas características? |
| Cadastro de Linhas Telefônicas | Qual é a linha e quais informações permitem acompanhá-la? |
| Utilização de Equipamentos | Quem está utilizando o equipamento, desde quando e com qual linha, se aplicável? |
| Entradas, saídas e histórico | Como o ativo chegou à situação atual e quais operações foram realizadas? |
| Usuários e permissões | Quem pode realizar cada ação e quem registrou a operação? |

Os três controles se complementam com o estoque e as movimentações. A solução deverá permitir conhecer os ativos disponíveis mesmo antes de uma vinculação de utilização.

### 8.2. Entradas e estoque

Registrar o recebimento de equipamentos, sua identificação e o local em que ficarão disponíveis. Permitir consultar os ativos em estoque e acompanhar as alterações decorrentes das movimentações registradas.

### 8.3. Saídas e utilização

Registrar a saída ou entrega de equipamentos, identificando o destino, o responsável e a data da operação. Permitir acompanhar quais ativos estão em utilização e a quem estão vinculados.

### 8.4. Demais movimentações

Contemplar o registro de devoluções e transferências, além do acompanhamento de manutenção e baixa de equipamentos conforme as necessidades levantadas. As prioridades de entrega dessas capacidades serão definidas no planejamento do projeto.

### 8.5. Consultas e histórico

Permitir consultar equipamentos, situação, localização, responsáveis e movimentações anteriores. O histórico deverá ajudar a compreender a trajetória de cada ativo e a identificar as operações realizadas.

### 8.6. Relatórios

Disponibilizar informações para acompanhamento da quantidade de ativos, disponibilidade, utilização, entradas, saídas e distribuição por local ou responsável. Os relatórios prioritários serão definidos com os usuários.

### 8.7. Acesso e registro das operações

Permitir o acesso por usuários autorizados e registrar quem realizou as operações relevantes. As permissões serão organizadas conforme as responsabilidades de cada perfil.

## 9. Limites do escopo inicial

O foco inicial será organizar o Cadastro de Equipamentos, o Cadastro de Linhas Telefônicas e a Utilização de Equipamentos, articulados ao controle de entradas e saídas, aos responsáveis e locais e à consulta ao histórico. A implantação poderá ocorrer por etapas, conforme as prioridades definidas com a empresa.

O detalhamento da telefonia e sua ordem de implementação serão definidos com os usuários. Funcionalidades complementares, como documentos de entrega, importação de dados e referências a solicitações internas, serão avaliadas para definir sua necessidade e prioridade.

A primeira versão não prevê gestão completa de compras, controle financeiro ou contábil, aplicação móvel nativa ou integração automática com outros sistemas. Essas possibilidades poderão ser analisadas futuramente mediante revisão do escopo.

## 10. Visão geral do funcionamento

O processo esperado é registrar os equipamentos quando entram na empresa, acompanhar sua disponibilidade e registrar as movimentações realizadas durante sua utilização.

```text
Recebimento e cadastro do ativo
  → Disponibilidade em estoque
  → Saída ou entrega
  → Utilização por um responsável ou local
  → Devolução, transferência, manutenção ou baixa, conforme a necessidade
```

O histórico acompanhará as operações. Essas possibilidades não representam uma sequência obrigatória: o caminho de cada ativo dependerá do que ocorrer durante sua utilização.

Por exemplo, um notebook recebido poderá ser cadastrado e permanecer disponível em estoque. Ao ser entregue a um colaborador, a saída e o vínculo de utilização serão registrados. Para um celular acompanhado de linha, o cadastro do aparelho e o cadastro da linha poderão ser relacionados à utilização correspondente. O usuário que realizou a operação será identificado. Se houver devolução, troca ou transferência, a alteração deverá manter a referência ao histórico anterior.

## 11. Justificativa e benefícios esperados

A centralização das informações poderá tornar o controle dos ativos mais organizado e facilitar o trabalho dos profissionais responsáveis. Em vez de depender da comparação de diferentes planilhas, a empresa poderá consultar os registros em um único sistema.

Os benefícios esperados incluem:

- maior organização dos cadastros;
- atualização mais simples das informações;
- melhor acompanhamento do estoque e da utilização;
- facilidade para localizar equipamentos e responsáveis;
- rastreabilidade das entradas, saídas e demais movimentações;
- redução de retrabalho e inconsistências nos registros;
- apoio à elaboração de relatórios e à tomada de decisão.

Esses benefícios deverão ser avaliados ao longo do desenvolvimento e da validação com os usuários. Ainda não há resultados medidos de economia ou melhoria de produtividade.

## 12. Tecnologias inicialmente consideradas

| Finalidade | Tecnologia ou ferramenta |
| --- | --- |
| Interface web | HTML, CSS e JavaScript |
| Desenvolvimento do backend | PHP |
| Banco de dados | MySQL |
| Ambiente de desenvolvimento | VS Code |
| Modelagem e administração do banco | MySQL Workbench |
| Controle de versão | Git |

As tecnologias são uma referência inicial. A arquitetura e as configurações serão detalhadas nas etapas apropriadas, considerando a viabilidade e as necessidades da solução.

## 13. Desenvolvimento e entregas previstas

O projeto será desenvolvido de forma incremental, começando pelas funcionalidades essenciais e evoluindo conforme a validação das necessidades da empresa.

As etapas previstas incluem levantamento do processo atual, análise de viabilidade, especificação de requisitos, modelagem, planejamento, implementação, testes e validação.

As entregas deverão incluir a documentação do projeto e uma aplicação web com os módulos definidos para cada etapa. A abrangência da primeira versão, os recursos disponíveis e o cronograma serão estabelecidos no planejamento.

## 14. Pontos a definir no levantamento

Os identificadores P01–P12 foram mantidos para permitir a consulta por documentos anteriores. Aqui, as questões são apresentadas no nível geral da proposta; sua resolução pertence às etapas de análise.

| Referência | Definição necessária |
| --- | --- |
| P01 | Unidades da empresa e tipos de ativos que serão atendidos |
| P02 | Responsável pela validação das necessidades e das entregas |
| P03 | Usuários do sistema e permissões de cada perfil |
| P04 | Forma de registrar recebimentos e entradas |
| P05 | Organização do estoque e dos locais de armazenamento |
| P06 | Necessidade e prioridade de documentos de entrega e controle de telefonia |
| P07 | Situações dos equipamentos e procedimentos de movimentação |
| P08 | Necessidade de relacionar movimentações a solicitações internas |
| P09 | Informações necessárias para identificar cada tipo de ativo |
| P10 | Prazo, recursos, infraestrutura e volume de utilização |
| P11 | Procedimentos de correção e preservação do histórico |
| P12 | Aproveitamento e preparação dos dados existentes nas planilhas |

Esses pontos permanecem pendentes de levantamento ou decisão. O detalhamento de regras, campos e exceções será feito nos documentos correspondentes.

## 15. Referência e histórico de revisão

**Referência de domínio:** [Contexto central do Sistema de Controle de Ativos de TI](../../CONTEXTO_SISTEMA_CONTROLE_ATIVOS_TI.md).

A proposta apresenta o cenário geral de uma empresa que utiliza planilhas e pretende adotar um sistema para controlar seus ativos. O contexto central permanece como material de apoio para aprofundamento nas etapas seguintes.

| Versão | Data | Alteração |
| --- | --- | --- |
| 0.1 | 20/10/2026 | Elaboração inicial do documento |
| 0.2 | 20/10/2026 | Revisão para uma proposta geral, centrada em planilhas, cadastros, entradas, saídas e movimentações; retirada de incidentes particulares e detalhes técnicos do escopo |

| 0.3 | 20/10/2026 | Ampliação da proposta com Cadastro de Equipamentos, Cadastro de Linhas Telefônicas, Utilização de Equipamentos e distinção entre usuário operador e colaborador responsável; mantida a abordagem geral |
