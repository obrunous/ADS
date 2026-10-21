# 03 — Análise e especificação de requisitos

## 1. Identificação e fontes

| Campo | Registro |
| --- | --- |
| Projeto | Sistema de Controle de Ativos de TI |
| Versão | 0.1 — requisitos candidatos para validação |
| Data | 20/10/2026 |
| Responsável pelo levantamento | Bruno |
| Situação | Em elaboração; sem aprovação empresarial ou acadêmica registrada |

Fontes consultadas:

- [Contexto central](../../CONTEXTO_SISTEMA_CONTROLE_ATIVOS_TI.md), especialmente identificação, processo atual, estoque, utilização, termos, módulos e regras iniciais.
- [01 — Escopo e proposta](../01-escopo-e-proposta/01-escopo-e-proposta.md), especialmente seções 7–10 e pendências P01–P12.
- [02 — Análise de viabilidade](../02-analise-de-viabilidade/02-analise-de-viabilidade.md), especialmente pontos críticos, provas PT01–PT06 e levantamentos V01–V09.

Os relatos de Bruno são a origem de domínio disponível. Não foram realizadas novas entrevistas, inspeções no ERP, análise de planilhas ou validações com o cliente nesta etapa. As formulações abaixo são **propostas de requisitos**, mesmo quando escritas como “o sistema deverá”. Não representam funcionalidades implementadas.

## 2. Objetivo e limites

Especificar capacidades e condições para controlar ativos desde o recebimento até sua destinação e histórico. O núcleo proposto é acesso → cadastros mínimos → recebimento e identificação → estoque → saída/entrega → utilização → devolução → consulta histórica.

Telefonia e termos dependem de decisão sobre sua obrigatoriedade no primeiro ciclo. Transferência, manutenção, baixa e relatórios ampliados integram a visão do produto, sem prazo ou incremento aprovado.

App nativo, IA, inventário automático por agente, integrações automáticas com ERP/GLPI/AD, gestão completa de compras e chamados e assinatura eletrônica integrada permanecem fora do recorte inicial proposto. Registrar referência de compra/chamado não implementa esses sistemas.

Este documento não define tabelas físicas, endpoints, classes finais, telas nem cronograma.

## 3. Convenções e prioridades

- **RF:** requisito funcional deste catálogo.
- **RNF:** requisito não funcional deste catálogo.
- **RN-P:** regra de negócio proposta, com referência provisória para refinamento na etapa 11.
- **Q:** questão pendente deste documento.
- **CA-RFxx-n:** critério de aceite candidato do RF correspondente.
- **Núcleo:** prioridade proposta para o primeiro ciclo operacional.
- **Condicional:** inclusão no primeiro ciclo depende de validação.
- **Evolução:** capacidade prevista para incremento posterior, a negociar.

Todos os requisitos têm situação **CANDIDATO — PENDENTE DE VALIDAÇÃO**. Prioridade não significa aprovação ou ordem de implementação. IDs deste catálogo não devem ser confundidos com RF01–RF20 do exercício FoodExpress ou exemplos didáticos das aulas. Renumerações futuras exigem mapa de correspondência; não reaproveitar IDs para outro significado.

Os critérios descrevem resultados verificáveis para testes futuros. Sua presença não significa que os testes tenham sido executados. Critérios dependentes de regra ou parâmetro ainda aberto não podem ser considerados aprovados até a decisão correspondente.

## 4. Perfis e conceitos do domínio

| Perfil candidato | Participação a validar |
| --- | --- |
| Operador de TI | Recebimentos, cadastros, saídas, utilizações e devoluções autorizadas |
| Gestor de TI | Consultas gerenciais, histórico e eventuais aprovações |
| Administrador | Usuários, permissões e configurações autorizadas |
| Colaborador/responsável | Pessoa vinculada ao ativo; acesso direto ainda não decidido |
| Responsável de filial | Participação em recebimento no destino a confirmar |

Os nomes não fixam uma matriz de permissões. No catálogo, “perfil autorizado” significa um papel com permissão explícita, cuja atribuição será validada.

| Conceito | Significado inicial |
| --- | --- |
| Equipamento | Ativo individual identificado; não é apenas a quantidade de um modelo |
| Inventário | Conjunto de ativos controlados, incluindo equipamentos em uso |
| Estoque disponível | Conjunto elegível para destinação no local e condição definidos |
| Movimentação | Evento que registra mudança no ciclo do ativo |
| Utilização | Vínculo de uso/responsabilidade com início e encerramento |
| Colaborador | Pessoa do domínio; não se confunde automaticamente com usuário de login |
| Ativo/inativo | Situação cadastral, distinta do estado operacional |
| Termo | Documento associado ao processo de utilização; gerar PDF não comprova assinatura |

## 5. Requisitos funcionais

### Condições comuns

