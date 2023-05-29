#ifndef DA_RAILWAYMANAGEMENT_GRAPH_H
#define DA_RAILWAYMANAGEMENT_GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include "VertexEdge.h"

class Graph {
private:
    std::unordered_map<int, Vertex *> vertexSet;
public:
    /**
     * @brief Finds a vertex with a given station name
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     * @param station Station name
     * @return Pointer to vertex or nullptr if not found
     */
    Vertex *findVertex(const int id) const;

    /**
     * @brief Finds a vertex with a given station name
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     * @param station Station name
     * @return Pointer to vertex or nullptr if not found
     */
    bool addVertex(const int id);

    /**
     * @brief Adds an edge to the graph
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     * @param origin Name of the origin station
     * @param dest  Name of the destination station
     * @param weight Capacity of segment
     * @param service Service of the edge to be added
     * @return true if edge was added, false if it already exists
     */
    bool addEdge(int origin, int dest, int weight);

    /**
     * @brief Adds a bidirectional edge to the graph
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     * @param origin Name of the origin station
     * @param dest Name of the destination station
     * @param weight Capacity of segment
     * @param service Service of the edge to be added
     * @return true if edge was added, false if it already exists
     */
    bool
    addBidirectionalEdge(int origin, int dest, int weight);

    /**
     * @brief Gets the number of vertices in the graph
     * Time Complexity: O(1)
     * @return Number of vertices
     */
    int getNumVertex() const;

    /**
     * @brief Gets the edges of the graph
     * Time Complexity: O(1)
     * @return Vector of edges
     */
    std::unordered_map<int, Vertex *> getVertexSet() const;

    /**
     * @brief Performs a Depth-First Search on the graph
     * Time Complexity: O(|V| + |E|) being |V| the number of vertices and |E| the number of edges in the graph
     * @param source Pointer to the source vertex
     */
    void DFS(Vertex *source);

    /**
     * @brief Resets the visited flag of all vertices
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     */
    void resetVisited();

};


#endif //DA_RAILWAYMANAGEMENT_GRAPH_H
