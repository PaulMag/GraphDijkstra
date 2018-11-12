#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
class Edge;

using namespace std;


class Node
{
public:
    Node(string n);

    string name;
    vector<Edge*> edges;

    void connect(Node* other, float w);
    void connectBi(Node* other, float w);
    void connectBi(Node* other, float w, float wReverse);
    void print();
    void traverse();
    void traverse(vector<Node*> path, float weightTotal);
};

#endif // NODE_H
