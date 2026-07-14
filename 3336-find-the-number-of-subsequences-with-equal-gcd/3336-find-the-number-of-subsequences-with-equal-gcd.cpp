

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        int MOD = 1e9 + 7;
        
        // dp[x][y] stores the count of pairs with GCD x and y respectively.
        // Dimension is (maxNum + 1) x (maxNum + 1)
        vector<vector<int>> dp(maxNum + 1, vector<int>(maxNum + 1, 0));
        dp[0][0] = 1; // Base case: both subsequences empty
        
        for (int num : nums) {
            vector<vector<int>> next_dp = dp;
            
            for (int x = 0; x <= maxNum; ++x) {
                for (int y = 0; y <= maxNum; ++y) {
                    if (dp[x][y] == 0) continue;
                    
                    // Choice 1: Put 'num' into the first subsequence
                    int newX = (x == 0) ? num : std::gcd(x, num);
                    next_dp[newX][y] = (next_dp[newX][y] + dp[x][y]) % MOD;
                    
                    // Choice 2: Put 'num' into the second subsequence
                    int newY = (y == 0) ? num : std::gcd(y, num);
                    next_dp[x][newY] = (next_dp[x][newY] + dp[x][y]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        // Sum up all valid pairs where x == y and both x, y > 0 (non-empty)
        long long ans = 0;
        for (int g = 1; g <= maxNum; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};