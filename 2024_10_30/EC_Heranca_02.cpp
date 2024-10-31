#include <iostream>
using namespace std;    

class classeBase{
    public:
    int comissao = 10;
    void print(){
        cout << "Função principal." << endl;
    }
};

class classeDerivada : public classeBase {
    public:
    void print(){
        cout << "Função derivada." << endl;
    }
};

int main(){
    classeDerivada exemploUm;

    exemploUm.print();

    cout << exemploUm.comissao << endl;
    
    return 0;
}

