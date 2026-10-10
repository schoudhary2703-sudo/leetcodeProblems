class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
         int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<long long> diff(n);

        long long total = 0, high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = llabs(1LL * nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        if (total <= k) return 0;

        long long low = 0;

        while (low < high) {
            long long mid = (low + high) / 2;
            long long required = 0;

            for (long long x : diff) {
                if (x > mid) {
                    required += x - mid;
                }
            }

            if (required <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long limit = low;
        long long used = 0;
        long long answer = 0;

        for (long long& x : diff) {
            if (x > limit) {
                used += x - limit;
                x = limit;
            }

            answer += x * x;
        }

        long long remaining = k - used;
        answer -= remaining * (2 * limit - 1);

        return answer;
    }
};