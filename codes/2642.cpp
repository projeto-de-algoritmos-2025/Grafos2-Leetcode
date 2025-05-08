#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> adj; // grafo: par ordenado de [(para, custo)]
    int n; 

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            adj[from].emplace_back(to, cost);
        }
    }

    void addEdge(vector<int> edge) {
        int from = edge[0], to = edge[1], cost = edge[2];
        adj[from].emplace_back(to, cost);
    }

    // Retorna o menor caminho usando Dijkstra
    int shortestPath(int node1, int node2) {
        // Vetor de distâncias, inicializado com infinito
        vector<int> dist(n, numeric_limits<int>::max());
        dist[node1] = 0;

        // PQ: (distância acumulada, nó atual)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, node1);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (u == node2) return d; // ja eh o melhor caminho

            if (d > dist[u]) continue; // pula se ja eh o melhor caminho

            for (auto& [v, cost] : adj[u]) {
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return -1; // erro (sem caminho)
    }
};