Operações restritas pressupõem autenticação e permissão. Gravações devem validar referências e campos obrigatórios aprovados; uma operação recusada não pode produzir efeitos de negócio parciais. Autor e instante de registro são obtidos de fonte controlada pelo sistema, separados da data efetiva do evento quando houver lançamento retroativo autorizado. Repetição de envio não deve duplicar eventos já confirmados; o comportamento de repetição será definido no desenho técnico.

Atualização cadastral não autoriza sobrescrever eventos passados. Os exemplos usam dados fictícios para validação futura.

### RF01 — Autenticar e encerrar sessão

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Usuário do sistema.
- **Origem:** Contexto: Base e Segurança.
- **Especificação:** O sistema deverá autenticar credenciais de usuário habilitado e permitir encerrar sua sessão.
- **Dependências:** RNF01 e RNF03.
- **CA-RF01-1:** Com credenciais válidas de usuário habilitado, iniciar sessão e apresentar somente as capacidades autorizadas.
- **CA-RF01-2:** Com credenciais inválidas ou usuário desabilitado, negar acesso; após sair, a sessão encerrada não permite operação restrita.
- **Pendência:** Provisionamento inicial, recuperação de acesso e tempos de sessão: Q01.

### RF02 — Administrar usuários e permissões

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Administrador autorizado.
- **Origem:** Contexto: Base; escopo: Base e acesso.
- **Especificação:** O sistema deverá permitir manter usuários, sua habilitação e permissões, conforme matriz aprovada.
- **Dependências:** RF01 e RNF01.
- **CA-RF02-1:** Uma alteração autorizada de permissão modifica o acesso conforme política aprovada e deixa registro rastreável.
- **CA-RF02-2:** Uma tentativa sem permissão de administrar acesso é recusada e não modifica o usuário-alvo.
- **Pendência:** Papéis, abrangência por empresa/filial e efeito da revogação em sessão aberta: Q01.

### RF03 — Manter empresas e filiais

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Cadastros; escopo: Base.
- **Especificação:** O sistema deverá permitir cadastrar, consultar e atualizar empresas e filiais utilizadas nos vínculos dos ativos.
- **Dependências:** RF01, RF02 e RN-P07.
- **CA-RF03-1:** Uma filial é relacionada à empresa válida e pode ser consultada pelos perfis permitidos.
- **CA-RF03-2:** Referência a empresa inexistente é recusada; alteração não apaga vínculos históricos.
- **Pendência:** Campos, obrigatoriedade e possibilidade de reorganização empresarial: Q02.

### RF04 — Manter colaboradores

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Pessoas e Utilização.
- **Especificação:** O sistema deverá permitir cadastrar, consultar e atualizar colaboradores, situação e vínculo organizacional aprovado.
- **Dependências:** RF03 e RN-P07.
- **CA-RF04-1:** Um colaborador cadastrado pode ser identificado no processo de entrega com o vínculo organizacional pertinente.
- **CA-RF04-2:** Referência organizacional inválida é recusada; desligamento não apaga utilizações anteriores.
- **Pendência:** Identificador corporativo e forma de preservar mudanças de empresa/filial: Q02.

### RF05 — Manter classificações de equipamento

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Cadastros e Equipamentos.
- **Especificação:** O sistema deverá manter tipos, fabricantes e modelos necessários à identificação de equipamentos.
- **Dependências:** RF02 e RNF04.
- **CA-RF05-1:** Um equipamento pode selecionar classificação válida e consultar a descrição correspondente.
- **CA-RF05-2:** Uma combinação proibida pelas relações aprovadas é recusada sem gravar referência inconsistente.
- **Pendência:** Dependências entre tipo, modelo e fabricante e campos por categoria: Q03.

### RF06 — Identificar e manter equipamento individual

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Estoque, Cadastros e Equipamentos.
- **Especificação:** O sistema deverá identificar cada equipamento individualmente e manter suas características e identificadores aplicáveis.
- **Dependências:** RF05, RN-P01, RN-P05 e RN-P07.
- **CA-RF06-1:** No recebimento de 25 celulares, cada unidade concluída possui identificação interna distinta e pode ser consultada individualmente.
- **CA-RF06-2:** Identificador que viole a política de unicidade aprovada é recusado; não tornar obrigatório um campo inaplicável ao tipo.
- **Pendência:** Campos obrigatórios, IMEI múltiplo, serial, service tag e hostname: Q03.

### RF07 — Alterar situação cadastral do equipamento

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Caso real e Status.
- **Especificação:** O sistema deverá permitir ativar ou inativar cadastro de equipamento, distinguindo essa situação de seu estado operacional.
- **Dependências:** RF06, RN-P02 e RN-P07.
- **CA-RF07-1:** Após inativação autorizada, o cadastro é identificado como inativo e utilizações antigas continuam consultáveis.
- **CA-RF07-2:** Inativar não elimina histórico nem representa automaticamente uma baixa ou retorno ao estoque.
- **Pendência:** Inativação durante utilização aberta, reativação e justificativa obrigatória: Q04.

