class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans=-1;
        if(k==(nums.size())){
            for(int i =0;i<nums.size();i++){
                
                    ans=max(ans,nums[i]);
                
            }
            return ans;
        }
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        if(k==1){
            for(int i =0;i<nums.size();i++){
                if(mp[nums[i]]==1){
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }
            if (mp[nums[0]] == 1)
                ans = max(ans, nums[0]);

            if (mp[nums[nums.size() - 1]] == 1)
                ans = max(ans, nums[nums.size() - 1]);
        
        return ans;
    }
};