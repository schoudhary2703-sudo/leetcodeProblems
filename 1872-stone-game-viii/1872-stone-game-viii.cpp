class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        long long sum = 0;

        for (int x : stones) sum += x;

        long long dp = sum;

        for (int i = n - 2; i >= 1; --i) {
            sum -= stones[i + 1];
            dp = max(dp, sum - dp);
        }

        return (int)dp;
    }
};
