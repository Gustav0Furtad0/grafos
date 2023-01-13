#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Leitura.h"
#include "Grafo/Graph.h"

int main(int argc, char** argv) {
    string fileName;
    fileName = argv[1];
    ifstream file = leitura(fileName);
    int v1, v2, weight;
    bool pondered = false;
    if (pondered) {
        while(file >> v1 >> v2 >> weight) {
            std::cout << "Vertice " << v1 << " aponta para " << v2 << " com peso " << weight << std::endl;
        }
    } else {
        while(file >> v1 >> v2) {
            std::cout << "Vertice " << v1 << " aponta para " << v2 << " com peso " << 0 << std::endl;
        }
    }
}