### RF08 — Registrar recebimento e entrada

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Problema atual e Novo conceito de estoque.
- **Especificação:** O sistema deverá registrar chegada de equipamentos, quantidade e destino de estoque, relacionando as unidades individuais à entrada.
- **Dependências:** RF03, RF06, RN-P01 e RNF04.
- **CA-RF08-1:** Uma entrada concluída de 25 unidades permite conciliar as 25 identificações com a quantidade recebida e o local definido.
- **CA-RF08-2:** Uma entrada não pode ser contabilizada duas vezes por repetição do mesmo envio confirmado; falha não deixa disponibilidade sem lastro.
- **Pendência:** Entrada parcial, unidades ainda não identificadas, documentos de origem e duplicidade de recebimento: Q05.

### RF09 — Consultar estoque e saldo por movimentações

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador ou gestor autorizado.
- **Origem:** Contexto: Novo conceito de estoque.
- **Especificação:** O sistema deverá apresentar saldo e equipamentos correspondentes ao local e condição consultados, derivados dos eventos válidos.
- **Dependências:** RF08, RF11, RF14 e RN-P01.
- **CA-RF09-1:** Em cenário aprovado de entrada 25, saída 5 e devolução 1 apta a retornar, apresentar saldo 21 e lista conciliável.
- **CA-RF09-2:** Ativo em uso não aparece como disponível; transferência entre locais não cria aumento artificial no total da empresa.
- **Pendência:** Conceito de disponível, reservas, data de corte, cancelamentos e níveis de agregação: Q05.

### RF10 — Consultar ativo e histórico de ciclo de vida

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Problema atual, Utilização e Auditoria.
- **Especificação:** O sistema deverá consultar ativo, localização, vínculos e sequência de eventos, inclusive eventos de utilizações encerradas.
- **Dependências:** RF06, RF20, RF21 e RN-P07.
- **CA-RF10-1:** A consulta permite identificar recebimento, saída, destinatário e devolução do ativo de teste com suas referências.
- **CA-RF10-2:** Inativação de cadastro não oculta utilizações antigas; perfil sem acesso não consulta dados restritos.
- **Pendência:** Busca, filtros, ordenação de eventos retroativos e visibilidade por perfil: Q06.

### RF11 — Registrar saída e envio

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Estoque e Fluxo do ativo.
- **Especificação:** O sistema deverá registrar saída de equipamento para destino identificado, com data, responsável e referência de origem quando aplicável.
- **Dependências:** RF09, RF12, RF19, RN-P03 e RN-P06.
- **CA-RF11-1:** Uma saída válida fica vinculada ao ativo e destino e afeta o saldo uma única vez, no marco operacional aprovado.
- **CA-RF11-2:** Equipamento indisponível ou destino obrigatório ausente impede confirmação; nenhum vínculo parcial permanece após falha.
- **Pendência:** Separação, reserva, expedição, trânsito e momento exato de redução do saldo: Q07.

### RF12 — Abrir utilização de equipamento

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Utilização de Equipamentos.
- **Especificação:** O sistema deverá registrar utilização vinculando equipamento, colaborador, empresa, datas e linha quando aplicável.
- **Dependências:** RF04, RF06, RF11, RN-P02 e RN-P03.
- **CA-RF12-1:** Uma entrega válida cria vínculo de utilização consultável com equipamento, destinatário e responsável pela operação.
- **CA-RF12-2:** Equipamento inativo ou já em uso não recebe vínculo incompatível segundo a regra aprovada, inclusive em tentativas concorrentes.
- **Pendência:** Momento de abertura em relação ao envio e confirmação de entrega; exceções de vínculo aberto: Q07.

### RF13 — Consultar utilizações abertas e encerradas

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador ou gestor autorizado.
- **Origem:** Contexto: Utilização de Equipamentos.
- **Especificação:** O sistema deverá consultar utilizações por equipamento e colaborador, distinguindo abertas e encerradas.
- **Dependências:** RF12, RF14 e RN-P07.
- **CA-RF13-1:** Para ativo devolvido e depois entregue novamente, apresentar os dois vínculos separadamente com seus períodos.
- **CA-RF13-2:** Alteração do responsável atual não substitui o destinatário do vínculo anterior.
- **Pendência:** Ausência de data de devolução como critério suficiente de abertura e filtros: Q06 e Q07.

### RF14 — Registrar devolução e encerrar utilização

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Regras iniciais e Fluxo completo.
- **Especificação:** O sistema deverá registrar devolução, encerrar a utilização correspondente e registrar a condição e destinação do ativo.
- **Dependências:** RF12, RN-P04 e RN-P08.
- **CA-RF14-1:** Ao devolver ativo apto, encerrar o vínculo e disponibilizar a unidade no local aprovado, com histórico preservado.
- **CA-RF14-2:** Ativo devolvido com necessidade de manutenção não fica automaticamente disponível; devolução repetida não soma outra unidade.
- **Pendência:** Devolução parcial de conjunto, datas retroativas, avaliador e destino pós-retorno: Q08.

