# 06 — Matriz de rastreabilidade

## 1. Identificação e objetivo

| Campo | Registro |
| --- | --- |
| Projeto | Sistema de Controle de Ativos de TI |
| Versão | 0.1 — matriz documental inicial |
| Data | 20/10/2026 |
| Situação | Relações propostas; requisitos e aceites ainda não aprovados |

Relacionar as necessidades de uma empresa que controla ativos em planilhas às partes do projeto: escopo, requisitos, regras propostas, casos de uso, conceitos e critérios de verificação. A matriz permite localizar cobertura, lacunas e impactos quando uma definição muda.

O foco é preservar a ligação entre Cadastro de Equipamentos, Cadastro de Linhas Telefônicas, Utilização de Equipamentos, movimentações e usuários. As referências não confirmam implementação, aprovação empresarial ou resultado de teste.

## 2. Fontes e versões consideradas

| Documento | Versão consultada | Uso |
| --- | --- | --- |
| [Contexto central](../../CONTEXTO_SISTEMA_CONTROLE_ATIVOS_TI.md) | Consolidação de 20/10/2026 | Domínio de origem |
| [01 — Escopo e proposta](../01-escopo-e-proposta/01-escopo-e-proposta.md) | 0.3 | Proposta geral e três controles principais |
| [02 — Viabilidade](../02-analise-de-viabilidade/02-analise-de-viabilidade.md) | 0.1 | Riscos, provas propostas e evidências faltantes |
| [03 — Requisitos](../03-analise-e-especificacao-de-requisitos/03-analise-e-especificacao-de-requisitos.md) | 0.1 | IDs RF, RNF, RN-P, Q e critérios CA |
| [04 — Modelagem UML](../04-modelagem-uml/04-modelagem-uml.md) | 0.1 | Atores, conceitos e hipóteses H01–H04 |
| [05 — Casos de uso](../05-diagrama-e-especificacao-de-casos-de-uso/05-diagrama-e-especificacao-de-casos-de-uso.md) | 0.1 | UC01–UC25 e garantias G01–G05 |

Os documentos 02–05 foram produzidos antes da última revisão do escopo. Seus identificadores são preservados aqui; divergências de prioridade ou descrição são registradas na seção 10, sem alterar silenciosamente as fontes.

## 3. Convenções e situação da cobertura

- **RF / RNF:** requisitos funcionais / não funcionais do catálogo.
- **RN-P:** regra de negócio proposta, ainda a detalhar na etapa 11.
- **UC:** caso de uso da etapa 05.
- **CA-RFxx-1/2:** critérios de aceite candidatos do catálogo, reproduzidos nos casos.
- **VT:** cenário de verificação planejado nesta matriz, sem execução.
- **Q:** questão pendente do catálogo; **P:** questão do escopo.
- **C:** cenário crítico da etapa 03; **PT:** prova proposta da viabilidade.

“Cobertura documental” significa que há referências relacionadas, não que o requisito esteja satisfeito. Todos os RFs, RNFs, UCs, regras e critérios continuam candidatos. Não existem tarefas de implementação, commits ou resultados de testes vinculados nesta versão.

As relações com conceitos e RNFs são propostas de análise. Conceito não equivale a tabela, classe implementada ou tela. Relação de dependência não fixa ordem de implementação e não gera automaticamente include/extend.

## 4. Necessidades e visão dos três controles

Os códigos N01–N08 são rótulos locais de necessidades, não novos requisitos.

| Necessidade | Origem na proposta | RFs relacionados | Resultado esperado a validar |
| --- | --- | --- | --- |
| N01 — Identificar equipamentos | Cadastro de Equipamentos | RF05–RF07 | Cada ativo pode ser reconhecido e consultado |
| N02 — Organizar telefonia | Cadastro de Linhas Telefônicas | RF18 | Linhas, operadoras e vínculos acompanháveis |
| N03 — Acompanhar utilização | Utilização de Equipamentos | RF04, RF12–RF14, RF18 | Identificar destinatário, período e vínculos pertinentes |
| N04 — Controlar entradas e saídas | Estoque e movimentações | RF08–RF09, RF11, RF14–RF17 | Disponibilidade e trajetória conciliáveis |
| N05 — Organizar apoio e acesso | Cadastros de apoio e usuários | RF01–RF05 | Dados padronizados e operações autorizadas |
| N06 — Preservar história e autoria | Histórico e registro de operações | RF10, RF13, RF20–RF21, RF23 | Distinguir responsável pelo ativo e usuário que lançou a operação |
| N07 — Apoiar consulta gerencial | Consultas e relatórios | RF09–RF10, RF13, RF24 | Consultar disponibilidade, localização e distribuição |
| N08 — Avaliar complementos | Documentos, solicitações e legado | RF19, RF22–RF23, RF25 | Capacidades complementares delimitadas e priorizadas |

