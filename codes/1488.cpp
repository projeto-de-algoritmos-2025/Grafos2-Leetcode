#include <vector>
#include <algorithm>
using namespace std;

// Estrutura de Union-Find com path compression e union by rank
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n): parent(n), rank(n, 0) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);           // path compression :contentReference[oaicite:3]{index=3}
        return parent[x];
    }
    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return false;
        // union by rank :contentReference[oaicite:4]{index=4}
        if(rank[pa] < rank[pb]) parent[pa] = pb;
        else if(rank[pb] < rank[pa]) parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
        return true;
    }
};

// Função que retorna o peso do MST, opcionalmente ignorando ou forçando uma aresta
int kruskal(int n, vector<array<int,4>>& edges, int blockEdge, int forceEdge) {
    UnionFind uf(n);
    int weight = 0, used = 0;
    // Se há aresta a ser forçada, adiciona antes de tudo
    if(forceEdge != -1) {
        auto &e = edges[forceEdge];
        uf.unite(e[0], e[1]);
        weight += e[2];
        used++;
    }
    // Kruskal padrão, ignorando a aresta blockEdge
    for(int i = 0; i < edges.size(); ++i) {
        if(i == blockEdge) continue;
        auto &e = edges[i];
        if(uf.unite(e[0], e[1])) {
            weight += e[2];
            used++;
            if(used == n-1) break;
        }
    }
    // Se não formou MST completo, retorna valor alto
    return (used == n-1 ? weight : 1e9);
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& inputEdges) {
        // Anexa índice original e prepara array fixo para ordenar
        vector<array<int,4>> edges;
        for(int i = 0; i < inputEdges.size(); ++i)
            edges.push_back({inputEdges[i][0], inputEdges[i][1], inputEdges[i][2], i});
        // Ordena por peso (e depois por índice para estabilidade) :contentReference[oaicite:5]{index=5}
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2] || (a[2] == b[2] && a[3] < b[3]);
        });

        // Peso do MST original sem restrições :contentReference[oaicite:6]{index=6}
        int originalMST = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo;
        // Para cada aresta, testa se é crítica ou pseudo-crítica :contentReference[oaicite:7]{index=7}
        for(int i = 0; i < edges.size(); ++i) {
            // 1) Se ignorar a aresta e o peso do MST fica maior, é crítica
            if(kruskal(n, edges, i, -1) > originalMST)
                critical.push_back(edges[i][3]);
            // 2) Se forçar a aresta e o MST ainda tem peso igual, é pseudo-crítica
            else if(kruskal(n, edges, -1, i) == originalMST)
                pseudo.push_back(edges[i][3]);
        }

        return {critical, pseudo};
    }
};
