#ifndef DA_RAILWAYMANAGEMENT_VERTEXEDGE_H
#define DA_RAILWAYMANAGEMENT_VERTEXEDGE_H

#include <vector>
#include <string>

class Edge;

class Vertex {
private:
    int id;
    std::string label;
    double lat, lon = 0;
    std::vector<Edge *> edges;

    bool visited = false;
    bool processing = false;
    unsigned int inDegree;
    double distance = 0;
    Edge *path = nullptr;
    std::vector<Edge *> incoming;

public:
    explicit Vertex(const int &id);

    const int &getId() const;

    std::vector<Edge *> getEdges() const;

    bool isVisited() const;

    int getDistance() const;

    Edge *getPath() const;

    std::vector<Edge *> getIncoming() const;

    void setVisited(bool _visited);

    void setPath(Edge *_path);

    void setDistance(int _distance);

    void setLabel(std::string _label);

    void setLat(double _lat);

    void setLon(double _lon);

    const std::string &getLabel() const;

    double getLat() const;

    double getLon() const;

    /**
     * Adds a new outgoing edge to the vertex/station
     * Time Complexity: O(1)
     * @param dest Destination of the edge
     * @param weight Weight of the edge
     * @param service Service of the edge
     * @return Pointer to the new edge
     */
    Edge *addEdge(Vertex *dest, double weight);

    /**
     * Removes an edge with a given destination from the vertex/station
     * Time Complexity: O(i*o) being i the number of incoming edges and o the number of outgoing edges
     * @param des Station to remove the edge to
     * @return True if the edge was removed, false otherwise
     */
    bool removeEdge(const int &dest);

};

class Edge {
private:
    Vertex *origin;
    Vertex *dest;
    double weight;
    Edge *reverse = nullptr;

public:
    Edge(Vertex *origin, Vertex *dest, double weight);

    Vertex *getOrigin() const;

    Vertex *getDest() const;

    int getWeight() const;

    void setReverse(Edge *_reverse);
};

#endif //DA_RAILWAYMANAGEMENT_VERTEXEDGE_H