N02 faz parte da organização funcional indicada na proposta 0.3. Isso não elimina a necessidade de definir o incremento e o detalhamento de telefonia, nem aprova suas cardinalidades.

## 5. Matriz principal: escopo → RF → UC → conceitos → aceite

A coluna de prioridade reproduz o catálogo 0.1, não uma prioridade nova. Toda linha possui situação “candidato; sem implementação/teste”. Os conceitos são candidatos para a etapa 07. As duas referências CA de cada linha são detalhadas na seção 8.

| RF e capacidade | Escopo 0.3: seção | Prioridade no catálogo | UC | Conceitos candidatos | Critérios | Questões |
| --- | --- | --- | --- | --- | --- | --- |
| RF01 — Autenticar e encerrar sessão | 7; 8.7 | Núcleo | UC01 | UsuarioSistema, sessão | CA-RF01-1; CA-RF01-2 | Q01 |
| RF02 — Administrar usuários e permissões | 7; 8.7 | Núcleo | UC02 | UsuarioSistema, Permissao | CA-RF02-1; CA-RF02-2 | Q01 |
| RF03 — Manter empresas e filiais | 8.1 — cadastros de apoio | Núcleo | UC03 | Empresa, Filial, Local a validar | CA-RF03-1; CA-RF03-2 | Q02 |
| RF04 — Manter colaboradores | 7; 8.1 — cadastros de apoio | Núcleo | UC04 | Colaborador, vínculo organizacional | CA-RF04-1; CA-RF04-2 | Q02 |
| RF05 — Manter classificações de equipamento | 8.1 — equipamentos e apoio | Núcleo | UC05 | TipoEquipamento, Fabricante, Modelo | CA-RF05-1; CA-RF05-2 | Q03 |
| RF06 — Identificar e manter equipamento individual | 8.1 — Cadastro de Equipamentos | Núcleo | UC06 | Equipamento, identificação | CA-RF06-1; CA-RF06-2 | Q03 |
| RF07 — Alterar situação cadastral do equipamento | 8.1 — Cadastro de Equipamentos; 8.5 | Núcleo | UC07 | Equipamento, situação cadastral | CA-RF07-1; CA-RF07-2 | Q04 |
| RF08 — Registrar recebimento e entrada | 8.2 | Núcleo | UC08 | Recebimento, Equipamento, Movimentacao | CA-RF08-1; CA-RF08-2 | Q05 |
| RF09 — Consultar estoque e saldo por movimentações | 8.2; 8.5 | Núcleo | UC09 | Estoque consultado, Equipamento, Movimentacao | CA-RF09-1; CA-RF09-2 | Q05 |
| RF10 — Consultar ativo e histórico de ciclo de vida | 8.5 | Núcleo | UC10 | Equipamento, Movimentacao, Utilizacao | CA-RF10-1; CA-RF10-2 | Q06 |
| RF11 — Registrar saída e envio | 8.3 | Núcleo | UC11 | Movimentacao, Equipamento, destino | CA-RF11-1; CA-RF11-2 | Q07 |
| RF12 — Abrir utilização de equipamento | 8.1 — Utilização de Equipamentos; 8.3 | Núcleo | UC12 | Utilizacao, Equipamento, Colaborador | CA-RF12-1; CA-RF12-2 | Q07 |
| RF13 — Consultar utilizações abertas e encerradas | 8.1 — Utilização de Equipamentos; 8.5 | Núcleo | UC13 | Utilizacao, Colaborador, Equipamento | CA-RF13-1; CA-RF13-2 | Q06, Q07 |
| RF14 — Registrar devolução e encerrar utilização | 8.3; 8.4 | Núcleo | UC14 | Utilizacao, Movimentacao, condição/destino | CA-RF14-1; CA-RF14-2 | Q08 |
| RF15 — Registrar transferência | 8.4 | Evolução | UC15 | Movimentacao, Local, Utilizacao se aplicável | CA-RF15-1; CA-RF15-2 | Q09 |
| RF16 — Registrar manutenção e retorno | 8.4 | Evolução | UC16 | Equipamento, Movimentacao, condição | CA-RF16-1; CA-RF16-2 | Q09 |
| RF17 — Registrar baixa | 8.4 | Evolução | UC17 | Equipamento, Movimentacao de baixa | CA-RF17-1; CA-RF17-2 | Q09 |
| RF18 — Manter linhas e vínculos de telefonia | 8.1 — Cadastro de Linhas Telefônicas; 9 | Condicional | UC18 | LinhaTelefonica, Operadora, vínculo | CA-RF18-1; CA-RF18-2 | Q10 |
| RF19 — Relacionar referência de solicitação ou chamado | 9 — referências a solicitações | Condicional | UC19 | Referência de solicitação, Movimentacao | CA-RF19-1; CA-RF19-2 | Q10 |
| RF20 — Registrar e consultar auditoria | 8.7 | Núcleo | UC20 | RegistroAuditoria, UsuarioSistema | CA-RF20-1; CA-RF20-2 | Q11 |
| RF21 — Corrigir registros com rastreabilidade | 8.5; 8.7; P11 | Núcleo | UC21 | Correção, evento original, RegistroAuditoria | CA-RF21-1; CA-RF21-2 | Q11 |
| RF22 — Gerar termo em PDF | 8.1 — utilização; 9 — documentos | Condicional | UC22 | Termo, Utilizacao, dados da emissão | CA-RF22-1; CA-RF22-2 | Q12 |
| RF23 — Consultar termo histórico | 8.5; 9 — documentos | Condicional | UC23 | Termo, versão documental | CA-RF23-1; CA-RF23-2 | Q12 |
| RF24 — Emitir consultas e relatórios gerenciais | 8.6 | Evolução | UC24 | Consulta gerencial, ativos e eventos | CA-RF24-1; CA-RF24-2 | Q13 |
| RF25 — Preparar importação validada do legado | 9 — importação; P12 | Condicional | UC25 | Lote, correspondências, cadastros de destino | CA-RF25-1; CA-RF25-2 | Q14 |

