class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int mod = 1e9+7;
        vector <int> count(n+1,0);
        vector <long long> prefixSum(n+1,0);
        vector <long long> prefixValue(n+1,0);
        vector <long long> power10(n+1,1);
        for(int i=1;i<=n;i++){
            power10[i]=(power10[i-1]*10)%mod;
        }
        for(int i=1;i<=n;i++){
            int digit=(s[i-1]-'0');
            count[i]=count[i-1];
            prefixSum[i]=prefixSum[i-1];
            prefixValue[i]=prefixValue[i-1];
            if(digit != 0){
                count[i]++;
                prefixSum[i]+=digit;
                prefixValue[i]=( prefixValue[i-1]*10 + digit ) % mod ;
            }
        }
        vector<int> result;
        for(const auto& q:queries){
            int l = q[0] + 1;
            int r = q[1] + 1;
            long long sum = prefixSum[r] - prefixSum[l-1];
            int k = count[r] - count[l-1];
            long long remove= (prefixValue[l-1]*power10[k])%mod;
            long long value= (prefixValue[r]-remove+mod)%mod;
            long long ans = (value *(sum % mod )) % mod ;
            result.push_back(ans);
        }
        return result;
    }
};