#include <iostream>
#include "graph.h"
#include "node.h"
#include "edge.h"
#include "path.h"

using namespace std;

int main()
{
    Graph myGraph = Graph();
    myGraph.insert("A");
    myGraph.insert("B");
    myGraph.insert("C");
    myGraph.insert("D");
    myGraph.find("A")->connectBi(myGraph.find("B"), 0.5);
    myGraph.find("A")->connectBi(myGraph.find("C"), 0.75);
    myGraph.find("B")->connectBi(myGraph.find("C"), 0.4, 0.8);
    myGraph.find("B")->connectBi(myGraph.find("D"), 1.5);
    myGraph.find("A")->connect(myGraph.find("D"), 1);
    myGraph.find("D")->connect(myGraph.find("D"), 5);
    myGraph.print();
    myGraph.find("A")->traverse();
    myGraph.find("D")->traverse();

    cout << endl;
    Path path = myGraph.find("C")->dijkstra(myGraph.find("D"));
    vector<Edge*> edges = path.edges;
    for (unsigned i=0; i<edges.size(); i++) {
        cout << edges[i]->fromNode->name << edges[i]->toNode->name << " " << edges[i]->weight << endl;
    }
    cout << "Total weight: " << path.getWeight() << endl;

    return 0;
}
