#include <string.h>
#include "Node.h"

class Graph {
    private:
        int order;
        int** adjMatrix;
        Node* firstNode;
        Node* lastNode;

    public:
        Graph (int numVertices);
        int retornaVertices(){ return order; };
        void leituraArquivoGrafo(bool pondered, bool directed);
    
};

Graph::Graph (int numVertices) {
    this->order = numVertices;
    this->adjMatrix = new int*[this->order];
    for (int i = 0; i < this->order; i++) {
        adjMatrix[i] = new int[this->order];
        for (int j = 0; j < this->order; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}
