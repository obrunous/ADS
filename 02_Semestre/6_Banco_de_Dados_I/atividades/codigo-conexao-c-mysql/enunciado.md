# Código de Conexão LP C com BD MySQL

**Item postado:** 25/09/2026.

**Fonte:** material fornecido pelo aluno nesta conversa.

## Código apresentado

```c
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conexao;

    // Inicializa a estrutura MYSQL
    conexao = mysql_init(NULL);

    if (conexao == NULL) {
        fprintf(stderr, "Erro ao inicializar o MySQL!\n");
        return 1;
    }

    // Tenta conectar ao banco de dados
    // Parâmetros: (conexao, host, usuário, senha, nome_do_banco, porta, unix_socket, flags)
    if (mysql_real_connect(conexao, "localhost", "root", "sua_senha", "seu_banco", 3306, NULL, 0) == NULL) {
        fprintf(stderr, "Erro de conexão: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return 1;
    }

    printf("Conexão realizada com sucesso!\n");

    // Fecha a conexão
    mysql_close(conexao);
    return 0;
}
```

`sua_senha` e `seu_banco` são marcadores do exemplo original, não credenciais confirmadas. O código foi documentado, sem execução ou teste de conexão nesta etapa.
