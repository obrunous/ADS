# 02 — Análise de viabilidade

## 1. Identificação e situação

| Campo | Registro |
| --- | --- |
| Projeto | Sistema de Controle de Ativos de TI |
| Documento | Análise preliminar de viabilidade |
| Versão | 0.1 — para levantamento e validação |
| Data | 20/10/2026 |
| Responsável pelo levantamento | Bruno |
| Parecer | Continuidade da análise recomendada; viabilidade global ainda não comprovada |
| Aprovação empresarial e acadêmica | PENDENTE DE DECISÃO |

### Fontes e limites da evidência

- [Contexto central do projeto](../../CONTEXTO_SISTEMA_CONTROLE_ATIVOS_TI.md).
- [01 — Escopo e proposta](../01-escopo-e-proposta/01-escopo-e-proposta.md).

A análise usa o contexto fornecido por Bruno e o escopo proposto. Não foram executados testes de desempenho, entrevistas adicionais, inspeção de infraestrutura, auditoria de planilhas, levantamento de preços ou provas técnicas nesta etapa. Valores, volumes e prazos não informados permanecem em aberto.

**Relatado** identifica informação do contexto. **Proposto** identifica uma recomendação a validar. **PENDENTE DE DECISÃO** identifica uma escolha ainda não tomada; **PENDENTE DE LEVANTAMENTO** identifica informação ou evidência que falta obter.

## 2. Questão de viabilidade e solução avaliada

A questão é se a empresa e a equipe conseguem construir, operar e manter um sistema que controle ativos desde o recebimento, com saldo explicável por movimentações, identificação individual, utilização e histórico confiável.

A solução considerada é uma aplicação web com HTML, CSS, JavaScript, PHP e MySQL, desenvolvida incrementalmente. O recorte sugerido compreende acesso e cadastros mínimos, recebimento, identificação dos ativos, consulta de estoque, saída/entrega, utilização, devolução e histórico.

Telefonia e termos devem ser incluídos no primeiro ciclo se forem indispensáveis à operação validada. A decisão altera esforço, dados necessários e critérios de aceite. O produto completo também prevê transferência, manutenção, baixa, relatórios e demais capacidades do escopo, sem pressupor sua entrega simultânea.

## 3. Síntese do parecer preliminar

| Dimensão | Avaliação atual | Condição para conclusão |
| --- | --- | --- |
| Técnica | Há uma abordagem coerente com a stack proposta; execução ainda não demonstrada | Validar ambiente, equipe, regras críticas e provas técnicas |
| Operacional | O problema é relatado e o fluxo futuro foi proposto | Confirmar responsáveis, rotina, exceções e adoção |
| Econômica | Não conclusiva | Levantar esforço, infraestrutura, operação e benefícios |
| Prazo e equipe | Não conclusiva | Confirmar disponibilidade, escopo e calendário |
| Dados e migração | Dependente de análise do legado | Medir qualidade, volume e capacidade de conciliação |
| Segurança e continuidade | Necessidades identificadas; atendimento não demonstrado | Definir controles, responsáveis e testes |
| Implantação | Ambiente e processo de transição não definidos | Aprovar piloto, suporte, recuperação e operação |

Não há evidência para aprovar uma implantação empresarial nem para prometer prazo ou retorno financeiro. Há base suficiente para continuar o levantamento e planejar validações pequenas, com escopo controlado.

## 4. Viabilidade técnica

### Adequação conceitual da stack

A proposta envolve cadastros, consultas, vínculos e transações sobre dados relacionados. O desenho frontend → backend PHP → MySQL é coerente com essas necessidades. Isso é uma avaliação conceitual, não comprovação de capacidade do ambiente ou de desempenho.

