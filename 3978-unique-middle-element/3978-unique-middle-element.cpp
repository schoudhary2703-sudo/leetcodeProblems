class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middleindex=(n-1)/2;
        for(int i = 0;i<n;i++){
            if(nums[i]==nums[middleindex] && i!=middleindex){
                return false;
            }
        }
        return true;
    }
};