### RF15 — Registrar transferência

- **Prioridade proposta:** Evolução.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Estoque e Fluxo completo.
- **Especificação:** O sistema deverá registrar transferência de ativo entre locais ou responsáveis conforme modalidade aprovada.
- **Dependências:** RF10, RF12, RN-P01 e RN-P08.
- **CA-RF15-1:** Uma transferência entre locais conserva a identidade do ativo e permite rastrear origem e destino sem duplicar o inventário.
- **CA-RF15-2:** Falha ou repetição não deixa duas localizações atuais incompatíveis nem duplica saldo.
- **Pendência:** Distinguir transferência física de mudança de responsável; aprovações e trânsito: Q09.

### RF16 — Registrar manutenção e retorno

- **Prioridade proposta:** Evolução.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Movimentações e Status.
- **Especificação:** O sistema deverá registrar encaminhamento à manutenção e seu retorno ou outra destinação autorizada.
- **Dependências:** RF10, RN-P08 e RN-P07.
- **CA-RF16-1:** Ativo encaminhado à manutenção sai da disponibilidade conforme regra e mantém histórico até a decisão de retorno.
- **CA-RF16-2:** Encerramento da manutenção sem condição/destino exigidos não torna o ativo automaticamente apto.
- **Pendência:** Fornecedor, custos, autorização, utilização durante manutenção e estados: Q09.

### RF17 — Registrar baixa

- **Prioridade proposta:** Evolução.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Movimentações e Fluxo completo.
- **Especificação:** O sistema deverá registrar baixa de ativo com motivo, data e responsável, preservando eventos anteriores.
- **Dependências:** RF10, RN-P07 e RN-P08.
- **CA-RF17-1:** Após baixa aprovada, o ativo deixa de integrar o conjunto disponível e seu histórico permanece consultável.
- **CA-RF17-2:** Baixa não apaga registros; ativo baixado não é entregue sem processo de reversão aprovado.
- **Pendência:** Aprovação, documentos, efeito em utilização aberta e reversibilidade: Q09.

### RF18 — Manter linhas e vínculos de telefonia

- **Prioridade proposta:** Condicional.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Telefonia e Utilização.
- **Especificação:** O sistema deverá cadastrar linhas e operadoras e manter histórico dos vínculos definidos com pessoas, empresa e equipamento.
- **Dependências:** RF03, RF04, RF06 e RN-P07.
- **CA-RF18-1:** Uma troca autorizada de vínculo permite consultar o vínculo anterior e o atual com seus períodos.
- **CA-RF18-2:** Referência inexistente é recusada; troca não sobrescreve silenciosamente o histórico anterior.
- **Pendência:** Cardinalidades, uso sem equipamento, unicidade e inclusão no primeiro ciclo: Q10.

### RF19 — Relacionar referência de solicitação ou chamado

- **Prioridade proposta:** Condicional.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Chamados e Regras iniciais.
- **Especificação:** O sistema deverá permitir registrar referência da solicitação/chamado de origem e relacioná-la à movimentação.
- **Dependências:** RF11 e RN-P06.
- **CA-RF19-1:** Uma saída com referência preenchida permite identificar essa origem ao consultar o histórico.
- **CA-RF19-2:** Não apresentar a referência manual como integração ou como chamado validado no sistema externo.
- **Pendência:** Obrigatoriedade, formato, múltiplas referências e eventual cadastro próprio: Q10.

### RF20 — Registrar e consultar auditoria

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Sistema no registro; gestor/administrador autorizado na consulta.
- **Origem:** Contexto: Auditoria e Segurança.
- **Especificação:** O sistema deverá registrar operações relevantes com autor, instante, ação, registro afetado e alterações pertinentes, permitindo consulta autorizada.
- **Dependências:** RF01, RNF02 e RN-P07.
- **CA-RF20-1:** Uma alteração rastreável permite identificar quem alterou, quando e o que mudou, sem expor segredo de autenticação.
- **CA-RF20-2:** Uma gravação crítica não é concluída sem sua evidência de auditoria exigida; perfil comum não altera registros de auditoria.
- **Pendência:** Eventos, retenção, acesso e tratamento de tentativas negadas: Q11.

### RF21 — Corrigir registros com rastreabilidade

- **Prioridade proposta:** Núcleo.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Escopo: Correção; viabilidade: riscos de conciliação.
- **Especificação:** O sistema deverá permitir correções autorizadas preservando referência ao registro original, motivo e efeitos no ciclo do ativo.
- **Dependências:** RF20, RN-P01 e RN-P07.
- **CA-RF21-1:** Uma correção de evento mostra o original e a correção, permitindo recompor o saldo pela regra vigente.
- **CA-RF21-2:** Não permitir substituição silenciosa de evento passado ou saldo manual sem evento de ajuste aprovado.
- **Pendência:** Tipos de ajuste, estorno, cancelamento e limites temporais: Q11.

