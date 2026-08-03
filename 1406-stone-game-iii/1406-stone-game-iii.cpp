class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
         int n = stoneValue.size();
        int dp[4] = {0};

        for (int i = n - 1; i >= 0; i--) {
            dp[i % 4] = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                dp[i % 4] = max(dp[i % 4], sum - dp[(i + k + 1) % 4]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};