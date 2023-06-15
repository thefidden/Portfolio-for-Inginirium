#ifndef MAIN_CPP_GRAPH_H
#define MAIN_CPP_GRAPH_H

#include "../../libraries.h"

using namespace std;

class Graph {
    protected:
        vector <Vertex> vertexArr;
        vector <vector <int>> distances;
        vector <vector <int>> adjacency;

    public:
        Graph ();

        Graph &setAdjacency (vector <vector <int>> adjacency);

        Graph &setDistances (vector <vector <int>> distances);

        vector <int> getMinDistances (int start, int end);

        vector <Vertex> searchInWidth (int start);
};


#endif //MAIN_CPP_GRAPH_H