### RF22 — Gerar termo em PDF

- **Prioridade proposta:** Condicional.
- **Ator/papel:** Operador de TI autorizado.
- **Origem:** Contexto: Caso real e Termos.
- **Especificação:** O sistema deverá gerar termo da utilização com dados obrigatórios validados e vínculo identificável com sua origem.
- **Dependências:** RF12, RF20 e RN-P09.
- **CA-RF22-1:** Para utilização e modelo válidos, gerar PDF com dados correspondentes de pessoa, equipamento e operação aprovados.
- **CA-RF22-2:** Campo obrigatório ausente produz mensagem clara, sem documento aparentemente válido mas incompleto.
- **Pendência:** Modelo, campos, versões, armazenamento e obrigatoriedade no primeiro ciclo: Q12.

### RF23 — Consultar termo histórico

- **Prioridade proposta:** Condicional.
- **Ator/papel:** Perfil autorizado.
- **Origem:** Contexto: Caso real e preservação de histórico.
- **Especificação:** O sistema deverá permitir consultar documento histórico autorizado com identificação da utilização e da versão documental correspondente.
- **Dependências:** RF22, RN-P07, RN-P09 e RNF01.
- **CA-RF23-1:** Após mudança cadastral, o termo emitido mantém os dados da emissão segundo a política documental aprovada.
- **CA-RF23-2:** Inativação posterior não oculta termo autorizado; acesso por identificador direto sem permissão é recusado.
- **Pendência:** Preservar PDF original, dados da emissão ou ambos; regeneração e retenção: Q12.

### RF24 — Emitir consultas e relatórios gerenciais

- **Prioridade proposta:** Evolução.
- **Ator/papel:** Gestor autorizado.
- **Origem:** Contexto: Dashboard e relatórios.
- **Especificação:** O sistema deverá apresentar totais e filtros aprovados por situação, empresa, filial, modelo e colaborador e por entradas/saídas.
- **Dependências:** RF09, RF10, RF20 e RN-P01.
- **CA-RF24-1:** Relatório filtrado apresenta os mesmos critérios de contagem da consulta operacional para o mesmo conjunto e período.
- **CA-RF24-2:** Não somar categorias sobrepostas como se fossem ativos distintos; não incluir dados fora da abrangência autorizada.
- **Pendência:** Indicadores, períodos, exportação, metas e atualização dos totais: Q13.

### RF25 — Preparar importação validada do legado

- **Prioridade proposta:** Condicional.
- **Ator/papel:** Perfil autorizado para migração.
- **Origem:** Contexto: Dados legados; viabilidade: transição.
- **Especificação:** O sistema deverá oferecer o procedimento aprovado para importar dados saneados com relatório de aceitos, rejeitados e correspondências.
- **Dependências:** RF03–RF06, RNF04 e RN-P07.
- **CA-RF25-1:** Em lote de teste aprovado, conciliar total de origem, registros aceitos e rejeitados e preservar os identificadores de correspondência necessários.
- **CA-RF25-2:** Não importar silenciosamente vínculo inválido nem duplicar registros ao repetir lote já processado conforme política.
- **Pendência:** Formato, escopo, estratégia de repetição, atomicidade do lote e corte do legado: Q14.

## 6. Requisitos não funcionais

Todos são candidatos. As metas ainda não conhecidas estão explicitadas; requisito parametrizado não será considerado pronto para aceite enquanto faltar o valor aprovado e seu cenário de medição.

