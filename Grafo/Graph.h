#include <string.h>
#include "Node.h"

class Graph {
    private:
        int order;
        Node*** adjMatrix;
        Node* firstNode;
        Node* lastNode;

    public:
        Graph (int numVertices);
        int retornaVertices(){ return order; };
        void leituraArquivoGrafo(bool pondered, bool directed);
        void insertNode(int id);
        void setNode(int id, Node* node);
        void setNodeWeight(int id, int weight);
        Node* getNode(int id);
        Node* removeNode(int id);
};

// Construtor do grafo com a ordem
Graph::Graph (int numVertices) {
    this->order = numVertices;
    this->adjMatrix = new Node**[numVertices];
    for (int i = 0; i < this->order; i++) {
        adjMatrix[i] = new Node*[this->order];
        for (int j = 0; j < this->order; j++) {
            adjMatrix[i][j] = nullptr;
        }
    }
}

// Destrutor do grafo
Graph::~Graph() {
    for (int i = 0; i < this->order; i++) {
        delete[] this->adjMatrix[i];
    }
    delete[] this->adjMatrix;
}

// Inserer um vertice no grafo
void Graph::insertNode(int id) {
    Node *node = new Node(id);
    if (this->firstNode == nullptr) {
        this->firstNode = node;
        this->lastNode = node;
    } else {
        this->lastNode->setNextNode(node);
        this->lastNode = node;
    }
}

// Retorna o vertice do grafo
Node* Graph::getNode(int id) {
    Node *aux = this->firstNode;
    while (aux != nullptr) {
        if (aux->getId() == id) {
            return aux;
        }
        aux = aux->getNextNode();
    }
    return nullptr;
}

// Remove veretice do grafo
Node* Graph::removeNode(int id) {
    Node *aux = this->firstNode;
    Node *prev = nullptr;
    while (aux != nullptr) {
        if (aux->getId() == id) {
            if (prev == nullptr) {
                this->firstNode = aux->getNextNode();
            } else {
                prev->setNextNode(aux->getNextNode());
            }
            return aux;
        }
        prev = aux;
        aux = aux->getNextNode();
    }
    return nullptr;
}

void Graph::setNodeWeight(int id, int weight) {
    Node *node = this->getNode(id);
    if (node != nullptr) {
        node->setWeight(weight);
    }
}
