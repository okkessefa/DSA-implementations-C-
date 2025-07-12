#include <iostream>
#include <vector>


class GraphList {
private:
    int vertices;
    std::vector<std::vector<int>> adjList;

public:
    GraphList(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Undirected
    }

    void display() {
        std::cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int V = 8;
    GraphList graph(V);

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