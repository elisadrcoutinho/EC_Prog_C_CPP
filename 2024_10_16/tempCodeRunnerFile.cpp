#include <iostream>  // Incluir a biblioteca de entrada/saída
#include <ctime>     // Incluir a biblioteca de tempo para funções de tempo

// Função para imprimir uma nova linha
void mudaLinha() {
    std::cout << std::endl;  // Imprimir uma nova linha
}

// Função para imprimir um carimbo de data/hora
void meuCarimbo(void) {
    time_t tempo_atual = time(NULL);  // Obter o tempo atual
    struct tm *tempo_local = localtime(&tempo_atual);  // Converter para o horário local
    char data_hora[64];  // Array para armazenar a data e hora formatadas
    
    // Formatar a data e a hora
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    
    // Imprimir o carimbo de data/hora
    std::cout << "\n[António Fonseca] - [ " << data_hora << " ]";
    mudaLinha();  // Chamar a função para imprimir uma nova linha
}

int main() {  // Função principal, ponto de entrada do programa
    int numeros[5] = {10, 20, 30, 40, 50};  // Declarar e inicializar um array de 5 inteiros
    
    int *ptr = numeros;  // Declarar um ponteiro e inicializá-lo para apontar para o primeiro elemento do array
    
    std::cout << numeros[0] << std::endl;  // Imprimir o primeiro elemento do array usando a notação de array
    
    std::cout << *ptr << std::endl;  // Imprimir o valor apontado por ptr (primeiro elemento do array)
    
    ptr++;  // Incrementar o ponteiro para apontar para o próximo elemento
    std::cout << *ptr << std::endl;  // Imprimir o valor do segundo elemento
 
    ptr--;  // Decrementar o ponteiro para apontar de volta para o primeiro elemento
    std::cout << *ptr << std::endl;  // Imprimir o valor do primeiro elemento novamente
 
    std::cout << *(ptr + 2) << std::endl;  // Imprimir o valor do terceiro elemento usando aritmética de ponteiros
 
    meuCarimbo();  // Chamar a função para imprimir o carimbo de data/hora
 
    return 0;  // Encerrar o programa e retornar 0 para indicar execução bem-sucedida
}