### Particularidade de RF20

RF20 reúne captura automática e consulta de auditoria. UC20 corresponde ao objetivo externo de consultar auditoria. A captura é transversal aos fluxos de gravação por G02, RF20 e RNF02. Não se declara que UC20, isoladamente, cobre o registro automático de todas as operações.

## 6. Matriz de requisitos não funcionais

Escopo de aplicação e verificações abaixo são propostas. Metas ausentes permanecem pendentes; referência a teste futuro não atesta atendimento.

| RNF | Aplicação principal | Ligação com UC/garantias | Verificação planejada | Pendência |
| --- | --- | --- | --- | --- |
| RNF01 — Autorização | Todas as operações restritas e documentos | UC01–UC25 conforme ação; G01 | VT-N01: testar permissão, abrangência e acesso direto com perfis permitidos/negados | Q01 |
| RNF02 — Auditoria | Gravações relevantes e consulta de autoria | G02/G04; UC20–UC21 | VT-N02: verificar autor, instante, alvo e proteção do registro; segredos ausentes | Q11 |
| RNF03 — Credenciais e sessão | Acesso e gestão de usuários | UC01–UC02; G01 | VT-N03: revisar armazenamento e testar encerramento/política de sessão | Q01 |
| RNF04 — Integridade e atomicidade | Gravações e referências | G02; UC03–UC08, UC11–UC12, UC14–UC19, UC21–UC22, UC25 | VT-N04: simular falha e conferir confirmação consistente; limite de lote a definir | Q05, Q14 |
| RNF05 — Concorrência e repetição | Operações com efeitos de negócio | G03; principalmente UC08, UC11–UC12, UC14–UC18, UC21, UC25 | VT-N05: executar conflito e reenvio sem efeitos incompatíveis/duplicados | Q07 e política técnica |
| RNF06 — Validação e persistência segura | Entradas recebidas e consultas ao banco | G05; casos com entrada de dados | VT-N06: enviar formatos inválidos e tentativas de injeção; revisar parametrização | Q03 e domínios por operação |
| RNF07 — Desempenho | Consultas e operações representativas | UC09–UC10, UC13, UC24 e demais operações sob carga | VT-N07: medir tempos/falhas no cenário de volume aprovado | Q15: metas e ambiente |
| RNF08 — Disponibilidade | Serviço como um todo | Transversal; não exige novo UC | VT-N08: medir janela e indisponibilidade conforme regra acordada | Q15: meta e janela |
| RNF09 — Recuperação | Dados, documentos e operação | Transversal; prova PT06 | VT-N09: restaurar e conciliar dentro dos limites aprovados | Q15: perda e tempo toleráveis |
| RNF10 — Usabilidade/compatibilidade | Interface dos três controles e operações principais | UC06, UC08, UC11–UC14, UC18 e navegação pertinente | VT-N10: executar roteiros com operadores nos ambientes acordados | Q16 |
| RNF11 — Manutenibilidade | Organização técnica e evolução | Todos os UCs; etapa 13 de arquitetura futura | VT-N11: revisar separação de responsabilidades, versões e testes do incremento | Convenções e processo a definir |
| RNF12 — Dados e documentos | Informações pessoais, acesso e retenção | UC04, UC10, UC13, UC18, UC20, UC22–UC25; G01/G04 | VT-N12: conferir finalidade/campos, acesso e política de retenção | Q11, Q12 |

