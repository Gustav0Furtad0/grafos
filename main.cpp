#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Leitura.h"
#include "Grafo/Graph.h"

using namespace std;

Graph* leituraGrafo(int* weight, int** matrizAdjacency, int numNodes) {
    Graph* grafo = new Graph(numNodes);
    for (int i = 0; i < numNodes; i++) {
        grafo->insertNode(i+1);
    }
    
    return grafo;
}

int main(int argc, char** argv) {
    string fileName;
    fileName = argv[1];
    ifstream file = leitura(fileName);

    int numNodes;
    string line, descarte;
    int weight;

    // Le o numero de nos
    file.ignore(14, ' ');
    if (file >> numNodes) {
        cout << "Number of nodes: " << numNodes << endl;
    } else {
        cout << "Failed to read number of nodes" << endl;
    }

    // Tendo em vista que não é necessário gerar o arquivo .dot, são puladas as posições
    file >> descarte;
    file.ignore(9, '\n');
    for (int i = 0; i < numNodes; i++) file.ignore(50, '\n');

    //Le pesos
    cout << "Weight:" << endl;
    file >> descarte;
    file.ignore(100, '\n');
    int pesos[numNodes];
    for (int i = 0; i < numNodes; i++) {
        int weight;
        file >> weight;
        pesos[i] = weight;
        std::cout << "Id: " << i+1 << " peso " << weight  << std::endl;
    }

    //Le matriz de adjacencia
    int matrizAdjacency[numNodes][numNodes];
    cout << "Matriz de adjacencia:" << endl;
    file >> descarte;
    file.ignore(100, '\n');
    for (int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            file >> matrizAdjacency[i][j];
        }
    }

    //Cria grafo

    for (int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            //cout << matrizAdjacency[i][j] << " ";
        }
        //cout << endl;
    }


    file.close();
}
