class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);

        for (auto &e : invocations)
            g[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);

        function<void(int)> dfs = [&](int u) {
            suspicious[u] = true;
            for (int v : g[u]) {
                if (!suspicious[v])
                    dfs(v);
            }
        };

        dfs(k);

        for (auto &e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};