### RFs e restrições de qualidade mais diretamente relacionados

A tabela complementa a visão transversal acima; não exclui outras restrições aplicáveis.

| RF | RNFs relacionados na análise |
| --- | --- |
| RF01 | RNF01, RNF03, RNF06 |
| RF02 | RNF01, RNF02, RNF03 |
| RF03 | RNF01, RNF02, RNF04, RNF06 |
| RF04 | RNF01, RNF02, RNF04, RNF12 |
| RF05 | RNF01, RNF04, RNF06 |
| RF06 | RNF01, RNF02, RNF04, RNF06 |
| RF07 | RNF01, RNF02, RNF04 |
| RF08 | RNF01, RNF02, RNF04, RNF05, RNF06 |
| RF09 | RNF01, RNF04, RNF07 |
| RF10 | RNF01, RNF02, RNF07, RNF12 |
| RF11 | RNF01, RNF02, RNF04, RNF05 |
| RF12 | RNF01, RNF02, RNF04, RNF05 |
| RF13 | RNF01, RNF02, RNF07, RNF12 |
| RF14 | RNF01, RNF02, RNF04, RNF05 |
| RF15 | RNF01, RNF02, RNF04, RNF05 |
| RF16 | RNF01, RNF02, RNF04 |
| RF17 | RNF01, RNF02, RNF04 |
| RF18 | RNF01, RNF02, RNF04, RNF12 |
| RF19 | RNF01, RNF02, RNF04, RNF06 |
| RF20 | RNF01, RNF02, RNF12 |
| RF21 | RNF01, RNF02, RNF04, RNF05 |
| RF22 | RNF01, RNF02, RNF04, RNF12 |
| RF23 | RNF01, RNF02, RNF12 |
| RF24 | RNF01, RNF07, RNF12 |
| RF25 | RNF01, RNF02, RNF04, RNF05, RNF06, RNF12 |

## 7. Matriz de regras propostas

A ligação abaixo reúne o catálogo e implicações propostas de análise. Regras permanecem RN-P provisórias até a etapa 11. Preservação histórica não significa retenção infinita ou ausência de política empresarial.

| Regra | RFs/UCs diretamente relacionados | Verificação candidata | Questões |
| --- | --- | --- | --- |
| RN-P01 — Saldo por eventos válidos | RF06, RF08–RF09, RF11, RF14–RF15, RF21, RF24; UCs correspondentes | Conciliar unidades e eventos; entrada 25, saída 5, retorno apto 1 = disponível 21 no mesmo conjunto | Q05, Q07–Q09, Q11, Q13 |
| RN-P02 — Inativo sem nova utilização; histórico preservado | RF07, RF10, RF12, RF23; UC07, UC10, UC12, UC23 | Inativar, consultar passado e tentar novo vínculo | Q04, Q07, Q12 |
| RN-P03 — Impedir uso incompatível | RF11–RF12; UC11–UC12 | Duas confirmações concorrentes não geram vínculos incompatíveis | Q07 |
| RN-P04 — Devolução encerra vínculo | RF13–RF14; UC13–UC14 | Encerrar utilização correta e preservar período anterior | Q07–Q08 |
| RN-P05 — Identificadores por tipo | RF06; UC06 | Validar unicidade/aplicabilidade após definir política | Q03 |
| RN-P06 — Saída identificável e origem aplicável | RF11, RF19; UC11, UC19 | Consultar destino, data, autor e referência quando exigida | Q07, Q10 |
| RN-P07 — Histórico e correção rastreáveis | RF03–RF04, RF06–RF07, RF10, RF13–RF18, RF20–RF23, RF25 e demais gravações pertinentes | Alterar cadastro/corrigir evento sem substituir silenciosamente o passado | Q02, Q06, Q11–Q12, Q14 |
| RN-P08 — Cadastro, estado e disponibilidade distintos | RF07, RF14–RF17; UCs correspondentes | Retorno em manutenção não vira disponível; inativação não equivale a baixa | Q04, Q08–Q09 |
| RN-P09 — Documento completo e versão identificável | RF22–RF23; UC22–UC23 | Recusar emissão incompleta e recuperar versão histórica correta | Q12 |