| ID | Especificação proposta | Verificação/critério de aceite futuro | Pendência |
| --- | --- | --- | --- |
| RNF01 | Autorizar no backend cada operação e acesso a dados, incluindo documentos | Testar perfis permitidos e negados, acesso direto e abrangência organizacional; tentativa negada não revela dado restrito | Matriz de papéis e abrangência: Q01 |
| RNF02 | Preservar rastreabilidade das operações e proteger a auditoria contra alteração por perfis operacionais | Consultar evento com autor, instante e alvo; tentar alteração não autorizada e verificar recusa | Eventos e retenção: Q11 |
| RNF03 | Proteger credenciais e sessões; persistir somente hash de senha e manter segredos fora do frontend | Revisar armazenamento e respostas; testar encerramento de sessão e política aprovada | Política de senha, recuperação, inatividade e expiração: Q01 |
| RNF04 | Manter integridade de referências e atomicidade das operações críticas | Simular falha entre etapas e verificar confirmação integral ou reversão, sem vínculo órfão | Fronteiras transacionais e política de lotes: Q05 e Q14 |
| RNF05 | Impedir confirmações incompatíveis sob concorrência e duplicação por repetição de comando | Duas entregas do mesmo ativo e reenvio do comando produzem apenas os efeitos permitidos | Regra de utilização e resposta ao conflito: Q07 |
| RNF06 | Validar entradas no backend e parametrizar acesso ao banco; erros não expõem credenciais ou detalhes internos | Enviar dados inválidos e entradas de tentativa de injeção; verificar recusa e ausência de efeitos indevidos; revisar persistência | Domínios e mensagens por campo: Q03 |
| RNF07 | Atender metas de desempenho no volume e concorrência aprovados | Medir operações representativas no cenário definido, registrando distribuição de tempos e falhas | Volumes, percentil, tempo-alvo e ambiente: Q15 |
| RNF08 | Atender janela de operação e disponibilidade acordadas | Medir indisponibilidade com regra de cálculo e exclusões aprovadas | Janela, meta e manutenção planejada: Q15 |
| RNF09 | Permitir recuperação por cópias protegidas e restauração testada | Restaurar em ambiente isolado e conciliar dados e documentos dentro dos limites aprovados | Perda tolerável, tempo de recuperação, frequência e responsável: Q15 |
| RNF10 | Oferecer interface utilizável nos dispositivos e navegadores efetivamente adotados | Executar roteiros de recebimento, saída e devolução com operadores e matriz de ambientes aprovada | Matriz de compatibilidade, critérios de usabilidade e acessibilidade: Q16 |
| RNF11 | Separar responsabilidades e permitir manutenção com histórico de versões e testes das regras críticas | Revisar organização do código, configuração e execução dos testes previstos no incremento | Convenções, revisão e ferramentas a definir na arquitetura |
| RNF12 | Restringir coleta, acesso, armazenamento e retenção de dados e documentos ao processo e às políticas aprovadas | Conferir campos/finalidades, acessos e procedimento de retenção em cenário de teste | Políticas e responsáveis empresariais: Q11 e Q12 |

Direção tecnológica de referência: HTML/CSS/JavaScript, PHP e MySQL. Versões, framework, hospedagem, biblioteca de PDF e mecanismos técnicos específicos pertencem à arquitetura e à análise do ambiente. Não foram estabelecidos valores arbitrários de disponibilidade ou resposta, nem declarada conformidade legal.

## 7. Regras de negócio propostas e separação de responsabilidades

Estes IDs são provisórios e deverão ser reconciliados na etapa 11. Regra é uma condição do domínio; RF descreve a capacidade; RNF descreve qualidade ou restrição. Uma regra não se torna automaticamente tabela ou caso de uso.

| ID | Regra candidata | Requisitos relacionados | Decisão ainda necessária |
| --- | --- | --- | --- |
| RN-P01 | Saldo resulta dos eventos válidos e deve ser conciliável com os ativos do conjunto consultado | RF06, RF08, RF09, RF15, RF21, RF24 | Locais, disponibilidade, reservas, estornos e correções |
| RN-P02 | Equipamento inativo não recebe nova utilização, preservando consulta histórica | RF07, RF12, RF23 | Inativação durante uso e exceções |
| RN-P03 | Equipamento em uso não pode receber entrega/utilização incompatível | RF11, RF12 | Limite de utilizações abertas e transições |
| RN-P04 | Devolução encerra o vínculo correspondente, preservando seu período e dados | RF13, RF14 | Momento de encerramento e exceções |
| RN-P05 | Identificadores externos seguem política de obrigatoriedade e unicidade por tipo | RF06 | Alcance da unicidade e tratamento de nulos/múltiplos valores |
| RN-P06 | Saída registra destino, data e responsável; chamado é relacionado quando aplicável | RF11, RF19 | Obrigatoriedade do chamado e confirmação no destino |
| RN-P07 | Eventos e vínculos históricos não são sobrescritos silenciosamente; correções são rastreáveis | RF03–RF07, RF10, RF13, RF15–RF18, RF20, RF21, RF23, RF25 | Política de correção, retenção e visualização histórica |
| RN-P08 | Estado operacional e situação cadastral são distintos; retorno ao disponível depende de condição válida | RF14–RF17 | Catálogo de estados, transições e autorizações |
| RN-P09 | Termo não pode ser emitido silenciosamente incompleto; sua versão histórica precisa ser identificável | RF22, RF23 | Campos, modelo e política documental |

Estados citados no contexto — em estoque, reservado, em trânsito, em uso, em manutenção, devolvido e baixado — são candidatos. Não constituem enumeração final. “Devolvido” pode representar um evento ou estado transitório; a modelagem deverá resolver isso sem confundir evento, condição física e disponibilidade.

## 8. Cenários críticos de validação

### C01 — Recebimento antes de destinação

**Dados fictícios:** recebimento de 25 celulares destinados ao mesmo local.

