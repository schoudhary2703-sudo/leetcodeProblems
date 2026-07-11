class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> vis(n);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            vector<int> comp;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }

            long long k = comp.size();
            long long degSum = 0;
            for (int u : comp) degSum += g[u].size();
            if (degSum == k * (k - 1)) ans++;
        }

        return ans;
    }
};