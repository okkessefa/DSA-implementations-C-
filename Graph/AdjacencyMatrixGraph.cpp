#include <iostream>
#include <vector>


class GraphMatrix {
private:
    int vertices;
    std::vector<std::vector<int>> matrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        matrix.resize(v, std::vector<int>(v, 0));
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // Undirected
    }

    void display() {
        std::cout << "\nAdjacency Matrix Representation:\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int V = 8;
    GraphMatrix graph(V);

    int edges[][2] = {
        {0,1}, {0,2}, {0,3},
        {1,4}, {1,5},
        {2,6}, {3,7}, {4,7}, {5,7}, {6,7}
    };

    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edgeCount; ++i) {
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    graph.display();

    return 0;
}