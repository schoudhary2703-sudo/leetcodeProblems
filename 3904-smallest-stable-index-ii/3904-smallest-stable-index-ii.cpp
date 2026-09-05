class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        vector<int> minimum(n);
        
        int mini=nums[n-1];
        minimum[n-1]=mini;
        for(int i=n-2 ;i>=0;i--){
            mini=min(minimum[i+1],nums[i]);
            minimum[i]=mini;
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int score=maxi-minimum[i];
            if(score<=k)return i;
        }
        return -1;
    }
};