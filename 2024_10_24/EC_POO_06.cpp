#include <iostream>

using namespace std;

void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];

    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << endl;
}

class Pessoa {
    private:
        string nome;          
        int idade; 
        float classificacao;

    public:
        // Método para definir nome, idade e classificação
        void set(string nome, int idade, float classificacao) {
            this-> nome = nome;
            this-> idade = idade;
            this-> classificacao = classificacao;
        }

        // Método para obter os valores de nome, idade e classificação
        void get() {
            cout << "Nome: " << nome << ", idade: " << idade << ", classsificação: " << classificacao << endl;
        }

        // Método para obter condição de acesso
        void podeFrequentar(){
            if (classificacao >12 && idade >=20){
                cout << nome << ", pode inscrever-se." << endl; 
            } else {
                cout << nome << ", não possui os requisitos para inscrever-se." << endl;
            }
    }
};

int main() {
    meuCarimbo();

    // Cria nova instancia

    Pessoa novaPessoa;

    string nome;
    int idade;
    float classificacao;

    // Intereação com utilizador
    cout << "Digite o seu nome: ";
    cin >> nome;

    cout << "Digite a sua idade: ";
    cin >> idade;

    cout << "Digite a sua classificação: ";
    cin >> classificacao;


    // Verifica os atributos
    novaPessoa.set(nome, idade, classificacao);

    // Introduz o método de acesso
    novaPessoa.podeFrequentar();

    return 0;

}