## 8. Critérios de aceite e verificações planejadas

Os 50 critérios são reproduzidos do catálogo para tornar o caminho RF → UC → aceite verificável. VT-Fxx-A/B são novos rótulos locais de verificações futuras, não testes implementados. Todos têm situação **NÃO EXECUTADO; CRITÉRIO CANDIDATO**. Um critério com política em aberto só poderá ser fechado após a decisão correspondente.

| Verificação planejada | Critério de origem | Caso | Resultado esperado do critério candidato |
| --- | --- | --- | --- |
| VT-F01-A | CA-RF01-1 | UC01 | Com credenciais válidas de usuário habilitado, iniciar sessão e apresentar somente as capacidades autorizadas. |
| VT-F01-B | CA-RF01-2 | UC01 | Com credenciais inválidas ou usuário desabilitado, negar acesso; após sair, a sessão encerrada não permite operação restrita. |
| VT-F02-A | CA-RF02-1 | UC02 | Uma alteração autorizada de permissão modifica o acesso conforme política aprovada e deixa registro rastreável. |
| VT-F02-B | CA-RF02-2 | UC02 | Uma tentativa sem permissão de administrar acesso é recusada e não modifica o usuário-alvo. |
| VT-F03-A | CA-RF03-1 | UC03 | Uma filial é relacionada à empresa válida e pode ser consultada pelos perfis permitidos. |
| VT-F03-B | CA-RF03-2 | UC03 | Referência a empresa inexistente é recusada; alteração não apaga vínculos históricos. |
| VT-F04-A | CA-RF04-1 | UC04 | Um colaborador cadastrado pode ser identificado no processo de entrega com o vínculo organizacional pertinente. |
| VT-F04-B | CA-RF04-2 | UC04 | Referência organizacional inválida é recusada; desligamento não apaga utilizações anteriores. |
| VT-F05-A | CA-RF05-1 | UC05 | Um equipamento pode selecionar classificação válida e consultar a descrição correspondente. |
| VT-F05-B | CA-RF05-2 | UC05 | Uma combinação proibida pelas relações aprovadas é recusada sem gravar referência inconsistente. |
| VT-F06-A | CA-RF06-1 | UC06 | No recebimento de 25 celulares, cada unidade concluída possui identificação interna distinta e pode ser consultada individualmente. |
| VT-F06-B | CA-RF06-2 | UC06 | Identificador que viole a política de unicidade aprovada é recusado; não tornar obrigatório um campo inaplicável ao tipo. |
| VT-F07-A | CA-RF07-1 | UC07 | Após inativação autorizada, o cadastro é identificado como inativo e utilizações antigas continuam consultáveis. |
| VT-F07-B | CA-RF07-2 | UC07 | Inativar não elimina histórico nem representa automaticamente uma baixa ou retorno ao estoque. |
| VT-F08-A | CA-RF08-1 | UC08 | Uma entrada concluída de 25 unidades permite conciliar as 25 identificações com a quantidade recebida e o local definido. |
| VT-F08-B | CA-RF08-2 | UC08 | Uma entrada não pode ser contabilizada duas vezes por repetição do mesmo envio confirmado; falha não deixa disponibilidade sem lastro. |
| VT-F09-A | CA-RF09-1 | UC09 | Em cenário aprovado de entrada 25, saída 5 e devolução 1 apta a retornar, apresentar saldo 21 e lista conciliável. |
| VT-F09-B | CA-RF09-2 | UC09 | Ativo em uso não aparece como disponível; transferência entre locais não cria aumento artificial no total da empresa. |
| VT-F10-A | CA-RF10-1 | UC10 | A consulta permite identificar recebimento, saída, destinatário e devolução do ativo de teste com suas referências. |
| VT-F10-B | CA-RF10-2 | UC10 | Inativação de cadastro não oculta utilizações antigas; perfil sem acesso não consulta dados restritos. |
| VT-F11-A | CA-RF11-1 | UC11 | Uma saída válida fica vinculada ao ativo e destino e afeta o saldo uma única vez, no marco operacional aprovado. |
| VT-F11-B | CA-RF11-2 | UC11 | Equipamento indisponível ou destino obrigatório ausente impede confirmação; nenhum vínculo parcial permanece após falha. |
| VT-F12-A | CA-RF12-1 | UC12 | Uma entrega válida cria vínculo de utilização consultável com equipamento, destinatário e responsável pela operação. |
| VT-F12-B | CA-RF12-2 | UC12 | Equipamento inativo ou já em uso não recebe vínculo incompatível segundo a regra aprovada, inclusive em tentativas concorrentes. |
| VT-F13-A | CA-RF13-1 | UC13 | Para ativo devolvido e depois entregue novamente, apresentar os dois vínculos separadamente com seus períodos. |
| VT-F13-B | CA-RF13-2 | UC13 | Alteração do responsável atual não substitui o destinatário do vínculo anterior. |
| VT-F14-A | CA-RF14-1 | UC14 | Ao devolver ativo apto, encerrar o vínculo e disponibilizar a unidade no local aprovado, com histórico preservado. |
| VT-F14-B | CA-RF14-2 | UC14 | Ativo devolvido com necessidade de manutenção não fica automaticamente disponível; devolução repetida não soma outra unidade. |
| VT-F15-A | CA-RF15-1 | UC15 | Uma transferência entre locais conserva a identidade do ativo e permite rastrear origem e destino sem duplicar o inventário. |
| VT-F15-B | CA-RF15-2 | UC15 | Falha ou repetição não deixa duas localizações atuais incompatíveis nem duplica saldo. |
| VT-F16-A | CA-RF16-1 | UC16 | Ativo encaminhado à manutenção sai da disponibilidade conforme regra e mantém histórico até a decisão de retorno. |
| VT-F16-B | CA-RF16-2 | UC16 | Encerramento da manutenção sem condição/destino exigidos não torna o ativo automaticamente apto. |
| VT-F17-A | CA-RF17-1 | UC17 | Após baixa aprovada, o ativo deixa de integrar o conjunto disponível e seu histórico permanece consultável. |
| VT-F17-B | CA-RF17-2 | UC17 | Baixa não apaga registros; ativo baixado não é entregue sem processo de reversão aprovado. |
| VT-F18-A | CA-RF18-1 | UC18 | Uma troca autorizada de vínculo permite consultar o vínculo anterior e o atual com seus períodos. |
| VT-F18-B | CA-RF18-2 | UC18 | Referência inexistente é recusada; troca não sobrescreve silenciosamente o histórico anterior. |
| VT-F19-A | CA-RF19-1 | UC19 | Uma saída com referência preenchida permite identificar essa origem ao consultar o histórico. |
| VT-F19-B | CA-RF19-2 | UC19 | Não apresentar a referência manual como integração ou como chamado validado no sistema externo. |
| VT-F20-A | CA-RF20-1 | UC20 | Uma alteração rastreável permite identificar quem alterou, quando e o que mudou, sem expor segredo de autenticação. |
| VT-F20-B | CA-RF20-2 | UC20 | Uma gravação crítica não é concluída sem sua evidência de auditoria exigida; perfil comum não altera registros de auditoria. |
| VT-F21-A | CA-RF21-1 | UC21 | Uma correção de evento mostra o original e a correção, permitindo recompor o saldo pela regra vigente. |
| VT-F21-B | CA-RF21-2 | UC21 | Não permitir substituição silenciosa de evento passado ou saldo manual sem evento de ajuste aprovado. |
| VT-F22-A | CA-RF22-1 | UC22 | Para utilização e modelo válidos, gerar PDF com dados correspondentes de pessoa, equipamento e operação aprovados. |
| VT-F22-B | CA-RF22-2 | UC22 | Campo obrigatório ausente produz mensagem clara, sem documento aparentemente válido mas incompleto. |
| VT-F23-A | CA-RF23-1 | UC23 | Após mudança cadastral, o termo emitido mantém os dados da emissão segundo a política documental aprovada. |
| VT-F23-B | CA-RF23-2 | UC23 | Inativação posterior não oculta termo autorizado; acesso por identificador direto sem permissão é recusado. |
| VT-F24-A | CA-RF24-1 | UC24 | Relatório filtrado apresenta os mesmos critérios de contagem da consulta operacional para o mesmo conjunto e período. |
| VT-F24-B | CA-RF24-2 | UC24 | Não somar categorias sobrepostas como se fossem ativos distintos; não incluir dados fora da abrangência autorizada. |
| VT-F25-A | CA-RF25-1 | UC25 | Em lote de teste aprovado, conciliar total de origem, registros aceitos e rejeitados e preservar os identificadores de correspondência necessários. |
| VT-F25-B | CA-RF25-2 | UC25 | Não importar silenciosamente vínculo inválido nem duplicar registros ao repetir lote já processado conforme política. |

