#include <iostream>
#include <fstream>
#include <string>

void mostraTexto(std::string caminhoFicheiro, int opcao);
void exemploPonteiros();
void exemploAritmetica();
void exemploArrays();
void mudalinha(); // Função auxiliar para saltar uma linha.

int main() {
    int opcao;

    do {
        std::cout << "Menu de Opções - Conceitos sobre Ponteiros\n";
        std::cout << "1. Definição de Ponteiros\n";
        std::cout << "2. Aritmética de Ponteiros\n";
        std::cout << "3. Ponteiros e Arrays\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer de entrada para evitar problemas com a leitura.

        switch (opcao) {
            case 1:
                mostraTexto("ponteiros.txt", 1); // Mostra o texto da opção 1.
                exemploPonteiros(); // Mostra o exemplo da opção 1.
                break;
            case 2:
                mostraTexto("ponteiros.txt", 2); // Mostra o texto da opção 2.
                exemploAritmetica(); // Mostra o exemplo da opção 2.
                break;
            case 3:
                mostraTexto("ponteiros.txt", 3); // Mostra o texto da opção 3.
                exemploArrays(); // Mostra o exemplo da opção 3.
                break;
            case 4:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }

        mudalinha(); // Salta uma linha após a exibição de cada opção.

    } while (opcao != 4);

    return 0;
}

// Função para mostrar o texto do ficheiro, de acordo com a opção escolhida.
void mostraTexto(std::string caminhoFicheiro, int opcao) {
    std::ifstream ficheiro(caminhoFicheiro);
    if (!ficheiro.is_open()) {
        std::cerr << "Erro ao abrir o ficheiro!" << std::endl;
        return;
    }

    std::string linha;
    int contador = 0;
    bool mostrarTexto = false;

    // Lê o ficheiro linha por linha.
    while (std::getline(ficheiro, linha)) {
        // Identifica o início de cada seção no ficheiro.
        if (linha.find("# Opção " + std::to_string(opcao)) != std::string::npos) {
            mostrarTexto = true;
            continue;
        }

        // Se encontrou a seção correta, exibe o texto.
        if (mostrarTexto) {
            if (linha.find("# Opção") != std::string::npos) {
                break; // Sai quando encontra a próxima seção.
            }
            std::cout << linha << std::endl;
        }
    }

    ficheiro.close();
}

// Exemplo da opção 1 - Definição de Ponteiros
void exemploPonteiros() {
    int numero = 10;
    int *ponteiro = &numero;
    std::cout << "Exemplo de Ponteiro:\n";
    std::cout << "Valor de 'numero': " << numero << std::endl;
    std::cout << "Endereço de 'numero': " << ponteiro << std::endl;
    std::cout << "Valor apontado pelo ponteiro: " << *ponteiro << std::endl;
}

// Exemplo da opção 2 - Aritmética de Ponteiros
void exemploAritmetica() {
    int numeros[] = {10, 20, 30, 40, 50};
    int *ponteiro = numeros;
    std::cout << "Exemplo de Aritmética de Ponteiros:\n";
    std::cout << "Primeiro elemento: " << *ponteiro << std::endl;
    ponteiro++;
    std::cout << "Segundo elemento (após incremento): " << *ponteiro << std::endl;
}

// Exemplo da opção 3 - Ponteiros e Arrays
void exemploArrays() {
    int numeros[] = {10, 20, 30, 40, 50};
    int *ponteiro = numeros;
    std::cout << "Exemplo de Ponteiros e Arrays:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Elemento " << i << ": " << *(ponteiro + i) << std::endl;
    }
}

// Função auxiliar para saltar uma linha.
void mudalinha() {
    std::cout << "\n";
}
