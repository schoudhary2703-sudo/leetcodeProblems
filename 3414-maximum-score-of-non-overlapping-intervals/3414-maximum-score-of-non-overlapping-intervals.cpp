class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        
        sort(a.begin(), a.end());
        
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            nxt[i] = lower_bound(
                a.begin(), a.end(), a[i][1] + 1,
                [](const auto& x, long long val) {
                    return x[0] < val;
                }
            ) - a.begin();
        }
        
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5, {0, {}})
        );
        
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                auto skip = dp[i + 1][k];
                
                auto take = dp[nxt[i]][k - 1];
                take.first += a[i][2];
                take.second.push_back(a[i][3]);
                sort(take.second.begin(), take.second.end());
                
                if (take.first > skip.first ||
                    (take.first == skip.first && take.second < skip.second)) {
                    dp[i][k] = take;
                } else {
                    dp[i][k] = skip;
                }
            }
        }
        
        return dp[0][4].second;
    }
};