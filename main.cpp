#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Leitura.h"

using namespace std;

int main() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream file = leitura(fileName);
    int v1, v2, weight;
    while(file >> v1 >> v2 >> weight) {
        cout << "Vertice " << v1 << " aponta para " << v2 << " com peso " << weight << endl;
    }   
}
