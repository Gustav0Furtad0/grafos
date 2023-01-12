class Graph {
    private:
        int numVertices;

    public:
        Graph (int numVertices);
        
        int retornaVertices(){ return numVertices; };
    
};

Graph::Graph (int numVertices) {
    this->numVertices = numVertices;
}
