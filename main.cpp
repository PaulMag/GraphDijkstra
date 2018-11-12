#include <iostream>
#include "graph.h"
#include "node.h"

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

    return 0;
}
