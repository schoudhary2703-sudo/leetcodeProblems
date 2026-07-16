class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD(n);
        int maxi=nums[0];
        long long ans=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGCD[i]=gcd(nums[i],maxi);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int low=0;
        int high=n-1;
        while(low<high){
            ans+=gcd(prefixGCD[low],prefixGCD[high]);
            low++;
            high--;
        }
        return ans;
    }

};