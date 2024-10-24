#include <iostream>

using namespace std;

class outraClasse{
    public:
    int xInt;
    string sString;
};

int main(){
    outraClasse outro_objeto;
    cout << sizeof(outro_objeto) << endl;
    cout << sizeof(outro_objeto.xInt) << endl;
    cout << sizeof(outro_objeto.sString) << endl;

    return 0;
}
