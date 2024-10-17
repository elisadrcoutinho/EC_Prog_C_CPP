#include <iostream>
#include <ctime>

// Declaração das funções
void meuCarimbo(void);
void mudaLinha(void);

int main() {
    
    meuCarimbo();
    
    /** 
    * O operador '&' é unário e significa 'endereço de...'. Por exemplo, &codPostal quer dizer 'endereço da variável codPostal'.
    * O código abaixo ilustra um exemplo para uma variável do tipo inteiro.
    * Nota: se executarmos o código várias vezes verificamos que o endereço de memória é diferente em cada execução.
    * [Exemplo 01] 
    */
        std::cout << "--- Exemplo 01 --->" << std::endl;
        int numero = 10;
        std::cout << numero  << std::endl;
        std::cout << &numero << std::endl;
        
        mudaLinha();

/**
 * Vamos considerar que dispomos de um tipo de dados para representar endereços.
 * Chamamos a este tipo "tipo apontador" (Pointer Type).
 * Agora, de alguma forma o compilador tem que saber a que tipo de variável corresponde o endereço.
 * Recordar que um 'char' ocupa 1 byte, um 'int' e um 'float' ocupam 4 byte's, mas com formato diferente
 * e por aí fora. Ou seja, precisamos de saber para que é que aponta o nosso tipo apontador...
 * Para se dclarar um ponteiro usamos a sintaxe 'tipo*'. Isto lê-se "apontador de tipo" ou, mais facilmente, 
 * "tipo pointer", e representa um tipo de dados que corresponde a endereços do tipo "tipo"...
 * Por exemplo, 'char*' é um 'char pointer'. Variáveis do tipo 'char*' contêm endereços do tipo 'char'...  
 */

    /** 
    * [Exemplo 02]
    */ 
        std::cout << "--- Exemplo 02 --->" << std::endl;
        int var_ex02 = 20;
        int *ptr_ex02;
        ptr_ex02 = &var_ex02; 
        std::cout << "Mostra o valor atual da variável 'var_ex02': " << var_ex02 << std::endl;
        std::cout << "Mostra o endereço de memória onde se encontra a variável 'var_ex02': " << ptr_ex02 << std::endl;
        std::cout << "Mostra o valor da variável 'var_ex02', apontada pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;

    mudaLinha();

    /** 
    * [Exemplo 03]
    */ 
        std::cout << "--- Exemplo 03 --->" << std::endl;
        char letra_ex03 = '-';		
        char *ptr_ex03;
        ptr_ex03 = &letra_ex03;
        /**  
         * Na declaração abaixo, vamos alterar o valor inicial da variável 'letra_ex03' sem efetuarmos qualquer operação de atribuição.
         * Para isso, recorremos ao seu endereço de memória através do ponteiro 'ptr_ex03'.
         * Estamos a dizer "atribui o caráter '+' à posição de memória apontada por...".
         */
        *ptr_ex03 = '+'; 
        std::cout << "Resultado do acesso ao endereço de memória da variável 'letra_ex03': " << letra_ex03 << std::endl;
        
    mudaLinha();
    
/**
 * Existem alguns erros muito comuns quando se usam ponteiros:
 * 1) não devemos (não podemos!) atribuir um endereço a uma variável que não seja do tipo ponteiro:
 *      int k;  &k = 100;
 * 2) um ponteiro tem que ser sempre inicializado antes de ser usado:
 *      int k;  int *p;    *p = 10; 
 *      Neste último caso, como 'p' não tem um valor conhecido, não se sabe onde será depositado o valor 10.  
 */
    /** 
    * [Exemplo 04]
    */ 
        std::cout << "--- Exemplo 04 --->" << std::endl;
        //int k, *p;
		//*p = 10;
        //std::cout << *p  << std::endl; // Atenção ao erro de 'execução' (runtime).

    mudaLinha();

    /** 
    * [Exemplo 05]
    */ 
        std::cout << "--- Exemplo 05 --->" << std::endl;
        int numeros[5] = {10, 20, 30, 40, 50}; // Definir e inicializar um 'array' de números inteiros.
        for (int i = 0; i < 5; ++i) {
            std::cout << numeros[i] << " ";
        }
        std::cout << std::endl;
        int *ptr = numeros; // Definir e inicializar um 'ponteiro' para o 'array' de números inteiros.
        std::cout << "Endereço de memória onde está o primeiro elemento do 'array': " << ptr << std::endl;
        std::cout << "Valor do primeiro elemento do 'array', usando o índice (index): " << numeros[0] << std::endl;
        std::cout << "Valor do primeiro elemento do 'array', usando o endereço (pointer): " << *ptr << std::endl;
        // Nota: se executarmos o código várias vezes verificamos que os endereços de memória são diferentes em cada execução.
      
    mudaLinha();
    
    /**
     * Aritmética com ponteiros.
     * O valor de um ponteiro pode ser incrementado (prefix) ou decrementado (postfix).
     * Incrementar um ponteiro significa avançar, para a direita, uma posição de memória (neste caso, dentro do 'array').
     * Decrementar um ponteiro significa retroceder, para a esquerda, uma posição de memória (neste caso, dentro do 'array').
     * A aritmética de ponteiros não é permitida se o tipo de dados para o qual o ponteiro aponta não estiver completo. 
     * De notar que o operador 'void' é sempre um tipo incompleto.  
     */        
        ptr++; // Incrementar o ponteiro para avançar uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço:  " << *ptr << std::endl;
        ptr++; // Incrementar mais uma vez o ponteiro para avançar mais uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;
        // Nota: verificar que os endereços de memória são sequenciais, de 4 em 4 byte's.
        
        ptr--; // Descrementar o ponteiro para recuar uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;

    /** A aritmética de ponteiros pode ser aplicada em instruções mais ou menos complexas. */
        std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *(ptr + 2) << std::endl;

    /** Valores inteiros podem ser adicionados ou subtraídos aos ponteiros e actuam como incremento ou decremento,
     *  respectivamente, mas por um 'número' específico, ao contrário do que sucede nas operações aritméticas.
     *  Também nestes casos o ponteiro deve 'apontar' para um tipo de dados completo.
     */
        ptr += 3; // Incrementar o ponteiro para avançar três posições (e não 3 vezes, como nas somas tradicionais).
        std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *ptr << std::endl;

    /** Para finalizar esta introdução aos ponteiros, devemos sempre ter em atenção as operações de incremento e/ou
     *  decremento que efetuamos. 
     *  Um uso incorreto dos valores dos ponteiros podem remeter-nos para comportamentos inesperados dos nossos programas (no que respeita ao endreçamento de memória).
     */ 

    mudaLinha();

    return 0;
}

// Definição das funções
void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
   
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    std::cout << "\n[UFCD_U15] - [Ponteiros] - [Elisa Coutinho] - [ " << data_hora << " ]" << std::endl;
    mudaLinha();
}

void mudaLinha(void)
{
    std::cout << std::endl;
}
