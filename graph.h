#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
class Node;

using namespace std;


class Graph
{
public:
    Graph();

    vector<Node*> nodes;

    void insert(Node* node);
    void insert(string nodeName);
    Node* find(string nodeName);
    void print();
};

#endif // GRAPH_H
