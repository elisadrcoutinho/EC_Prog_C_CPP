#include <iostream>
#include <dirent.h>  // Para manipulação de diretórios
#include <string>    // Para usar std::string
#include <cstring>   // Para usar strcmp

int main(int argc, char* argv[]) {
    // Verifica se a extensão do arquivo foi fornecida como argumento
    if (argc != 2) {
        std::cout << "Uso: " << argv[0] << " <extensao_do_arquivo>" << std::endl;
        return 1;  // Retorna 1 para indicar erro
    }

    // Armazena a extensão fornecida pelo usuário
    std::string extension = argv[1];
    if (extension[0] != '.') {
        extension = "." + extension;  // Adiciona um ponto se não estiver presente
    }

    // Abre o diretório atual
    DIR* dir = opendir(".");
    if (!dir) {
        std::cerr << "Não foi possível abrir o diretório atual." << std::endl;
        return 1;  // Retorna 1 para indicar erro
    }

    struct dirent* entry;  // Estrutura para armazenar informações do arquivo
    bool found = false;    // Variável para verificar se algum arquivo foi encontrado

    // Itera sobre os arquivos no diretório atual
    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;  // Nome do arquivo

        // Verifica se o arquivo tem a extensão desejada
        if (filename.size() >= extension.size() && 
            filename.substr(filename.size() - extension.size()) == extension) {
            std::cout << "Arquivo encontrado: " << filename << std::endl;  // Imprime o nome do arquivo
            found = true;  // Marca que um arquivo foi encontrado
        }
    }

    closedir(dir);  // Fecha o diretório

    // Informa se nenhum arquivo foi encontrado
    if (!found) {
        std::cout << "Nenhum arquivo com a extensão " << extension << " encontrado no diretório atual." << std::endl;
    }

    return 0;  // Retorna 0 indicando que o programa terminou com sucesso
}