| Componente | Papel previsto | Verificação necessária |
| --- | --- | --- |
| HTML, CSS e JavaScript | Interface web para operações e consultas | Navegadores e dispositivos usados pela equipe |
| PHP | Validar regras, autorizar e executar operações | Versão suportada no ambiente escolhido, extensões e experiência da equipe |
| MySQL | Persistência, integridade e transações | Versão, mecanismo transacional, administração e capacidade |
| VS Code | Edição e apoio ao desenvolvimento | Ambiente disponível e configuração do projeto |
| MySQL Workbench | Modelagem e administração | Compatibilidade com a instância que será usada |
| Git | Histórico e revisão de mudanças | Repositório, fluxo de revisão e responsáveis |
| Geração de PDF | Termos vinculados à utilização | Biblioteca, modelo, fontes e tratamento de dados incompletos a selecionar |

Nenhuma versão, framework ou biblioteca adicional fica aprovada por este documento. A seleção deve considerar o ambiente e as necessidades reais, sem ampliar artificialmente a stack.

### Pontos críticos a demonstrar

1. **Recebimento e identificação:** concluir uma entrada sem duplicar ativos ou disponibilizar unidades ainda não identificadas, conforme regra a definir.
2. **Consistência transacional:** impedir que uma falha deixe movimentação registrada sem atualizar o vínculo correspondente, ou vice-versa.
3. **Concorrência:** duas entregas simultâneas do mesmo equipamento não podem criar utilizações incompatíveis segundo as regras aprovadas.
4. **Saldo e inventário:** distinguir estoque disponível, localização e total de ativos, com conciliação por eventos.
5. **Histórico:** manter vínculos encerrados e rastrear correções, mesmo após mudanças cadastrais ou inativação.
6. **Termos:** bloquear geração incompleta e definir como preservar informações documentais quando os cadastros mudarem.

### Arquitetura preliminar para avaliação

Propõe-se avaliar uma aplicação simples e modular, com responsabilidades separadas para interface, regras e persistência. A escolha definitiva pertence à etapa de arquitetura.

Não há necessidade demonstrada de microsserviços, app nativo ou API pública para o primeiro ciclo. Integrações automáticas com ERP, GLPI e outros sistemas permanecem fora do recorte inicial proposto. Referenciar um chamado manualmente não exige integração.

### Provas técnicas futuras propostas

| Código local | Experimento a planejar após validação do requisito | Evidência esperada |
| --- | --- | --- |
| PT01 | Registrar um recebimento e identificar suas unidades em ambiente de teste | Contagem e identificação conciliadas, inclusive após falha simulada |
| PT02 | Tentar entregar o mesmo ativo em duas operações concorrentes | Apenas o resultado permitido pela regra é confirmado; nenhuma duplicidade |
| PT03 | Simular erro durante saída ou devolução | Operação integralmente confirmada ou revertida |
| PT04 | Consultar utilização encerrada de ativo depois inativado | Dados históricos continuam acessíveis ao perfil autorizado |
| PT05 | Gerar termo com dados completos e depois com campo obrigatório ausente | PDF correto no primeiro caso; erro claro no segundo |
| PT06 | Restaurar uma cópia de segurança em ambiente isolado | Dados recuperados e consultas críticas conciliadas |

Esses experimentos não foram executados e não autorizam implementação nesta etapa. Seus resultados deverão alimentar a revisão do parecer.

## 5. Viabilidade operacional

O controle desde o recebimento exige que alguém registre a chegada antes da primeira destinação. Se a operação continuar cadastrando apenas no envio, a mudança de software não resolverá o problema de saldo.

| Processo | Condição operacional necessária | Pendência |
| --- | --- | --- |
| Recebimento | Responsável registra quantidade e identifica unidades | Quem executa, quando e com qual documento? |
| Estoque | Local e condição do ativo são conhecidos | Quais locais existem e como conciliá-los fisicamente? |
| Entrega | Destino, responsável e equipamento são confirmados | Quem autoriza e quem confirma recebimento? |
| Utilização | Vínculo é aberto e encerrado no momento adequado | Colaborador é apenas cadastro ou também usuário? |
| Devolução | Condição do ativo é avaliada antes de voltar ao disponível | Quem decide entre estoque, manutenção e baixa? |
| Correção | Erros são corrigidos com rastreabilidade | Qual perfil pode corrigir e como registrar o motivo? |
| Termos | Dados e modelo são validados pelo responsável | Quais campos, aceite e versões são necessários? |
| Operação diária | Há suporte e responsáveis por acessos e continuidade | Quem atende incidentes e administra o ambiente? |

