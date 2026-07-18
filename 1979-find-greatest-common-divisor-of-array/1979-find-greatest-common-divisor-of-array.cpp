class Solution {
private:
    int customGcd(int a , int b ){
        return b==0 ? a : customGcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        // approach one from side 
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // return gcd(nums[0],nums[n-1]);
        

        // optimization 
        int min_val=1001;
        int max_val=1;
        for(int num:nums){
            if(max_val<num)max_val=num;
            if(min_val>num)min_val=num;
        }
        return customGcd(min_val,max_val);
    }
};