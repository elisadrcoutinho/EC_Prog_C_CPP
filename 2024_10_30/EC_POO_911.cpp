#include <iostream>
using namespace std;

// Classe Retangulo
class Retangulo {
    private:
        int altura;
        int largura;

    public:
        // Construtor para incializar com altura e largura do retângulo
        Retangulo(int alt, int larg);

        // Funções para desenhar o retângul
        void desenha();          // Desenha o retângulo com o caractere padrão '*'
        void desenha(char c);    // Desenha o retângulo com um caractere específico
};

// Construtor: inicializa a altura e a largura
Retangulo::Retangulo(int alt, int larg) {
    altura = alt;
    largura = larg;
}

// Função para desenhar o retângulo com '*'
void Retangulo::desenha() {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            cout << '*';
        }
        cout << "\n";
    }
}

// Função para desenhar o retângulo com 'c'
void Retangulo::desenha(char c) {
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            cout << c;
        }
        cout << "\n";
    }
}

// Função principal
int main() {
    // Criação de um objeto da classe Retangulo com altura 8 e largura 12
    Retangulo ret(8, 12);

    // Desenha o retângulo com o caractere padrão '*'
    ret.desenha();
    cout << "\n";

    // Desenha o retângulo com o caractere 'A'
    ret.desenha('A');

    return 0;
}