### Adoção e treinamento propostos

Propõe-se validar o fluxo com operadores reais antes de ampliar o uso, preparar um roteiro curto de recebimento, entrega e devolução e acompanhar um piloto com amostra acordada. Devem ser observadas dificuldades de preenchimento, disponibilidade de dados e divergências com a rotina.

A unidade, os participantes, a duração e a amostra do piloto são **PENDENTE DE DECISÃO**. Não se presume adesão dos usuários nem substituição imediata dos controles atuais.

## 6. Viabilidade econômica

Não há orçamento, taxa de trabalho, preços contratados ou medição de perdas no material disponível. Portanto, não é possível calcular custo total, economia, retorno do investimento ou prazo de retorno de forma fundamentada.

A disponibilidade de ferramentas sem custo direto em determinado cenário não elimina custos de análise, desenvolvimento, infraestrutura, treinamento, manutenção ou obrigações de licenciamento a verificar no uso escolhido.

### Investimento inicial e custos recorrentes

| Grupo | Itens a levantar | Situação |
| --- | --- | --- |
| Construção e preparação | Levantamento, requisitos, modelagem, programação, testes e documentação | PENDENTE DE LEVANTAMENTO |
| Dados | Análise, saneamento, conferência e eventual importação | PENDENTE DE LEVANTAMENTO |
| Implantação | Configuração, piloto, treinamento e transição | PENDENTE DE LEVANTAMENTO |
| Infraestrutura | Servidor, armazenamento, rede e ambientes | PENDENTE DE LEVANTAMENTO |
| Operação | Hospedagem ou operação interna, backups, monitoramento e suporte | PENDENTE DE LEVANTAMENTO |
| Evolução | Correções, atualizações e novas funcionalidades | PENDENTE DE LEVANTAMENTO |
| Dependências | Eventuais bibliotecas, serviços, licenças e contratos | PENDENTE DE LEVANTAMENTO |

Para planejamento, separar gastos de implantação dos recorrentes, frequentemente tratados como investimento inicial/CAPEX e operação/OPEX. A classificação contábil efetiva deve ser confirmada pela empresa; esta análise não faz esse enquadramento.

### Modelo de estimativa a preencher

```text
Esforço por etapa = horas previstas por atividade
Custo de trabalho = soma das horas por perfil × custo/hora correspondente
Custo inicial estimado = trabalho inicial + preparação + implantação + demais gastos iniciais
Custo operacional mensal = infraestrutura + suporte + manutenção + serviços recorrentes
Custo no horizonte escolhido = custo inicial + custos recorrentes do período
```

Registrar premissas, fonte, data e intervalo de incerteza de cada estimativa. Não duplicar custos já incluídos em outra categoria. Horizonte de avaliação, taxas e valores: **PENDENTE DE DECISÃO**.

### Benefícios e como medi-los

| Benefício esperado | Medição proposta antes e depois do piloto |
| --- | --- |
| Consultas mais ágeis | Tempo para localizar ativo, responsável e histórico |
| Estoque mais confiável | Divergências entre contagem física e registros, usando o mesmo local e critério |
| Menos retrabalho | Ocorrências e tempo gasto com correções e conciliação |
| Termos consistentes | Ocorrências de geração incompleta ou necessidade de refazer documento |
| Rastreabilidade | Proporção de movimentações com ativo, destino, data e autor identificados |

Definir amostra, período de observação, responsável e metas antes de comparar resultados. Nenhum percentual de melhoria está comprovado.

## 7. Viabilidade de prazo e capacidade da equipe

O contexto identifica Bruno no levantamento, execução e validação e prevê apoio de IAs. Não informa equipe de desenvolvimento confirmada, horas semanais, data de entrega ou calendário de homologação. Não se transfere a equipe do Organizador Pessoal para este projeto.

Apoio de IA não elimina revisão humana, testes, aprendizagem ou validação empresarial. A estimativa deve incluir essas atividades e a disponibilidade de quem toma decisões sobre o processo.

