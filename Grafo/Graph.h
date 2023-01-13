#include <string.h>

class Graph {
    private:
        int order;
        bool directed;
        bool weighted;
        int** adjMatrix;

    public:
        Graph (int numVertices);
        int retornaVertices(){ return order; };
        void leituraArquivoGrafo(bool pondered, bool directed);
    
};

Graph::Graph (int numVertices) {
    this->order = numVertices;
    this->directed = directed;
    this->weighted = weighted;
    this->adjMatrix = new int*[numVertices];
}