1. Registrar recebimento e relacionar as unidades segundo a política aprovada.
2. Confirmar 25 identificações individuais e a entrada correspondente.
3. Consultar o saldo antes de qualquer envio.
4. Verificar conciliação entre quantidade e lista de unidades.

**Exceção:** se nem todas as unidades estiverem identificadas, aplicar a política de entrada parcial a definir em Q05, sem apresentar unidades não elegíveis como disponíveis.

### C02 — Saída, utilização e devolução

**Premissa de teste:** entrada válida de 25; saída válida de 5; retorno de 1 apto ao mesmo conjunto disponível.

O saldo esperado é 21. Os demais ativos não desaparecem do inventário: quatro continuam fora do disponível por utilização, conforme o cenário. Saída e abertura do vínculo devem respeitar o marco de entrega definido, sem contabilizar duas vezes o mesmo evento.

**Exceção:** se o retorno exigir manutenção, não aplicar automaticamente o saldo 21 ao disponível. A unidade fica na condição aprovada e continua rastreável.

### C03 — Duas tentativas de entrega do mesmo ativo

Com a regra candidata de uma utilização incompatível por ativo, dois operadores tentam confirmar a entrega da mesma unidade. Somente uma operação pode produzir vínculo válido; a outra recebe resposta de conflito sem efeito parcial. O desenho técnico da solução será definido na arquitetura.

### C04 — Inativação e documento histórico

Após uma utilização encerrada e termo emitido, inativar o equipamento. Consultar vínculo e termo com perfil autorizado: os dados históricos permanecem acessíveis. Tentar nova utilização: recusar conforme RN-P02. O relato do ERP inspira o cenário, mas não determina sua causa técnica.

### C05 — Dados insuficientes para PDF

Remover de um cenário fictício um dado obrigatório do modelo aprovado e solicitar o termo. Informar precisamente a pendência, sem produzir documento aparentemente completo. Após corrigir o dado de forma autorizada, repetir a emissão com versão e origem rastreáveis.

### C06 — Falha e repetição

Simular falha entre o registro da movimentação e seu efeito sobre vínculo/estado. Verificar reversão ou confirmação integral. Repetir o comando após perda da resposta: não duplicar evento já confirmado. Definir como identificar a operação repetida sem impedir recebimentos distintos legítimos.

## 9. Dados de interesse para análise posterior

Este é um vocabulário conceitual, não um esquema físico. Campos e obrigatoriedade precisam ser validados antes do DER.

| Conceito | Informações a investigar | Cuidados |
| --- | --- | --- |
| Empresa/filial/local | Identificação, vínculo organizacional, situação | Filial e local físico podem não ser equivalentes |
| Colaborador | Identificação corporativa, nome, vínculo, situação | Coletar somente dados necessários |
| Usuário do sistema | Identidade de acesso, habilitação, permissões | Não confundir com colaborador nem persistir senha em texto puro |
| Equipamento | ID interno, tipo, fabricante/modelo, identificadores, situação | IDs não devem ser alterados para representar movimentação |
| Recebimento | Origem, quantidade, data, local, unidades, autor | Quantidade não substitui identificação individual |
| Movimentação | Ativo, tipo, origem/destino, data do evento, instante do registro, autor e motivo | Datas distintas e correções precisam de política |
| Utilização | Equipamento, colaborador, empresa, período, linha opcional e observação | Cardinalidades e encerramento precisam de decisão |
| Linha telefônica | Número, operadora, situação e vínculos históricos | Não impor um para um sem análise |
| Termo | Utilização, emissão, modelo/versão e documento/dados históricos | Documento atual e documento emitido não se confundem |
| Auditoria | Autor, instante, ação, alvo e valores pertinentes | Não copiar segredos para logs |

## 10. Rastreabilidade inicial

A matriz completa pertence à etapa 06. Esta síntese liga necessidades do contexto ao catálogo e aos riscos já levantados.

| Necessidade | RFs | RNFs | Referência de viabilidade |
| --- | --- | --- | --- |
| Representar ativos antes do envio | RF05, RF06, RF08, RF09 | RNF04, RNF05 | PT01; V-R02, V-R09 |
| Evitar entrega duplicada | RF11, RF12 | RNF04, RNF05 | PT02, PT03; V-R05 |
| Manter histórico e corrigir com rastreabilidade | RF07, RF10, RF13, RF20, RF21 | RNF02, RNF04 | PT04; V-R02, V-R06 |
| Controlar retorno e destinação | RF14–RF17 | RNF04, RNF05 | PT03; V-R02 |
| Produzir termos consistentes | RF22, RF23 | RNF01, RNF12 | PT05; V-R06, V-R07 |
| Controlar acesso e proteger informações | RF01, RF02, RF20 | RNF01, RNF03, RNF06, RNF12 | V-R07 |
| Preparar legado e recuperação | RF25 | RNF04, RNF09 | PT06; V-R03, V-R08 |
| Consultar operação e gestão | RF09, RF10, RF13, RF24 | RNF01, RNF07, RNF10 | V03; V-R02 |

