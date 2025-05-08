#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) { // effort: armazena o menor esforço necessário para alcançar cada célula.
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // todos movimentos possiveis
        
        // armazenar o menor esforço necessário para chegar em cada célula
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;
        
        // minheap
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        
        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top();
            pq.pop();
            
            if (x == rows - 1 && y == cols - 1) {
                return currEffort;
            }
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int nextEffort = max(currEffort, abs(heights[nx][ny] - heights[x][y])); // calcular o esforço para chegar na célula
                    if (nextEffort < effort[nx][ny]) { // se o esforço atual for menor que o esforço armazenado, usa
                        effort[nx][ny] = nextEffort; 
                        pq.emplace(nextEffort, nx, ny); // adiciona a célula na fila de prioridade
                    }
                }
            }
        }
        
        return 0; 
    }
};
