#ifndef MIVNEBETHW5_GRAPH_H
#define MIVNEBETHW5_GRAPH_H

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <stack>
//early deleration as requested
class Vertex;
//defines an edge with a source and target(destinantion)
class Edge {
public:
    Vertex* source;
    Vertex* target;

    Edge(Vertex* src, Vertex* tgt) : source(src), target(tgt) {}
};
//defines the vertex
class Vertex {
public:
    std::string key;
    std::list<Edge*> edges;
    bool visited;
    int discoveryTime;
    int finishTime;

    // Get the number of neighbors (outgoing edges) for this vertex
    int getNumNeighbors() const;

    // Add an outgoing edge to this vertex
    void addEdge(Vertex* target);

    // Check if this vertex has an edge to the given target
    bool hasEdgeTo(Vertex* target) const;

    //constructor
    Vertex(const std::string& k) : key(k), visited(false), discoveryTime(0), finishTime(0) {}
};
//defines a graph with the abiltiy to use DFS algorithm to visit nodes
class Graph {
private:
    std::unordered_map<std::string, Vertex*> vertices;
    int time;

    void DFSVisit(Vertex* v, std::list<Vertex*>& sortedList);

public:
    //constructs default graph
    Graph() : time(0) {}
    //destructs graph
    ~Graph();
    //adds a vertex
    bool addv(const std::string& key);
    //adds an edge
    bool adde(const std::string& v1, const std::string& v2);
    //prints all connections
    void printAll();
    //sorts it topologically
    void topologicalSort();
};

#endif //MIVNEBETHW5_GRAPH_H
