#ifndef EDGE_H
#define EDGE_H

class Node;


class Edge
{
public:
    Edge(Node* from, Node* to, float w);

    Node* fromNode;
    Node* toNode;
    float weight;
};

#endif // EDGE_H
