#include <iostream>
 
int main() {
   
    int numeros[5] = {10, 20, 30, 40, 50};
   
    int *ptr = numeros;
   
    std::cout << numeros[0] << std::endl;
   
    std::cout << *ptr << std::endl;
   
    ptr++;
    std::cout << *ptr << std::endl;
 
    ptr--;
    std::cout << *ptr << std::endl;
 
    std::cout << *(ptr + 2) << std::endl;
 
    return 0;
}