## 9. Cenários críticos, provas e artefatos futuros

| Cenário da etapa 03 | RF/UC principal | Prova da viabilidade | Verificações relacionadas |
| --- | --- | --- | --- |
| C01 — Recebimento antes do envio | RF06, RF08–RF09; UC06, UC08–UC09 | PT01 | VT-F06-A, VT-F08-A/B, VT-F09-A; VT-N04 |
| C02 — Entrada, saída e retorno | RF08–RF09, RF11–RF14; UCs correspondentes | PT01, PT03 | VT-F09-A/B, VT-F11-A/B, VT-F14-A/B; VT-N04 |
| C03 — Entregas concorrentes | RF11–RF12; UC11–UC12 | PT02 | VT-F12-B; VT-N05 |
| C04 — Inativação e histórico | RF07, RF10, RF12, RF23; UCs correspondentes | PT04 | VT-F07-A/B, VT-F10-B, VT-F12-B, VT-F23-A/B |
| C05 — Documento incompleto | RF22; UC22 | PT05 | VT-F22-A/B |
| C06 — Falha e repetição | Gravações críticas, especialmente RF08, RF11–RF12, RF14 | PT03 e partes de PT01/PT02 | VT-N04, VT-N05 e critérios de recusa/consistência pertinentes |
| Recuperação do ambiente | RNF09; não é um novo caso de uso empresarial | PT06 | VT-N09 |