| Marco proposto | Dependência de entrada | Evidência para concluir |
| --- | --- | --- |
| M01 — Processo e recorte inicial | Acesso aos responsáveis | Fluxo e limites aceitos |
| M02 — Requisitos e regras | M01 e exemplos reais | Critérios de aceite e exceções documentados |
| M03 — Modelagem e arquitetura | M02 e análise dos dados | Relacionamentos e decisões técnicas revisados |
| M04 — Incrementos do ciclo principal | M03 e ambiente de teste | Operações testadas e histórico conciliado |
| M05 — Piloto | Incremento utilizável e dados preparados | Evidências operacionais e correções registradas |
| M06 — Decisão de implantação | Piloto e continuidade verificados | Aceite, suporte e recuperação definidos |

Datas, duração, responsáveis e folga por marco são **PENDENTE DE DECISÃO**. Esses marcos orientam análise; não são cronograma contratado.

Se prazo e capacidade não comportarem o escopo, a decisão proposta é reduzir capacidades não essenciais e preservar integridade, autorização e histórico do ciclo entregue. Não se deve anunciar o produto completo com base no esforço de um protótipo de cadastro.

## 8. Infraestrutura, volume e desempenho

Antes de dimensionar o ambiente, levantar:

- total de equipamentos, linhas, colaboradores, empresas e filiais;
- movimentações diárias e crescimento esperado do histórico;
- operadores simultâneos, picos e operações mais frequentes;
- quantidade, tamanho e política de armazenamento dos PDFs;
- locais de acesso, qualidade da rede e necessidade de acesso remoto;
- tempo de resposta aceitável para consultas, gravações e relatórios;
- horário de operação e impacto de indisponibilidade;
- perda de dados tolerável e tempo máximo aceitável para recuperação.

Nenhum limite de carga, tempo de resposta ou percentual de disponibilidade foi definido. Metas serão requisitos não funcionais a validar e medir, não valores copiados de exercícios acadêmicos.

### Ambientes possíveis a comparar

| Alternativa de ambiente | Aspectos a avaliar |
| --- | --- |
| Servidor interno | Capacidade existente, administração, acesso das filiais, energia, backups e suporte |
| Hospedagem externa | Compatibilidade técnica, custo, acesso, proteção dos dados, suporte e recuperação |
| Ambiente local de desenvolvimento | Adequação para estudo e testes; não comprova condições de produção |

A existência de uma máquina de desenvolvimento não demonstra capacidade para operar o sistema empresarial. O ambiente de produção e seus responsáveis ainda não foram escolhidos.

## 9. Dados legados e transição

As planilhas e controles atuais são fontes de descoberta do domínio. Não constituem automaticamente requisitos completos nem dados prontos para importação.

Proposta de preparação:

1. Inventariar as fontes autorizadas e identificar responsável e significado de cada campo.
2. Medir ausências, duplicidades, formatos inconsistentes e vínculos sem correspondência.
3. Definir identificadores, estados e regras com o responsável do processo.
4. Sanear cópias de trabalho, preservando as fontes e registrando transformações.
5. Validar amostra e conciliar contagens e utilizações abertas.
6. Planejar importação em teste, conferir resultados e registrar falhas.
7. Aprovar a transição e só então executar o procedimento autorizado.

### Alternativas para início de operação

- **Somente novos recebimentos:** reduz trabalho inicial, mas não oferece inventário completo do legado.
- **Carga inicial saneada:** amplia cobertura, mas exige preparação e conciliação.
- **Transição gradual por unidade ou tipo:** limita o lote inicial, mas exige delimitar claramente os controles válidos durante a coexistência.

Escolha e critérios de corte: **PENDENTE DE DECISÃO**. Deve-se evitar registros concorrentes divergentes entre planilha, ERP e sistema novo. É necessário definir qual fonte prevalece em cada etapa e quem reconcilia diferenças.

## 10. Segurança, acesso e continuidade

