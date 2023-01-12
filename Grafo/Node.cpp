class Node {
    private:
        int node_id;
        float weight;
        Node* next_node;
        Edge* first_edge;
        Edge* last_edge;

    public:
        // Constructor
        Node(int node_id);
        // Destructor
        ~Node();
        int getId() { return node_id; };
        float getWeight() { return weight; };
        Node* getNextNode() { return next_node; };
        
}