### Ligação com os próximos artefatos

| Etapa | Como usar a matriz | Situação nesta versão |
| --- | --- | --- |
| 07 — Classes | Relacionar RF/UC a conceitos, responsabilidades e multiplicidades validadas | Sem diagrama detalhado vinculado; recorte preliminar está na etapa 04 |
| 08 — Sequência | Detalhar interações e falhas dos cenários críticos | Sem sequência detalhada vinculada; recorte preliminar na etapa 04 |
| 09 — Atividades | Representar marcos de recebimento, saída e retorno com decisões aprovadas | Sem atividade detalhada vinculada |
| 10 — MVP | Aprovar capacidades por incremento e resolver prioridade de RF18 | Ainda sem definição final vinculada |
| 11 — Regras | Consolidar RN-P01–RN-P09 sem perder correspondências | Regras continuam propostas do catálogo |
| 12 — Dados | Validar entidades, atributos e cardinalidades dos conceitos | Nenhum esquema físico vinculado |
| 13 — Arquitetura | Definir como atender RNFs e garantias G01–G05 | Nenhuma implementação técnica vinculada |
| 14–16 — API, telas e plano | Relacionar operações e tarefas aos RFs/UCs aprovados | Rotas, telas finais e tarefas ainda não vinculadas |

Esses registros informam ausência de vínculo nesta matriz, não uma inspeção ou declaração de que toda pasta futura esteja vazia. Não se criam identificadores fictícios de código, endpoints, tabelas ou testes executados.

## 10. Divergências, lacunas e revisão necessária