O contexto exige validação no backend, prepared statements, hash de senha, menor privilégio, configuração separada e auditoria. O atendimento deverá ser demonstrado na implementação e nos testes; não é uma capacidade já existente.

| Área | Condição proposta para operação | Evidência a produzir |
| --- | --- | --- |
| Acesso | Perfis e permissões aprovados | Matriz de acesso e testes de autorização |
| Dados | Coletar apenas o necessário para o processo | Campos e finalidade validados pela empresa |
| Credenciais | Segredos fora do frontend e do conteúdo público do projeto | Revisão de configuração e acesso |
| Integridade | Operações críticas consistentes e rastreáveis | Testes transacionais e de concorrência |
| Documentos | PDFs acessíveis apenas a perfis autorizados | Testes de acesso e tratamento de campos ausentes |
| Backup | Cópias protegidas e recuperação verificável | Restauração testada e relatório de conciliação |
| Incidentes | Responsável e procedimento de resposta | Plano de atendimento e comunicação |

Políticas empresariais de privacidade, retenção, descarte, termos e responsabilidades precisam ser obtidas com as áreas competentes antes do uso de dados reais. Esta etapa não conclui conformidade jurídica nem atribui validade legal aos PDFs.

Preservar histórico operacional não resolve por si só a política de retenção. A regra de não apagar histórico deve ser compatibilizada com as políticas aprovadas e as obrigações aplicáveis, sem definir prazos por suposição.

## 11. Alternativas de solução

| Alternativa | Possível benefício | Limitação ou dependência |
| --- | --- | --- |
| Melhorar os controles atuais | Menor mudança imediata; permite esclarecer processo | Pode manter fragmentação e controles manuais; precisa ser avaliada |
| Configurar ou ampliar solução existente | Pode aproveitar operação e suporte já disponíveis | Recursos, contratos, permissões e aderência não foram verificados |
| Desenvolver sistema próprio incremental | Permite modelar o ciclo e aprender com o domínio real | Exige desenvolvimento, manutenção, infraestrutura e validação |

A escolha de sistema próprio é a direção do contexto, mas a comparação empresarial ainda exige evidências. Não se afirma que o Sankhya ou outra ferramenta possua ou deixe de possuir determinada função sem verificação. Nenhuma integração ou aquisição é recomendada como decisão final nesta análise.

## 12. Registro inicial de riscos

Os códigos abaixo pertencem a este documento. Probabilidade e impacto permanecem qualitativamente não classificados por falta de evidência; não se inventa pontuação numérica.

| ID | Risco e possível efeito | Tratamento proposto | Sinal a acompanhar |
| --- | --- | --- | --- |
| V-R01 | Escopo crescer e ultrapassar capacidade | Aprovar recorte e registrar mudanças | Inclusão de módulos sem revisão de esforço |
| V-R02 | Regras de saldo e estado gerarem divergências | Validar eventos com exemplos e conciliar ativos | Quantidades sem explicação por movimentação |
| V-R03 | Legado inconsistente impedir carga confiável | Sanear amostra antes de estimar migração | Duplicidades e vínculos incompletos |
| V-R04 | Disponibilidade insuficiente da equipe atrasar entrega | Levantar horas e limitar tarefas | Marcos sem responsável ou validação |
| V-R05 | Operações concorrentes criarem vínculos incompatíveis | Validar desenho transacional e testar concorrência | Dupla entrega ou utilização sobreposta |
| V-R06 | Alteração cadastral prejudicar termo ou histórico | Definir dados históricos e versionamento documental | PDF mudar ou perder dados após atualização |
| V-R07 | Acesso inadequado expor dados ou permitir alterações | Definir permissões e testar autorização | Operação fora do perfil permitido |
| V-R08 | Falha de ambiente causar perda ou indisponibilidade | Definir backup, restauração e suporte | Cópias sem recuperação comprovada |
| V-R09 | Operadores não registrarem recebimentos a tempo | Ajustar rotina e acompanhar piloto | Ativos físicos sem identificação no sistema |
| V-R10 | Integração prematura ampliar dependências | Manter limites do primeiro ciclo e avaliar separadamente | Entrega depender de API não validada |

