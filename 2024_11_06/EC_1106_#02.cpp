#include <iostream>
#include <string>
using namespace std;

// Função para imprimir o carimbo de data e hora
void meuCarimbo() {
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    cout << "\n[UFCD_U15] - [Instâncias] - [Elisa Coutinho] - [ " << data_hora << " ]" << endl;
}

// Função para mudar de linha (limpar a tela ou adicionar uma nova linha)
void mudaLinha() {
    printf("\n");
}

// Classe base para Funcionário
class Funcionario {
protected:
    string numeroContribuinte;
    string nome;

public:
    // Construtor da classe Funcionario
    Funcionario(string numContribuinte, string nomeFuncionario)
        : numeroContribuinte(numContribuinte), nome(nomeFuncionario) {}

    // Métodos para acessar os dados do funcionário
    string getNumeroContribuinte() const { return numeroContribuinte; }
    string getNome() const { return nome; }

    // Método para exibir informações do funcionário
    virtual void mostrarInformacoes() const {
        cout << "Nome: " << nome << endl;
        cout << "Número de Contribuinte: " << numeroContribuinte << endl;
    }

    // Método virtual puro para calcular o salário (a ser implementado pelas subclasses)
    virtual float calcularSalario() const = 0;
};

// Classe derivada de Funcionario para Freelancer
class Freelancer : public Funcionario {
private:
    int horasTrabalhadas;
    float valorHora;

public:
    // Construtor da classe Freelancer
    Freelancer(string numContribuinte, string nomeFuncionario, int horas, float valor)
        : Funcionario(numContribuinte, nomeFuncionario), horasTrabalhadas(horas), valorHora(valor) {}

    // Método para exibir informações específicas do Freelancer
    void mostrarInformacoes() const {
        Funcionario::mostrarInformacoes();
        cout << "Horas Trabalhadas: " << horasTrabalhadas << endl;
        cout << "Valor por Hora: " << valorHora << endl;
    }

    // Implementação do cálculo do salário para Freelancer
    float calcularSalario() const {
        return horasTrabalhadas * valorHora;
    }
};

// Classe derivada de Funcionario para Interno
class Interno : public Funcionario {
private:
    float salarioBase;
    float bonusAnual;

public:
    // Construtor da classe Interno
    Interno(string numContribuinte, string nomeFuncionario, float salario, float bonus)
        : Funcionario(numContribuinte, nomeFuncionario), salarioBase(salario), bonusAnual(bonus) {}

    // Método para exibir informações específicas do Interno
    void mostrarInformacoes() const {
        Funcionario::mostrarInformacoes();
        cout << "Salário Base: " << salarioBase << endl;
        cout << "Bónus Anual: " << bonusAnual << endl;
    }

    // Implementação do cálculo do salário para Interno
    float calcularSalario() const {
        return salarioBase + bonusAnual;
    }
};

// Função principal
int main() {
    meuCarimbo();
    mudaLinha();

    // Criação de instâncias para teste
    Freelancer f1("12345", "João das Coves Freelancer", 160, 13.0); // 160 horas, 13.0 por hora
    Interno i1("54321", "Maria das Maças Interno", 2000.0, 500.0); // Salário base 2000.0, bônus de 500.0

    // Exibindo informações dos funcionários
    cout << "\nInformações do Freelancer:" << endl;
    f1.mostrarInformacoes();
    cout << "Salário: " << f1.calcularSalario() << endl;

    mudaLinha();

    cout << "\nInformações do Interno:" << endl;
    i1.mostrarInformacoes();
    cout << "Salário: " << i1.calcularSalario() << endl;

    return 0;
}