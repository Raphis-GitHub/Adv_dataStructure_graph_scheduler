#include "graph.h"

// Perform topological sort on the graph
void Graph::topologicalSort() {
    std::list<Vertex*> sortedList;
    time = 0;
    // Reset all vertices to unvisited
    for (auto& pair : vertices) {
        pair.second->visited = false;
    }
    // Perform DFS on all unvisited vertices
    for (auto& pair : vertices) {
        if (!pair.second->visited) {
            DFSVisit(pair.second, sortedList);
        }
    }

    for (Vertex* v : sortedList) {
        std::cout << v->key << " ";
    }
    std::cout << std::endl;
}

void Graph::printAll() {
    for (const auto& pair : vertices) {
        std::cout << pair.first << " (" << pair.second->getNumNeighbors() << " neighbors) -> ";
        for (Edge* e : pair.second->edges) {
            std::cout << e->target->key << " ";
        }
        std::cout << std::endl;
    }
}

bool Graph::adde(const std::string &v1, const std::string &v2) {

        auto it1 = vertices.find(v1);
        auto it2 = vertices.find(v2);
        if (it1 == vertices.end() || it2 == vertices.end()) {
            return false;  // One or both vertices don't exist
        }

        // Check if edge already exists
        if (it1->second->hasEdgeTo(it2->second)) {
            return false;  // Edge already exists
        }

        it1->second->addEdge(it2->second);
        return true;

}

bool Graph::addv(const std::string &key) {
    if (vertices.find(key) != vertices.end()) {
        return false;  // Vertex already exists
    }
    vertices[key] = new Vertex(key);
    return true;
}

Graph::~Graph() {
    for (auto& pair : vertices) {
        for (Edge* e : pair.second->edges) {
            delete e;
        }
        delete pair.second;
    }
}

void Graph::DFSVisit(Vertex *v, std::list<Vertex *> &sortedList) {
    v->visited = true;
    time++;
    v->discoveryTime = time;

    for (Edge* e : v->edges) {
        if (!e->target->visited) {
            DFSVisit(e->target, sortedList);
        }
    }

    time++;
    v->finishTime = time;
    sortedList.push_front(v);
}

bool Vertex::hasEdgeTo(Vertex *target) const {
    for (Edge* e : edges) {
        if (e->target == target) {
            return true;
        }
    }
    return false;
}

void Vertex::addEdge(Vertex *target) {
    edges.push_back(new Edge(this, target));
}

int Vertex::getNumNeighbors() const {
    return edges.size();
}
