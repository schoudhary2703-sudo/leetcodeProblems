class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return n ;
        }
        int k = 0;
        while(1<<k<=n){
            k++;
        }
        return 1<<k;
    }
};