#include <iostream>
#include <string>

using namespace std;

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
   
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    std::cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << std::endl;
   
}

class Estudante{
public:
    string nome;
    int idade;

 void mostrar(){
    cout << nome << " " << idade << endl;
 }
};

int main(){

    meuCarimbo();

    Estudante novoEstudante;
    cin >> novoEstudante.nome >> novoEstudante.idade;
    novoEstudante.mostrar();

    return 0;
}