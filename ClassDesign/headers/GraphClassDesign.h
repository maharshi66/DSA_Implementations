#include <utility> // std::pair
#include <ostream>
#include <vector>

/**
 * @brief      This class describes a graph.
 *
 * @tparam     T     { description }
 */
template <typename T>
class Graph
{
    public:
        Graph(bool directed = false) : directed(directed) {}

        int addVertex(T value);
        std::pair<int, int> addEdgeAndVertices(T start_value, T end_value, int cost = 0);
        void addEdge(int start_id, int end_id, int cost = 0);
        int vertexCount() const;
        const T & getVertexData(int vertex_id) const;
        std::vector<int> getAllVertexIDs() const;
        // BFS returns vector pair <vertex_id, parent of this vertex>
        
        std::pair<std::vector<int>, std::vector<int>> BreadthFirstSearch(int start_id) const;
        
        std::vector<int> DepthFirstSearch(int start_id, bool recursive = false) const;

        template <typename U>
        friend std::ostream & operator<<(std::ostream & out, Graph<U> & g);

    private:
        class Vertex; // forward declare;

        std::vector<Vertex> vertices;
        const bool directed;
        void DepthFirstSearchRecursive(int vertex_id, std::vector<int> & visit_order,
                std::vector<bool> & visited) const;
        
        /**
         * @brief      { function_description }
         *
         * @param      out   The out
         */
        void print(std::ostream & out) const;


        /**
         * @brief      This class describes an out edge.
         */
        class OutEdge
        {
            public:
                OutEdge(int end_id, int cost): dest_id(end_id), cost(cost) {}
                const int getDestID() const;
                const int getCost() const;

            private:
                int dest_id;
                int cost;
        };


        /**
         * @brief      This class describes a vertex.
         */
        class Vertex
        {
            public:
                /**
                 * @brief      Constructs a new instance.
                 *
                 * @param[in]  id     The identifier
                 * @param[in]  value  The value
                 */
                Vertex(int id, T value): id(id), data(value) {}
                
                void addEdge(int end_id, int cost);
                
                /**
                 * @brief      Gets the data.
                 *
                 * @return     The data.
                 */
                const T & getData() const;
                const std::vector<OutEdge> & getOutgoingEdges() const;

            private:
                int id; // unique identifier
                T data; 
                std::vector<OutEdge> outgoing_edges;
        };
};