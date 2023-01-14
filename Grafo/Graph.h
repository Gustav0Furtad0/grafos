#include <string.h>
#include <iostream>
#include <fstream>
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
        Node* insertNode(int id);
        void setNodeWeight(int id, int weight);
        Node* getNode(int id);
        Node* removeNode(int id);
        void updateMatriz( );
        void insertEdge(int source_id, int target_id);
        void exibeMatrizAdjacencia();
        void exibeListaAdjacencia();
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

// // Destrutor do grafo
// Graph::~Graph() {
//     for (int i = 0; i < this->order; i++) {
//         delete[] this->adjMatrix[i];
//     }
//     delete[] this->adjMatrix;
// }

// Inserer um vertice no grafo
Node* Graph::insertNode(int id) {
    Node *node = new Node(id);
    if (this->firstNode == nullptr) {
        this->firstNode = node;
        this->lastNode = node;
    } else {
        this->lastNode->setNextNode(node);
        this->lastNode = node;
    }
    return node;
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

// Define peso do vertice
void Graph::setNodeWeight(int id, int weight) {
    Node *node = this->getNode(id);
    if (node != nullptr) {
        node->setWeight(weight);
    }
}

//Atualiza matriz de adjacencia
// void Graph::updateMatriz() {
//     Node *aux = this->firstNode;
//     while (aux != nullptr) {
//         Edge *edge = aux->getFirstEdge();
//         while (edge != nullptr) {
//             this->adjMatrix[aux->getId()][edge->getTargetId()] = aux;
//             edge = edge->getNextEdge();
//         }
//         aux = aux->getNextNode();
//     }
// }

// Insere aresta no grafo
void Graph::insertEdge(int sourceId, int targetId) {
    Node *source = this->getNode(sourceId);
    Node *target = this->getNode(targetId);
    if (source != nullptr && target != nullptr) {
        source->insertEdge(targetId, 0);
        target->insertEdge(sourceId, 0);
        this->adjMatrix[sourceId-1][targetId-1] = target;
        this->adjMatrix[targetId-1][sourceId-1] = source;
    } else
        cout << "Vertice nao encontrado" << endl;
}

void Graph::exibeMatrizAdjacencia() {
    cout << "Matriz de adjacencia:" << endl;
    for (int i = 0; i < this->order; i++) {
        for (int j = 0; j < this->order; j++) {
            //std::cout << "nada ";
            if (this->adjMatrix[i][j] != nullptr)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void Graph::exibeListaAdjacencia() {
    cout << "Lista de adjacencia:" << endl;
    for (int i = 0; i < this->order; i++) {
        cout << "Vertice " << i+1 << ": ";
        for (int j = 0; j < this->order; j++) {
            if (i == j)
                continue;
            if (this->adjMatrix[i][j] != nullptr)
                cout << j+1 << " ";
        }
        cout << endl;
    }
}
