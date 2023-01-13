#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Função que abre o arquivo e retorna o próprio arquivo caso ele exista
ifstream leitura(string arquivo) {
    ifstream file(arquivo);
    if(!file.is_open()) {
        cout << "Failed to open file" << endl;
        return 0;
    }
    return file;
}