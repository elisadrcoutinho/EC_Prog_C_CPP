#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

using namespace std;
using namespace mysqlx;

class AlunoDB { 
private:
    Session* session;  // Usando session para mysqlx

public:
    // Construtor: Conecta ao banco de dados
    AlunoDB() {
        // Conectando usando mysqlx (requer a porta 33060)
        session = new Session("localhost", 33060, "usuario", "senha");
        session->getSchema("escola");  // Conecta ao banco de dados "escola"
    }

    // Destrutor: Desconecta do banco de dados
    ~AlunoDB() {
        delete session;
    }

    // Função para adicionar um aluno
    void adicionarAluno(const std::string& nome, int idade, const std::string& curso) {
        Schema db = session->getSchema("escola");
        Table alunos = db.getTable("alunos");
        alunos.insert("nome", "idade", "curso").values(nome, idade, curso).execute();
        cout << "Aluno adicionado com sucesso." << endl;
    }

    // Função para listar todos os alunos
    void listarAlunos() {
        Schema db = session->getSchema("escola");
        Table alunos = db.getTable("alunos");
        RowResult result = alunos.select("id", "nome", "idade", "curso").execute();

        for (Row row : result) {
            cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << row[3] << endl;
        }
    }

    // Função para atualizar os dados de um aluno
    void atualizarAluno(int id, const std::string& nome, int idade, const std::string& curso) {
        Schema db = session->getSchema("escola");
        Table alunos = db.getTable("alunos");
        alunos.update().set("nome", nome).set("idade", idade).set("curso", curso).where("id = :id").bind("id", id).execute();
        cout << "Dados do aluno atualizados com sucesso." << endl;
    }

    // Função para deletar um aluno pelo ID
    void deletarAluno(int id) {
        Schema db = session->getSchema("escola");
        Table alunos = db.getTable("alunos");
        alunos.remove().where("id = :id").bind("id", id).execute();
        cout << "Aluno deletado com sucesso." << endl;
    }
};

// Função principal
int main() {
    // Criando o objeto para acessar as funções
    AlunoDB db;

    // Adicionando um aluno
    db.adicionarAluno("Carlos", 20, "Engenharia");

    // Listando alunos
    db.listarAlunos();

    // Atualizando dados do aluno
    db.atualizarAluno(1, "Carlos Silva", 21, "Engenharia Civil");

    // Listando alunos atualizados
    db.listarAlunos();

    // Deletando aluno
    db.deletarAluno(1);

    return 0;
}