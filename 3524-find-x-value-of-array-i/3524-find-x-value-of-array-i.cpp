class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k), ndp(k);
        vector<long long> ans(k);

        for (int x : nums) {
            fill(ndp.begin(), ndp.end(), 0);

            int r = x % k;
            ndp[r]++;

            for (int j = 0; j < k; j++) {
                ndp[(j * r) % k] += dp[j];
            }

            dp = ndp;

            for (int j = 0; j < k; j++)
                ans[j] += dp[j];
        }

        return ans;
    }
};