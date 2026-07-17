class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int M=*max_element(nums.begin(),nums.end());
        vector<int> cnt (M+1,0);
        for(int x:nums) cnt[x]++;
        vector<int> mul(M+1,0);
        for(int i=1;i<=M;i++)
            for(int y=i;y<=M;y+=i)
                mul[i]+=cnt[y];
        vector<long long> exact(M+1,0);
        for(int i=1;i<=M;i++){
            long long c=mul[i];
            exact[i]=c*(c-1)/2;
        }
        for(int i=M;i>=1;i--){
            for(int y=2*i;y<=M;y+=i){
                exact[i]-=exact[y];
            }
        }
        vector<long long> prefix(M+1,0);
        for(int i =1;i<=M;i++){
            prefix[i]=prefix[i-1]+exact[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            int lo = 1, hi = M, res = M;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] > q) { res = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};