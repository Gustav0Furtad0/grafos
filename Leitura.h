#include <string>
#include <fstream>
#include <iostream>

using namespace std;

ifstream leitura(string arquivo) {

    ifstream file(arquivo);
    if(!file.is_open()) {
        cout << "Failed to open file" << endl;
        return 0;
    }
    return file;
}