#include "node.h"
#include "edge.h"
#include <algorithm>


Node::Node(string n)
{
    name = n;
}

void Node::connect(Node *other, float w)
/* Make a one-way connection between this Node and other Node. */
{
    edges.push_back(new Edge(this, other, w));
}

void Node::connectBi(Node *other, float w)
/* Make a two-way connection between Nodes this and other with the same weight. */
{
    edges.push_back(new Edge(this, other, w));
    other->edges.push_back(new Edge(other, this, w));
}

void Node::connectBi(Node *other, float w, float wReverse)
/* Make a two-way connection between Nodes this and other with different weights. */
{
    edges.push_back(new Edge(this, other, w));
    other->edges.push_back(new Edge(other, this, wReverse));
}

void Node::print()
/* Print all direct connections from this Node and their respective weights. */
{
    cout << name << ":   ";
    for (unsigned i=0; i<edges.size(); i++)
    {
        cout << edges[i]->toNode->name << " (" << edges[i]->weight << ")";
        if (i+1 < edges.size()) {
            cout << ",  ";
        }
    }
    cout << endl;
}

void Node::traverse()
/* Depth-first recursive traversal that shows all possible paths to other Nodes from this
 * Node and the total distance of each of these paths.
 */
{
    vector<Node*> pathInit(1, this);
    cout << name << endl;
    for (unsigned i=0; i<edges.size(); i++)
    {
        edges[i]->toNode->traverse(pathInit, edges[i]->weight);
    }
}

void Node::traverse(vector<Node*> path, float weightTotal)
/* Help method for traverse() method. Cumulate total path and total weight up to this point
 * and print it. Should be private. */
{
    if (std::find(path.begin(), path.end(), this) != path.end()) {
        return;  // Stop here if this is already in the path to avoid looping back.
    }
    path.push_back(this);
    for (unsigned i=0; i<path.size(); i++)
    {
        cout << path[i]->name;
        if (i+1 < path.size()) {
            cout << " -> ";
        }
    }
    cout << " (" << weightTotal << ")" << endl;
    for (unsigned i=0; i<edges.size(); i++)
    {
        edges[i]->toNode->traverse(path, weightTotal+edges[i]->weight);
    }
}
