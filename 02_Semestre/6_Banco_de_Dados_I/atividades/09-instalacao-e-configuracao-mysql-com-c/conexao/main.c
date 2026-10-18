#include <stdio.h>
#include <unistd.h>
#include <mysql.h>

int main(void){
    MYSQL *conexao;
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    char *senha;

    conexao = mysql_init(NULL);
    if(conexao == NULL){
        fprintf(stderr, "Erro ao inicializar o MySQL.\n");
        return 1;
    }

    // A senha é digitada no terminal, sem aparecer na tela ou ficar no código.
    senha = getpass("Senha do MySQL para root: ");
    if(senha == NULL){
        fprintf(stderr, "Nao foi possivel ler a senha.\n");
        mysql_close(conexao);
        return 1;
    }

    if(mysql_real_connect(conexao, "127.0.0.1", "root", senha,
                          "sistema_academico", 3306, NULL, 0) == NULL){
        fprintf(stderr, "Erro de conexao: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return 1;
    }

    printf("Conexao realizada com sucesso!\n");

    // Consulta de leitura para confirmar o banco selecionado.
    if(mysql_query(conexao, "SELECT DATABASE()") != 0){
        fprintf(stderr, "Erro na consulta: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return 1;
    }

    resultado = mysql_store_result(conexao);
    if(resultado == NULL){
        fprintf(stderr, "Erro ao receber resultado: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return 1;
    }

    linha = mysql_fetch_row(resultado);
    if(linha != NULL && linha[0] != NULL){
        printf("Banco conectado: %s\n", linha[0]);
    }

    mysql_free_result(resultado);
    mysql_close(conexao);
    return 0;
}
