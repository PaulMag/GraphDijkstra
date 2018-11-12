#ifndef PATH_H
#define PATH_H

#include <vector>
class Edge;

using namespace std;


class Path
{
public:
    Path();
//    Path(Path& path);
    Path(vector<Edge*> edgesSource);

    vector<Edge*> edges;

    void push_back(Edge* edge);
    Edge* back();
    float getWeight() const;
};

#endif // PATH_H
