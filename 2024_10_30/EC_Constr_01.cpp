#include <iostream>
using namespace std;

class Carro {
    public:
    string nomeCarro;

    // Construtor cm+om um argumento
    Carro(string nomeCarro){
        this->nomeCarro = nomeCarro;
    }

    // Construtor de cópia
    Carro(Carro &outroCarro){
        nomeCarro = outroCarro.nomeCarro;
    }
};

int main(){
    Carro carroOriginal("Ruído tipo Mustang");
        cout << "Carro Original: " << carroOriginal.nomeCarro << endl;  

    Carro carroCopiado(carroOriginal);
        cout << "Primeiro carro copiado: " << carroCopiado.nomeCarro << endl;

    Carro outroCarroCopiado(carroOriginal);
        cout << "Segundo carro copiado: " << outroCarroCopiado.nomeCarro << endl;

    return 0;
}