As siglas PT, V e V-R remetem à análise de viabilidade. Os IDs não representam testes executados ou decisões aprovadas.

## 11. Questões pendentes e impacto

| ID | Pergunta a decidir/levantar | Impacto principal | Relação com documentos anteriores |
| --- | --- | --- | --- |
| Q01 | Quais perfis, permissões, recuperação de acesso e regras de sessão? | RF01, RF02; RNF01, RNF03 | P02–P03; V01, V08 |
| Q02 | Quais campos e relações organizacionais são obrigatórios e históricos? | RF03, RF04 | P01, P03; V01, V04 |
| Q03 | Quais campos por equipamento e quais identificadores únicos, opcionais ou múltiplos? | RF05, RF06; RN-P05 | P09; V04 |
| Q04 | Quando inativar/reativar equipamento e como tratar uso aberto? | RF07; RN-P02 | P07, P11; V01 |
| Q05 | Como concluir entrada, tratar identificação parcial, reserva, saldo e duplicidade? | RF08, RF09; RN-P01 | P04–P05; V01, V03 |
| Q06 | Quais filtros e qual representação de vínculos/eventos históricos? | RF10, RF13 | P11; V01, V04 |
| Q07 | Em que marco saída, envio, entrega e utilização mudam estado/saldo? | RF11, RF12; RN-P03 | P04, P07; V01, V09 |
| Q08 | Quem avalia devolução e qual destino para cada condição? | RF14; RN-P04, RN-P08 | P07; V01 |
| Q09 | Como transferir, manter e baixar, com quais autorizações e reversões? | RF15–RF17 | P07, P11; V01 |
| Q10 | Telefonia entra no núcleo? Como relacionar chamados e linhas? | RF18, RF19 | P06, P08; V02 |
| Q11 | Como corrigir eventos e quais regras de auditoria, retenção e acesso? | RF20, RF21; RN-P07 | P11; V08 |
| Q12 | Quais termos, campos e política de emissão, preservação e retenção? | RF22, RF23 | P06, P11; V02, V08 |
| Q13 | Quais indicadores, filtros, exportações e regras de contagem? | RF24 | P05; V01, V03 |
| Q14 | Qual legado, formato, qualidade e estratégia de transição/importação? | RF25 | P12; V04 |
| Q15 | Quais volumes, carga, metas de resposta, disponibilidade e recuperação? | RNF07–RNF09 | P10; V03, V06 |
| Q16 | Quais dispositivos, navegadores e critérios de usabilidade/acessibilidade? | RNF10 | P03, P10; V01, V06 |

Todas estão **PENDENTE DE DECISÃO/LEVANTAMENTO** conforme sua natureza. Bruno pode coletar evidências; o responsável empresarial que confirma regras e prioridades ainda precisa ser identificado. Nenhum prazo ou responsável adicional foi atribuído sem confirmação.

## 12. Método de validação e controle de mudanças

1. Revisar o catálogo com o responsável pelo processo, distinguindo rotina real e melhoria proposta.
2. Usar exemplos reais autorizados e dados fictícios de teste para esclarecer exceções.
3. Resolver as questões que bloqueiam cada incremento e registrar decisão, fonte, data e aprovador.
4. Completar parâmetros dos RNFs e a matriz de permissões antes de aceitar seus testes.
5. Aprovar prioridades e fronteira do MVP, incluindo decisão explícita sobre telefonia e termos.
6. Relacionar requisitos a casos de uso, regras, entidades e critérios de teste.
7. Somente então planejar tarefas pequenas de implementação e validação.

Para cada requisito, manter futuramente situação, prioridade aprovada, fonte, aprovador, data, versão e impacto de mudança. Situações sugeridas: candidato, em revisão, aprovado, adiado, rejeitado e substituído. Ao rejeitar ou adiar, registrar motivo; preservar o ID para manter a rastreabilidade.

Não declarar este documento especificação fechada enquanto restarem decisões bloqueantes do recorte escolhido. A conclusão de requisitos não aprova automaticamente DER, código ou implantação.

## 13. Resumo do catálogo e histórico

Esta versão contém **25 requisitos funcionais candidatos**, **12 requisitos não funcionais candidatos**, **9 regras propostas** e **16 questões pendentes**, com dois critérios de aceite por RF. Os critérios são planejamento de verificação, não resultados de testes.

| Versão | Data | Registro |
| --- | --- | --- |
| 0.1 | 20/10/2026 | Catálogo inicial extraído do contexto, escopo e viabilidade; prioridades propostas, critérios de aceite, cenários e pendências; sem implementação |

A próxima etapa de modelagem deverá usar esses IDs e explicitar hipóteses. O detalhamento de casos de uso e a matriz de rastreabilidade serão desenvolvidos em suas pastas quando solicitados.
