#include <cassert>
#include <queue> // for Breadth First Search
#include <stack> // for Depth First Search
#include "GraphClassDesign.h"
#include <iostream>

template <typename T>
int Graph<T>::addVertex(T value)
{
    int id = vertexCount(); // id is the index into vertices array
    vertices.push_back(Vertex(id, value));
    return id;
}

template <typename T>
std::pair<int, int> Graph<T>::addEdgeAndVertices(T start_value, T end_value, int cost)
{
    int start_id = addVertex(start_value);
    int end_id = addVertex(end_value);
    addEdge(start_id, end_id, cost);
    return std::pair<int, int> (start_id, end_id);
}

template <typename T>
void Graph<T>::addEdge(int start_id, int end_id, int cost)
{
    assert(start_id >= 0 && start_id < vertexCount());
    assert(end_id >= 0 && end_id < vertexCount());
    vertices[start_id].addEdge(end_id, cost);
    if (!directed)
        vertices[end_id].addEdge(start_id, cost);
}

template <typename T>
int Graph<T>::vertexCount() const
{
    return vertices.size();
}

template <typename T>
const T & Graph<T>::getVertexData(int vertex_id) const
{
    return vertices[vertex_id].getData();
}

template <typename T>
std::vector<int> Graph<T>::getAllVertexIDs() const
{
    std::vector<int> vertex_ids(vertexCount());
    for (size_t i = 0; i < vertex_ids.size(); ++i)
        vertex_ids[i] = i;
    return vertex_ids;
}

/*template <typename T>
std::pair<std::vector<int>, std::vector<int>> Graph<T>::BreadthFirstSearch(int start_id) const
{
    std::vector<int> parent(VertexCount(), -1);
    std::vector<int> vertex_ids(VertexCount(), -1);
    std::vector<bool> visited(VertexCount(), false);

    std::queue<int> q; // holds vertex ids still to be explored
    q.push(start_id);
    int index = 0;
    vertex_ids[index++] = start_id;
    parent[start_id] = -1;
    visited[start_id] = true;

    while (!q.empty())
    {
        int id = q.front();
        q.pop();
        // process vertex here if desired
        for (const OutEdge e : vertices[id].GetOutgoingEdges())
        {
            int neighbor_id = e.GetDestID();
            if (!visited[neighbor_id])
            {
                visited[neighbor_id] = true;
                vertex_ids[index++] = neighbor_id;
                parent[neighbor_id] = id;
                q.push(neighbor_id);
            }
        }
    }
    return std::make_pair(vertex_ids, parent);
}

template <typename T>
std::vector<int> Graph<T>::DepthFirstSearch(int start_id, bool recursive) const
{
    std::vector<bool> visited(VertexCount(), false);

    // Recursive implementation
    if (recursive)
    {
        std::vector<int> visit_order_recursive;
        DepthFirstSearchRecursive(start_id, visit_order_recursive, visited);
        return visit_order_recursive;
    }

    // Iterative implementation
    std::vector<int> visit_order(VertexCount(), -1);
    std::stack<int> s; // holds vertex ids still to be explored
    s.push(start_id);

    int index = 0;
    while (!s.empty())
    {
        int id = s.top();
        s.pop();
        if (!visited[id])
        {
            visited[id] = true;
            visit_order[index++] = id;
            for (const OutEdge e : vertices[id].GetOutgoingEdges())
            {
                int neighbor_id = e.GetDestID();
                s.push(neighbor_id);
            }
        }
    }
    return visit_order;
}
*/
template <typename T>
std::ostream & operator<<(std::ostream & out, Graph<T> & g)
{
    g.print(out);
    return out;
}

/*
template <typename T>
void Graph<T>::DepthFirstSearchRecursive(int vertex_id, std::vector<int> & visit_order, 
        std::vector<bool> & visited) const
{
    visited[vertex_id] = true;
    visit_order.push_back(vertex_id); // pre-order
    for (const OutEdge e : vertices[vertex_id].GetOutgoingEdges())
    {
        int neighbor_id = e.GetDestID();
        if (!visited[neighbor_id])
            DepthFirstSearchRecursive(neighbor_id, visit_order, visited);
    }
    // post-order visit would go here
}
*/

template <typename T>
void Graph<T>::print(std::ostream & out) const
{
    out << "V = ";
    for (const Vertex v : vertices)
        out << v.getData() << " ";
    out << "\n";
    out << "E = ";
    for (const Vertex v : vertices)
    {
        out << "[" << v.getData() << ":";
        for (const OutEdge e : v.getOutgoingEdges())
        {
            out << " " << vertices[e.getDestID()].getData();
        }
        out << "] ";
    }
    out << "\n";

}

template <typename T>
const int Graph<T>::OutEdge::getDestID() const
{
    return dest_id;
}

template <typename T>
const int Graph<T>::OutEdge::getCost() const
{
    return cost;
}

template <typename T>
void Graph<T>::Vertex::addEdge(int end_id, int cost)
{
    outgoing_edges.push_back(OutEdge(end_id, cost));
}

template <typename T>
const T & Graph<T>::Vertex::getData() const
{
    return data;
}

template <typename T>
const std::vector<typename Graph<T>::OutEdge> & Graph<T>::Vertex::getOutgoingEdges() const
{
    return outgoing_edges;
}

int main() {
    Graph<std::string> g;
    std::pair<int, int> ids_A_B = g.addEdgeAndVertices("A", "B");
    std::pair<int, int> ids_C_G = g.addEdgeAndVertices("C", "G");
    std::pair<int, int> ids_E_F = g.addEdgeAndVertices("E", "F");
    int id_D = g.addVertex("D");
    g.addEdge(ids_A_B.first, ids_C_G.first); // A<-->C
    g.addEdge(ids_A_B.first, ids_E_F.first); // A<-->E
    g.addEdge(ids_A_B.second, id_D); // B<-->D
    g.addEdge(ids_A_B.second, ids_E_F.second); // B<-->F

    std::cout << "Graph:\n";
    std::cout << g;
    
    return 0;
}
