#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
class Edge;
#include <queue>

using namespace std;


class Node
{
public:
    Node(string n);

    string name;
    vector<Edge*> edges;
    bool visited = false;
    typedef vector<Edge*> Path;

    void connect(Node* other, float w);
    void connectBi(Node* other, float w);
    void connectBi(Node* other, float w, float wReverse);
    void print();
    void traverse();
    void traverse(vector<Node*> path, float weightTotal);
    Path dijkstra(Node* target);
    void dijkstra(priority_queue<Path>& pathQueue, Path current);
};

#endif // NODE_H
