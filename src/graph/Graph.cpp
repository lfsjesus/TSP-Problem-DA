#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Graph.h"

Vertex* Graph::findVertex(int id) const {
    auto it = vertexSet.find(id);
    if (it == vertexSet.end())
        return nullptr;
    return it->second;
}

bool Graph::addVertex(int id) {
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

bool Graph::addBidirectionalEdge(int origin, int dest, double weight) {
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

void Graph::tsp_backtracking(std::vector<int> &path, std::vector<int> &bestPath, double &minCost, double cumulatedCost) {
    int first = path.front();
    int last = path.back();

    if (path.size() == vertexSet.size()) {
        for (Edge* e : findVertex(last)->getEdges()) {
            Vertex* v = e->getDest();
            if (v->getId() == first) {
                double cycleCost = cumulatedCost + e->getWeight();
                if (cycleCost < minCost) {
                    minCost = cycleCost;
                    bestPath = path;
                }
                break;
            }
        }
        return;
    }

    for (Edge* e : findVertex(last)->getEdges()) {
        Vertex* v = e->getDest();
        if (!v->isVisited()) {
            double new_cost = cumulatedCost + e->getWeight();
            path.push_back(v->getId());
            v->setVisited(true);
            tsp_backtracking(path, bestPath, minCost, new_cost);
            path.pop_back();
            v->setVisited(false);
        }
    }
}
