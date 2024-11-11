#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

// Função para imprimir o carimbo com a data e hora
void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    cout << "\n[UFCD_U15] - [Objetos] - [Elisa Coutinho] - [ " << data_hora << " ]" << endl;
}

// Função para mudar de linha (limpar a tela ou adicionar uma nova linha)
void mudaLinha(void) {
    printf("\n");
}

int main() {
    meuCarimbo();  // Exibe o carimbo com data e hora
    mudaLinha();   // Adiciona uma linha em branco

    ifstream inputFile("/Users/elisadrummond/Documents/GitHub/EC_Prog_C-CPP/2024_11_06/InteirosPositivos.txt");
    ofstream outputFileA("/Users/elisadrummond/Documents/GitHub/EC_Prog_C-CPP/2024_11_06/1106_02A.txt");
    ofstream outputFileB("/Users/elisadrummond/Documents/GitHub/EC_Prog_C-CPP/2024_11_06/1106_02B.txt");

    if (!inputFile) {
        cerr << "Erro ao abrir o ficheiro de entrada." << endl;
        return 1;
    }

    if (!outputFileA || !outputFileB) {
        cerr << "Erro ao abrir os ficheiros de saída." << endl;
        return 1;
    }

    int number;
    int count = 0;
    double sum = 0;

    // Lê os números do ficheiro e calcula a soma e a quantidade
    while (inputFile >> number) {
        sum += number;
        count++;
    }

    if (count == 0) {
        cerr << "O ficheiro está vazio ou não contém números válidos." << endl;
        return 1;
    }

    // Calcula a média
    double average = sum / count;

    // Reabre o ficheiro de entrada para a segunda iteração
    inputFile.clear();
    inputFile.seekg(0);

    // Separa os números em dois ficheiros com base na média
    while (inputFile >> number) {
        if (number < average) {
            outputFileA << number << endl;
        } else {
            outputFileB << number << endl;
        }
    }

    // Fechar os ficheiros
    inputFile.close();
    outputFileA.close();
    outputFileB.close();

    cout << "Média calculada e números separados em 1106_02A.txt e 1106_02B.txt." << endl;

    return 0;
}