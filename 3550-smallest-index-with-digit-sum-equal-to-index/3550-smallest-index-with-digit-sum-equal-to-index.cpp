class Solution {
private:
    int digitSum(int x){
        int sum=0;
        while(x>0){
            int digit=x%10;
            sum+=digit;
            x=x/10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digitSum(nums[i])==i) return i;
        }
        return -1;
    }
};