class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long mod=1e9 + 7 ;
        long long cur = k;
        long long nextCost=1;
        long long ans=0;
        for(int num:nums){
            if(cur<num){
                long long t = (num-cur+k-1LL)/k;
                __int128 sum = (__int128)t * (2 * (__int128)nextCost + t - 1) / 2;
                ans=(ans+(long long)(sum%mod))%mod;
                cur += t * 1LL * k;
                nextCost += t;
            }
            cur-=num;
        }
        return ans%mod;
    }
};