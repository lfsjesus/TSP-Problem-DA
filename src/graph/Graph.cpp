#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "Graph.h"

Vertex *Graph::findVertex(const int id) const {
    return vertexSet.find(id)->second;
}

bool Graph::addVertex(const int id) {
    auto it = vertexSet.find(id);
    if (it != vertexSet.end())
        return false;
    auto *v1 = new Vertex(id);
    vertexSet.insert({id, v1});
    return true;
}

bool Graph::addEdge(int origin, int dest, int weight) {
    Vertex *v1 = findVertex(origin);
    Vertex *v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, weight);
    return true;
}

bool Graph::addBidirectionalEdge(int origin, int dest, int weight) {
    Vertex *v1 = findVertex(origin);
    Vertex *v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;

    Edge *e1 = v1->addEdge(v2, weight);
    Edge *e2 = v2->addEdge(v1, weight);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

int Graph::getNumVertex() const {
    return (int) vertexSet.size();
}

std::unordered_map<int, Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

void Graph::DFS(Vertex *source) {
    source->setVisited(true);
    for (auto e: source->getEdges()) {
        if (!e->getDest()->isVisited()) {
            DFS(e->getDest());
        }
    }
}

void Graph::resetVisited() {
    for (auto v: vertexSet) {
        v.second->setVisited(false);
    }
}
