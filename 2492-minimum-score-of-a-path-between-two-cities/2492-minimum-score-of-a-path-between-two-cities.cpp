class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }
        
        int min_score = 1e9;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (const auto& edge : adj[node]) {
                min_score = min(min_score, edge.second);
                if (!visited[edge.first]) {
                    visited[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
        
        return min_score;
    }
};