Responsáveis, periodicidade de revisão, prioridade e resposta detalhada: **PENDENTE DE DECISÃO**. Bruno pode apoiar a coleta, mas não se presume que assuma sozinho todos os riscos operacionais.

## 13. Plano de obtenção das evidências faltantes

| ID | Informação necessária | Forma proposta de obtenção | Quem deve confirmar |
| --- | --- | --- | --- |
| V01 | Fluxo, exceções e responsáveis | Entrevista e observação autorizada | Responsável empresarial a identificar |
| V02 | Núcleo do MVP, termos e telefonia | Revisão de exemplos de entrega e devolução | Responsável do processo e Bruno |
| V03 | Volumes e concorrência | Contagem de fontes e observação da rotina | Operação e responsável técnico |
| V04 | Qualidade do legado | Perfil de amostra autorizada | Dono dos dados e Bruno |
| V05 | Capacidade da equipe e prazo | Disponibilidade por atividade e calendário | Participantes e avaliador quando aplicável |
| V06 | Ambiente, suporte e recuperação | Inventário técnico e revisão operacional | Responsável pela infraestrutura |
| V07 | Custos e benefícios | Estimativa por atividade e medições do processo | Responsáveis empresarial e financeiro |
| V08 | Acesso, dados e termos | Revisão das políticas e modelos | Áreas competentes da empresa |
| V09 | Regras técnicas críticas | Provas futuras PT01–PT06 e resultados registrados | Equipe técnica e validador do processo |

Não foram agendadas entrevistas nem executados contatos externos. Datas e participantes devem ser definidos nas próximas decisões.

## 14. Condições para avançar e critérios de interrupção

### Avançar para requisitos e modelagem

É recomendável continuar a documentação com requisitos candidatos e perguntas abertas, mantendo rastreabilidade com o escopo. Confirmar o responsável pela validação e priorizar o ciclo operacional antes de congelar requisitos e DER.

### Avançar para implementação do primeiro incremento

Condições propostas: recorte aceito; regras do incremento compreendidas; critérios de aceite definidos; dados e relacionamentos revisados; capacidade e ambiente de teste disponíveis; tarefa pequena com arquivos, testes e resultado esperado delimitados.

### Avançar para piloto e implantação

Condições propostas: fluxo principal testado; dados conciliados; autorização e recuperação verificadas; suporte e responsáveis definidos; estratégia de transição aceita; validação empresarial registrada.

### Rever, reduzir ou adiar

Reavaliar a iniciativa se não houver responsável para validar o processo, se o prazo disponível for incompatível com o núcleo mínimo, se não houver condições de proteger e recuperar os dados ou se a solução existente atender melhor às necessidades após avaliação. Cada decisão deve registrar evidência e impacto, sem descartar silenciosamente requisitos.

## 15. Conclusão e recomendação

O projeto apresenta uma necessidade operacional concreta no contexto relatado: controlar ativos antes do envio e reconstruir seu ciclo de vida com estoque e utilização consistentes. A stack proposta oferece uma direção conceitual coerente, mas sua aplicação ao ambiente real ainda depende de evidências.

**Parecer preliminar: prosseguir com levantamento, requisitos e modelagem incremental. A viabilidade global permanece não comprovada, especialmente nas dimensões econômica, de prazo, infraestrutura e operação.**

A recomendação não aprova investimento, cronograma, aquisição ou implantação. A conclusão deverá ser revista com o recorte aceito, estimativas, análise do legado e resultados das validações propostas.

## 16. Histórico e próximos documentos

| Versão | Data | Registro |
| --- | --- | --- |
| 0.1 | 20/10/2026 | Análise preliminar baseada no contexto e no escopo; dimensões, riscos, alternativas, evidências e condições de avanço documentados; sem testes executados ou implementação |

Próxima etapa prevista: análise e especificação de requisitos, na pasta `03-analise-e-especificacao-de-requisitos`. As respostas V01–V09 deverão atualizar este parecer; mudanças no recorte deverão ser refletidas também no documento de escopo.
