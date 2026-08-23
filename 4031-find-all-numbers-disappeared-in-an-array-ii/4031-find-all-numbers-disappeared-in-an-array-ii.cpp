class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int ptr=0;
        int i=lower;
        int n = nums.size();
        while(i<=upper){
            while (ptr < n && nums[ptr] < i) ptr++;
            if(ptr<n && nums[ptr] == i){
                i++;
                ptr++;
            }else{
                int start=i;
                while(i<=upper && (ptr >= n || nums[ptr]!=i)){
                        i++;
                }
                ans.push_back({start,i-1});
            }
        }
        return ans;
    }
};