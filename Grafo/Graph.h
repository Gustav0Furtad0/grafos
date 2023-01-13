#include <string.h>

class Graph {
    private:
        int numVertices;
        bool directed;
        bool weighted;
        int** adjMatrix;

    public:
        Graph (int numVertices, bool directed, bool weighted);
        int retornaVertices(){ return numVertices; };
        void leituraArquivoGrafo(bool pondered, bool directed);
    
};

Graph::Graph (int numVertices, bool directed, bool weighted) {
    this->numVertices = numVertices;
    this->directed = directed;
    this->weighted = weighted;
    this->adjMatrix = new int*[numVertices];
}
