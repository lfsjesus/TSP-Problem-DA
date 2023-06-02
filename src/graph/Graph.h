#ifndef DA_RAILWAYMANAGEMENT_GRAPH_H
#define DA_RAILWAYMANAGEMENT_GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>
#include "VertexEdge.h"
#include "aux_data_structures/MutablePriorityQueue.h"

class Graph {
private:
    std::unordered_map<int, Vertex *> vertexSet;
public:
    /**
     * @brief Finds a vertex with a given station name
     * Time Complexity: O(|1|) being |V| the number of vertices in the graph
     * @param station Station name
     * @return Pointer to vertex or nullptr if not found
     */
    Vertex *findVertex(int id) const;

    /**
     * @brief Adds a vertex to the graph
     * Time Complexity: O(1)
     * @param id ID of the vertex to be added
     * @return true if vertex was added, false if it already exists
     */
    bool addVertex(int id);

    /**
     * @brief Adds an edge to the graph
     * Time Complexity: O(1)
     * @param origin Name of the origin station
     * @param dest  Name of the destination station
     * @param weight Capacity of segment
     * @param service Service of the edge to be added
     * @return true if edge was added, false if it already exists
     */
    bool addEdge(int origin, int dest, double weight);

    /**
     * @brief Adds a bidirectional edge to the graph
     * Time Complexity: O(1)
     * @param origin Name of the origin station
     * @param dest Name of the destination station
     * @param weight Capacity of segment
     * @param service Service of the edge to be added
     * @return true if edge was added, false if it already exists
     */
    bool
    addBidirectionalEdge(int origin, int dest, double weight);

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
     * @brief Resets the visited flag of all vertices
     * Time Complexity: O(|V|) being |V| the number of vertices in the graph
     */
    void resetVisited();

    friend class MutablePriorityQueue<Vertex>;

    /**
     * @brief Solves Travelling Salesman Problem related problems using backtracking
     * Time Complexity: O(n!) being n the number of vertices in the graph
     * @param path vector with the node to start and end the tour
     * @param bestPath initially empty vector that will eventually be filled with the best path
     * @param minCost initially infinity, will eventually be filled with the minimum cost
     * @param cumulatedCost initially 0 and will keep track of the cost so far
     */
    void tsp_backtracking(std::vector<int> &path, std::vector<int> &bestPath, double &minCost, double cumulatedCost); // passar path com vertice de inicio (0), marca-lo como visitado antes de chamar a função, cumulatedCost = 0

    /**
     * @brief Finds the minimum spanning tree of the graph using Prim's algorithm
     * Complexity: O(|E|log|V|) being |E| the number of edges and |V| the number of vertices in the graph
     * @param mst vector of edges that will be filled with the edges of the MST
     */
    void MSTPrim(std::vector<Edge*> &mst);

    /**
     * @brief Determines whether two nodes are connected or not
     * @param id1 first node id
     * @param id2 second node id
     * @return true if connected, false otherwise
     */
    bool connectedNodes(int id1, int id2) const;

    /**
     * @brief Computes the distance of a path passed as argument using the triangular inequality approach
     * Complexity: O(n) being n the number of vertices in the path
     * @param path vector of vertices that represent the path
     * @return distance of the path
     */
    double computePathDistance(std::vector<Vertex*> &path);

    /**
     * @brief Solves the Travelling Salesman Problem using the Triangular Inequality Heuristic, ensuring a 2-approximation
     * @return distance of the tour/path
     */
    double triangularInequalityHeuristic();

    /**
     * @brief Transverses a MST given as argument in pre-order
     * Complexity: O(|V|+|E|) being |V| the number of vertices and |E| the number of edges in the graph
     * @param mst the MST
     * @param v the vertex to start the transversal
     * @param path the path to be filled
     */
    void preOrderTraversal(const std::vector<Edge*>& mst, Vertex* v, std::vector<Vertex*> &path);
};

#endif //DA_RAILWAYMANAGEMENT_GRAPH_H
