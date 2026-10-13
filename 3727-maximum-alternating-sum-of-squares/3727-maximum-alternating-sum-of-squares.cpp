class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            v[i] = val * val;
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            ans -= v[i];
        }
        for (int i = half; i < n; ++i) {
            ans += v[i];
        }
        return ans;
    }
};