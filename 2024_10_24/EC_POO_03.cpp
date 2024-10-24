#include <iostream>


using namespace std;

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
   
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    std::cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << std::endl;
   
}

class Utilizador{
    private:
    string nome = "Elisa";
    string palavraPasse = "abcElisa123";

    public:

    void set(string nome, string palavraPasse){
        this -> nome = nome;
        this -> palavraPasse = palavraPasse;
    }
    void get(){
        cout << nome << " " << palavraPasse << endl;
    }
};

int main(){

    meuCarimbo();
    
    Utilizador novo_obj;
    novo_obj.get();
    novo_obj.set("Elisa","abcElisa123");
    novo_obj.get();
    return 0;
}