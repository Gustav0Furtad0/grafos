#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Grafo/Node.h"
#include "Grafo/Graph.h"

using namespace std;

ifstream leitura(string arquivo) {
    ifstream file(arquivo);
    if(!file.is_open()) {
        cout << "Error: " << arquivo << endl;
        throw std::runtime_error("Failed to open file");
    } else {
        cout << "Arquivo: " << arquivo << endl;
    }
    return file;
}


Graph* leituraGrafo(string fileName) {
    ifstream file = leitura(fileName);

    int numNodes;
    string line, descarte;

    // Le o numero de nos
    file.ignore(14, ' ');
    file >> numNodes;
    cout << "Number of nodes: " << numNodes << endl;

    // Aloca o grafo
    Graph* grafo= new Graph(numNodes);

    // Tendo em vista que não é necessário gerar o arquivo .dot, são puladas as posições
    file >> descarte;
    file.ignore(9, '\n');
    for (int i = 0; i < numNodes; i++) file.ignore(50, '\n');

    // Le os nos e seus pesos
    file >> descarte;
    file.ignore(100, '\n');
    for (int i = 0; i < numNodes; i++) {
        int weight;
        file >> weight;
        Node* node = grafo->insertNode(i+1);
        node->setWeight(weight);
        cout << "Node " << node->getId() << " weight: " << node->getWeight() << endl;
    }

    //Le matriz de adjacencia
    file >> descarte;
    file.ignore(100, '\n');
    for (int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            int adjacency;
            file >> adjacency;
            if (adjacency == 1) {
                grafo->insertEdge(i+1, j+1);
            }
        }
        //cout << endl;
    }

    return grafo;
}

int main(int argc, char** argv) {
    Graph* grafo = leituraGrafo(argv[1]);
    //Exibe matriz de adjacencia
    grafo->exibeMatrizAdjacencia();
    grafo->exibeListaAdjacencia();
}
