#ifndef graph.h
#define graph.h

// adjacency list representation of a graph

class Vertex{
    private:
    int element;
    Vertex* position;
    public:
    bool isAdjacentTo();
};

class Edge{
    private:
    int element;
    //give me origin vertex object
    //destination vertex object
    //and a reference to position in edge sequence
    Vertex* origin;
    Vertex* destination;
    Edge* position;
    public:
    Edge();
    Vertex endVertices();
    Vertex opposite();
};

//class for graph which has edge and vertex classes derived from it

class Graph{
    private:
    public:
};
















#endif graph.h