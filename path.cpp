#include "path.h"
#include "edge.h"


Path::Path()
{
}

//Path::Path(Path &path)
///* Copy constructor */
//{
////    edges.reserve(path.edges.size());
//    for (unsigned i=0; i<path.edges.size(); i++) {
//        edges.push_back(path.edges[i]);
//    }
//}

Path::Path(vector<Edge *> edgesSource)
{
    for (unsigned i=0; i<edgesSource.size(); i++) {
        edges.push_back(edgesSource[i]);
    }
}

void Path::push_back(Edge *edge)
{
    edges.push_back(edge);
}

Edge *Path::back()
{
    return edges.back();
}

float Path::getWeight()
{
    float weight = 0;
    for (unsigned i=0; i<edges.size(); i++){
        weight += edges[i]->weight;
    }
    return weight;
}
