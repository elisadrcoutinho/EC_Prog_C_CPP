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

    ifstream inputFile("/Users/elisadrummond/Documents/GitHub/EC_Prog_C-CPP/2024_11_06/Inteiros.txt");
    ofstream outputFile("/Users/elisadrummond/Documents/GitHub/EC_Prog_C-CPP/2024_11_06/1106_01.txt");

    if (!inputFile) {
        cerr << "Erro ao abrir o ficheiro de entrada." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Erro ao abrir o ficheiro de saída." << endl;
        return 1;
    }

    int number;
    int sumPositive = 0;
    int sumNegative = 0;

    // Lê os números do ficheiro e calcula as somas
    while (inputFile >> number) {
        if (number > 0) {
            sumPositive += number;
        } else if (number < 0) {
            sumNegative += number;
        }
    }

    // Escreve os resultados no ficheiro de saída
    outputFile << "Soma dos números positivos: " << sumPositive << endl;
    outputFile << "Soma dos números negativos: " << sumNegative << endl;

    // Fechar os ficheiros
    inputFile.close();
    outputFile.close();

    cout << "Cálculos concluídos e resultados guardados em 1106_01.txt." << endl;

    return 0;
}