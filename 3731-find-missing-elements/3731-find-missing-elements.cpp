class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int maxi=nums[nums.size()-1];
        int mini=nums[0];
        while(mini<=maxi){
            if(find(nums.begin(), nums.end(), mini) == nums.end()){
                ans.push_back(mini);
            }
            mini++;
        }
        return ans;

    }
};