

class Solution {
public:
    int findMaxPathScore( vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n =online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        int max_cost = 0;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], cost = e[2];
            adj[u].push_back({v, cost});
            in_degree[v]++;
            max_cost = max(max_cost, cost);
        }
        
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--in_degree[edge.first] == 0) {
                    q.push(edge.first);
                }
            }
        }
        
       
        auto check = [&](int mid) {
            const long long INF = 1e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;
            
           
            for (int u : topo) {
                if (dist[u] == INF) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    
                    
                    if (cost < mid) continue;
                    
                    
                    if (v != n - 1 && !online[v]) continue;
                    
                    
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                    }
                }
            }
           
            return dist[n - 1] <= k;
        };
        
      
        int low = 0, high = max_cost;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;      
                low = mid + 1;  
            } else {
                high = mid - 1; 
                }
        }
        
        return ans;
    }
};