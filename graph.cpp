#include "graph.h"
#include "node.h"

Graph::Graph()
{
}

void Graph::insert(Node *node)
/* Insert an existing Node into the Graph. */
{
    nodes.push_back(node);
}

void Graph::insert(string nodeName)
/* Create a new Node with the given name and insert into the Graph. */
{
    if (find(nodeName)) {
        cout << "warning: A node with the name '" << nodeName
             << "' already exists in this graph." << endl;
    }
    insert(new Node(nodeName));
}

Node *Graph::find(string nodeName)
/* If it exists, return the Node with the given name.
 * If multiple Nodes exist with the same name only the first will be returned.
 */
{
    for (unsigned i=0; i<nodes.size(); i++) {
        if (nodeName.compare(nodes[i]->name) == 0) {
            return nodes[i];
        }
    }
    return nullptr;
}

void Graph::print()
/* Print the name of each Node in the graph with their respective direct connections. */
{
    for (unsigned i=0; i<nodes.size(); i++) {
        nodes[i]->print();
    }
}
