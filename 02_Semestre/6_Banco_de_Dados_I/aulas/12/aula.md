# Aula 12 - Registro de 09/10/2026

**Data:** 09/10/2026

**Fonte:** [Página do encontro no Notion](https://app.notion.com/p/3aed0f04d5398191b10ac4ecbdc3fbbc)

> **Divergência na fonte:** o título informa “Não teve aula”, mas o corpo documenta a configuração do VS Code para C + MySQL e descreve uma aula em andamento. O conteúdo abaixo foi preservado como registro histórico da página. As versões, os caminhos e os testes mencionados não foram verificados novamente nesta cópia.

## Registro da configuração do VS Code — C + MySQL
Registro de 09/10/2026. A aula está em andamento; os próximos passos serão acompanhados conforme as orientações do professor.
### Continuidade da Atividade 08
Referência da aula anterior: [Interface em C para receber dados do sistema acadêmico](https://app.notion.com/p/3aed0f04d53981c18224f9c1705a166d).
Foi lido o enunciado e o arquivo `atividade_08/atividade08.c`, na pasta `/Users/brunoalves/Documents/banco_de_dados`.
A interface recebe 16 atributos: 7 de DISCENTE, 5 de DISCIPLINA e 4 de CURSA. Usa `printf` e `scanf` para receber e exibir os valores, sem persistência.
Segundo o relato do aluno, o professor está explicando a configuração do Code::Blocks para utilizar MySQL com C. No Mac do aluno, essa preparação foi adaptada para o VS Code.
### Verificação do ambiente
- VS Code 1.140.0, arquitetura x64, instalado.
- Extensão Microsoft C/C++ instalada.
- Apple Clang 14.0.3 disponível em `/usr/bin/clang`.
- MySQL 8.0.36 instalado em `/usr/local/mysql`.
- Cabeçalho encontrado: `/usr/local/mysql/include/mysql.h`.
- Biblioteca encontrada: `/usr/local/mysql/lib/libmysqlclient.dylib`.
- Também existe MariaDB 10.4.28 do XAMPP. Os comandos `mysql` e `mysql_config` do terminal apontavam primeiro para `/Applications/XAMPP/xamppfiles/bin`.
- A pasta do projeto ainda não possuía configuração `.vscode`. Foram usados caminhos explícitos para o MySQL 8.0.36, sem alterar o PATH global.
### Configuração realizada
Foram criados dois arquivos dentro de `/Users/brunoalves/Documents/banco_de_dados/.vscode`:
- `tasks.json`: tarefa padrão de compilação do arquivo C atual e tarefa de compilação seguida de execução no terminal integrado.
- `c_cpp_properties.json`: configuração do IntelliSense para Clang, C11, arquitetura macOS x64 e cabeçalhos do MySQL.
A compilação usa `-std=c11 -Wall -Wextra -pedantic -g`, com os seguintes caminhos e opções:
```text
-I/usr/local/mysql/include
-L/usr/local/mysql/lib
-lmysqlclient
-Wl,-rpath,/usr/local/mysql/lib
```
O executável é gerado ao lado do arquivo C, com o mesmo nome-base e extensão `.out`. A opção `-g` inclui informações para depuração; não foi criada uma configuração de depurador.
### Cabeçalho adequado a esta instalação
```c
#include <mysql.h>
```
Com o caminho de inclusão configurado, esse cabeçalho foi encontrado. O formato `#include <mysql/mysql.h>` apresentado no exemplo anterior falhou com `file not found` nesta instalação. O arquivo C da Atividade 08 não foi modificado.
### Como usar no VS Code
1. Abrir a pasta `/Users/brunoalves/Documents/banco_de_dados` no VS Code.
2. Abrir e salvar o arquivo `.c` que será executado.
3. Acessar **Terminal → Executar Tarefa**.
4. Selecionar **C + MySQL: compilar e executar arquivo atual**.
Para apenas compilar, usar **Terminal → Executar Tarefa de Compilação**. A tarefa padrão é **C + MySQL: compilar arquivo atual**.
Essas instruções usam as tarefas criadas; os botões de outras extensões, como Code Runner, não foram configurados.
### Testes realizados e resultado
Os dois arquivos JSON foram lidos e validados. Em uma pasta temporária, foi compilado e executado um pequeno programa que inclui `mysql.h`, chama `mysql_init(NULL)`, mostra a versão da biblioteca com `mysql_get_client_info()` e libera a estrutura com `mysql_close()`.
Foram usados os comandos e argumentos extraídos do próprio `tasks.json`. Compilação e execução terminaram com código 0. Saída:
```text
MySQL 8.0.36: OK
```
Isso confirma que o compilador encontra o cabeçalho, vincula a biblioteca e consegue carregá-la durante a execução. O acionamento pelo menu do VS Code não foi testado pela interface gráfica.
### O que ainda falta verificar
- [x] Compilador e extensão C/C++ instalados.
- [x] Biblioteca cliente MySQL encontrada e testada.
- [x] Tarefas de compilação e execução configuradas.
- [x] Caminho dos cabeçalhos configurado para o IntelliSense.
- [ ] Confirmar o serviço MySQL e a instância que será usada na aula.
- [ ] Testar conexão com usuário, senha, porta e banco corretos.
- [ ] Integrar a interface da Atividade 08 conforme a orientação do professor.
**Limite do teste:** não houve chamada a `mysql_real_connect`, autenticação, consulta ou gravação no banco. As anotações da aula mencionam porta 3306 e usuário root, mas esses parâmetros ainda não foram validados por uma conexão nesta etapa.
Os arquivos do exercício foram preservados. Este registro documenta a preparação local do ambiente; não afirma que a integração com o servidor esteja concluída.
