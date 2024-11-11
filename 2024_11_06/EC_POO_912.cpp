#include <iostream>     // Biblioteca padrão para entrada e saída
#include <string>       // Biblioteca para manipulação de strings
#include <fstream>      // Biblioteca para manipulação de arquivos
#include <ctime>        // Biblioteca para obter data e hora

using namespace std;

// Função para exibir carimbo de data/hora e outras informações do programa
void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << endl;
}

void mudaLinha(void) {
    printf("\n");
}

// Função para exibir separador visual
void separador(void) {
    for (int i = 0; i < 120; i++) {
        printf("*");
    }
}

// Classe base para representar um DVD com título e preço
class DVD {
private:
    string titulo;      // Armazena o título do DVD
    float preco;        // Armazena o preço do DVD

public:
    // Construtor padrão com valores iniciais opcionais para título e preço
    DVD(string t = "", float p = 0.0) : titulo(t), preco(p) {}

    // Métodos de acesso (getters) para obter o título e preço do DVD
    string getTitulo() const { return titulo; }
    float getPreco() const { return preco; }

    // Método para configurar o título e o preço do DVD
    void setDVD(const string &t, float p) {
        titulo = t;
        preco = p;
    }

    // Método para imprimir os detalhes do DVD no console
    void imprimir() const {
        cout << "Título: " << titulo << ", Preço: " << preco << endl;
    }
};

// Classe para gerenciar uma coleção de DVDs
class ColecaoDeDVDs {
private:
    DVD dvds[100];       // Array fixo que permite armazenar até 100 DVDs
    int numeroDVDs;      // Contador que mantém o número atual de DVDs na coleção

public:
    // Construtor que inicializa o contador de DVDs como zero
    ColecaoDeDVDs() : numeroDVDs(0) {}

    // Função para verificar se um DVD com o mesmo título já existe na coleção
    bool dvdExiste(const string &titulo) const {
        for (int i = 0; i < numeroDVDs; i++) {
            if (dvds[i].getTitulo() == titulo) {
                return true; // Retorna true se o título já existe
            }
        }
        return false; // Retorna false se o título é único
    }

    // Função para adicionar um novo DVD à coleção (evita duplicatas)
    void acrescentarDVD(const DVD &d) {
        if (dvdExiste(d.getTitulo())) { // Verifica duplicação
            cout << "Erro: Um DVD com o título \"" << d.getTitulo() << "\" já foi inserido." << endl;
            return; // Não adiciona o DVD se já existir
        }

        if (numeroDVDs < 100) {
            dvds[numeroDVDs++] = d;    // Adiciona o DVD e incrementa o contador
            cout << "DVD \"" << d.getTitulo() << "\" adicionado com sucesso!" << endl;
        } else {
            cout << "Coleção cheia. Não é possível adicionar mais DVDs." << endl;
        }
    }

    // Função para gerar um relatório e salvar em um arquivo de texto
    void relatorio() const {
        ofstream arquivo("relatorio_dvds.txt");    // Cria um arquivo para escrita
        if (!arquivo) {                            // Verifica se o arquivo foi aberto corretamente
            cout << "Erro ao abrir o arquivo para gravação." << endl;
            return;
        }

        // Escreve os dados de cada DVD no arquivo
        for (int i = 0; i < numeroDVDs; i++) {
            arquivo << "Título: " << dvds[i].getTitulo() << ", Preço: " << dvds[i].getPreco() << endl;
        }

        cout << "Relatório salvo no arquivo 'relatorio_dvds.txt'." << endl;
        arquivo.close();                           // Fecha o arquivo após a gravação
    }

    // Função para buscar um DVD pelo título na coleção
    void buscarDVD(const string &titulo) const {
        bool encontrado = false;                   // Variável para indicar se o DVD foi encontrado

        // Itera pela coleção de DVDs para encontrar o título
        for (int i = 0; i < numeroDVDs; i++) {
            if (dvds[i].getTitulo() == titulo) {   // Verifica se o título coincide
                cout << "DVD encontrado:" << endl;
                dvds[i].imprimir();                // Imprime os detalhes do DVD encontrado
                encontrado = true;
                break;                             // Sai do loop ao encontrar o DVD
            }
        }

        // Se o DVD não foi encontrado, informa ao usuário
        if (!encontrado) {
            cout << "DVD com o título \"" << titulo << "\" não encontrado." << endl;
        }
    }
};

// Função principal onde a interação com o usuário ocorre
int main() {
    meuCarimbo();
    mudaLinha();
    cout << "Bem-vindo ao gerenciador de coleção de DVDs!" << endl;
    mudaLinha();

    ColecaoDeDVDs colecao;    // Cria uma coleção de DVDs
    int opcao;                // Variável para armazenar a escolha do usuário

    // Loop principal do menu, que permite ao usuário escolher uma opção
    do {
        cout << "Selecione uma opção:" << endl;
        cout << "1. Adicionar DVD" << endl;
        cout << "2. Buscar DVD" << endl;
        cout << "3. Gerar relatório" << endl;
        cout << "4. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;         // Lê a opção escolhida
        cin.ignore();         // Limpa o buffer para evitar problemas com getline

        // Verifica qual opção foi selecionada pelo usuário
        if (opcao == 1) {
            string titulo;
            float preco;

            cout << "Digite o título do DVD: ";
            getline(cin, titulo);            // Lê o título do DVD, suportando espaços
            cout << "Digite o preço do DVD: ";
            cin >> preco;                    // Lê o preço do DVD
            cin.ignore();

            // Adiciona o DVD à coleção (se não for duplicado)
            colecao.acrescentarDVD(DVD(titulo, preco));

        } else if (opcao == 2) {
            string titulo;

            cout << "Digite o título do DVD que deseja buscar: ";
            getline(cin, titulo);            // Lê o título a ser buscado

            // Busca o DVD na coleção
            colecao.buscarDVD(titulo);

        } else if (opcao == 3) {
            // Gera e salva o relatório dos DVDs em um arquivo
            colecao.relatorio();

        } else if (opcao == 4) {
            cout << "Encerrando o programa." << endl;    // Finaliza o programa

        } else {
            cout << "Opção inválida. Tente novamente." << endl;  // Opção não reconhecida
        }

        // Chama a função para adicionar uma linha em branco após cada interação
        mudaLinha();

    } while (opcao != 4);   // Continua no loop até que o usuário escolha a opção de sair

    return 0;   // Retorna 0 para indicar que o programa terminou com sucesso
}