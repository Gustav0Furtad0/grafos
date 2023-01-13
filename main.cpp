#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Leitura.h"

using namespace std;

int main(int argc, char** argv) {
    string fileName;
    fileName = argv[1];
    ifstream file = leitura(fileName);
    int v1, v2, weight;
    bool pondered = false;
    if (pondered) {
        while(file >> v1 >> v2 >> weight) {
        cout << "Vertice " << v1 << " aponta para " << v2 << " com peso " << weight << endl;
        }
    } else {
        while(file >> v1 >> v2) {
            cout << "Vertice " << v1 << " aponta para " << v2 << " com peso " << 0 << endl;
        }
    }
}
