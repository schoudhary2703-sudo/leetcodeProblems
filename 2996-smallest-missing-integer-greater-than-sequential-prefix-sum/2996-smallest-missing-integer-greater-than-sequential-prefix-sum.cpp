class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1; 
        int sum = nums[0];
        while(i< nums.size() && nums[i]==nums[i-1]+1 ){
            sum+=nums[i];
            i++;
        }
        unordered_set<int> st;
        for (int num:nums){
            st.insert(num);
        }
        while(st.find(sum)!=st.end()){
            sum++;
        }
        return sum;
    }
};