| ID local | Constatação documental | Efeito | Encaminhamento proposto |
| --- | --- | --- | --- |
| D01 | Escopo 0.3 coloca Equipamentos, Linhas Telefônicas e Utilização como controles principais; RF18/UC18 ainda estão “Condicional” nos documentos 03/05 | A organização funcional foi atualizada, mas prioridade e recorte não foram sincronizados | Revisar 02–05 e definição do MVP quando autorizado; não excluir telefonia da visão nem declarar prioridade aprovada |
| D02 | Escopo foi generalizado para empresa com planilhas; documentos anteriores ainda contêm recortes e exemplos particulares | Exemplos podem ser confundidos com obrigações universais | Separar exemplos de teste do fluxo obrigatório na próxima revisão dos respectivos documentos |
| D03 | RF20 mistura registro automático e consulta; UC20 modela a consulta | Cobertura parece completa somente se as garantias transversais forem lidas | Manter RF20 + RNF02 + G02 nos fluxos de gravação; avaliar decomposição futura preservando IDs |
| D04 | RF11 e RF12 têm dependências mútuas e Q07 ainda aberta | Relação funcional pode ser confundida com ordem de desenvolvimento ou confirmação única | Resolver marco de envio/entrega/uso antes de fechar sequência e transações |
| D05 | Papel genérico especializado em UC15–UC17, UC20–UC21 e UC25 não define pessoas reais | Ainda não há matriz definitiva de autorização | Resolver Q01 sem conceder acesso amplo apenas por ser administrador |
| D06 | Conceitos e hipóteses H01–H04 da etapa 04 não são modelo final | Multiplicidade histórica ou destino loja pode ser interpretado incorretamente | Revisar Q02/Q05/Q07; não derivar tabelas automaticamente |
| D07 | RNF07–RNF10 têm metas e ambientes pendentes | Não é possível aprovar desempenho, disponibilidade, recuperação ou compatibilidade | Levantar Q15/Q16 e registrar medição futura |
| D08 | Não há evidência de aprovação, implementação ou execução vinculada | Cobertura documental não demonstra satisfação do requisito | Acrescentar evidências somente após produção e verificação |

Esta entrega registra os impactos e cria apenas a matriz. Não altera prioridades ou fontes dos documentos anteriores. A matriz não transforma as restrições específicas ainda candidatas em novas decisões de domínio.

## 11. Pendências e caminho de decisão

| Questões | Grupos afetados | Evidência/decisão esperada |
| --- | --- | --- |
| Q01 | RF01–RF02 e autorização de todos os demais | Perfis, ações e abrangência aprovados |
| Q02–Q03 | RF03–RF06 e conceitos de apoio | Campos, relações e identificação definidos |
| Q04–Q05 | RF07–RF09 e cálculo de estoque | Situação cadastral, entrada e disponibilidade delimitadas |
| Q06–Q08 | RF10–RF14 | História, marcos de entrega e retorno esclarecidos |
| Q09 | RF15–RF17 | Modalidades, estados e aprovações definidas |
| Q10 | RF18–RF19 | Telefonia detalhada e relação com solicitações decidida |
| Q11–Q12 | RF20–RF23; RNF02/RNF12 | Correção, auditoria, documentos e retenção definidos |
| Q13–Q14 | RF24–RF25 | Contagem gerencial e migração definidas |
| Q15–Q16 | RNF07–RNF10 | Metas, ambiente e critérios de uso acordados |

Bruno apoia o levantamento. A confirmação empresarial depende de responsável ainda a identificar. Cada decisão deverá registrar origem, aprovador, data e impacto, atualizando os documentos de referência e depois esta matriz.

## 12. Manutenção e critérios de revisão

1. Ao alterar o escopo, localizar RFs, UCs, regras, conceitos e aceites afetados.
2. Preservar IDs; ao dividir ou substituir requisito, registrar correspondência e motivo.
3. Atualizar situação e versão nas fontes, sem usar apenas esta matriz para aprovar mudanças.
4. Incorporar artefatos reais de modelagem e implementação quando forem produzidos.
5. Ligar testes executados a resultado, data, ambiente e versão testada; distinguir aprovação de critério e execução.
6. Registrar requisito adiado/rejeitado sem apagar sua história.

Checklist de revisão documental:

- [ ] Necessidades da proposta e os três controles têm vínculos rastreáveis.
- [ ] Todos os RFs e UCs estão relacionados; RF20 tem cobertura transversal explícita.
- [ ] RNFs e regras propostas têm caminho de verificação identificado.
- [ ] As pendências de prioridade e de negócio estão resolvidas para o incremento selecionado.
- [ ] Metas ainda abertas não são apresentadas como testes aprovados.
- [ ] Colaborador responsável e usuário que registra a operação permanecem distintos.
- [ ] Vínculos futuros se referem a artefatos realmente existentes e revisados.

Os itens são roteiro de aprovação futura. As conferências automáticas de contagem e referências realizadas na criação não substituem essa revisão de domínio.

## 13. Resultado desta versão e histórico

Cobertura estrutural registrada: **25 RFs, 25 UCs, 12 RNFs, 9 regras propostas e 50 critérios de aceite**, com 50 verificações funcionais e 12 verificações não funcionais planejadas. Não há requisito declarado implementado ou teste declarado aprovado.

| Versão | Data | Registro |
| --- | --- | --- |
| 0.1 | 20/10/2026 | Matriz inicial baseada no escopo 0.3 e catálogos existentes; cobertura, critérios, pendências e divergências registrados; sem implementação |
