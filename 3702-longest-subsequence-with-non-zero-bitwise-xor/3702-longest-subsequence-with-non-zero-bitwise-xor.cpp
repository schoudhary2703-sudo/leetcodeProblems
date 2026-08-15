class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool zero = true;
        int xoor = 0;
        for(int num: nums){
            xoor^=num;
            if(num!=0)zero=false;
        }
        if(xoor!=0){
            return nums.size();
        } 
        if(zero)return 0;
        
        return nums.size()-1;
    }
};