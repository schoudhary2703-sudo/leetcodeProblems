class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n =nums.size();
        int leftmax=nums[0];
        int maxi=nums[0]+nums[k];
        
        for(int j = k ; j<n;j++){
            leftmax=max(leftmax,nums[j-k]);
            maxi=max(maxi,leftmax+nums[j]);
        }
    
        return maxi;
    }
};