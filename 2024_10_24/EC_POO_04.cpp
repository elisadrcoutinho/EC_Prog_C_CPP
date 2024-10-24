#include <iostream>

using namespace std;

void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];

    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << endl;
}

class Utilizador {
    private:
        string nome;          
        string palavraPasse;   

    public:
        // Método para definir nome e palavra-passe
        void set(string nome, string palavraPasse) {
            this-> nome = nome;
            this-> palavraPasse = palavraPasse;
        }

        // Método para obter os valores de nome e palavra-passe
        void get() {
            cout << "Nome: " << nome << ", palavra-passe: " << palavraPasse << endl;
        }
};

int main() {
    meuCarimbo();
    Utilizador novo_obj;
    
    string nome;
    string palavraPasse;

    cout << "Digite o seu nome: ";
    cin >> nome;

    cout << "Digite a sua palavra-passe: ";
    cin >> palavraPasse;

    // Definir os valores no objeto
    novo_obj.set(nome, palavraPasse);
    
    // Exibir os valores no ecrã
    novo_obj.get();

    return 0;
}
