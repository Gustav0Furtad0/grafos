#include <string>
#include <fstream>
#include <iostream>

// Função que abre o arquivo e retorna o próprio arquivo caso ele exista
ifstream leitura(string arquivo) {
    ifstream file(arquivo);
    if(!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return 0;
    }
    return file;
}