class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> triplet(2048, false);
        vector<bool> pair(2048, false);
        for(int j=0; j<n; j++){
            for(int k=j;k<n;k++){
                    int XOR=nums[j]^nums[k];
                    pair[XOR]=true;
            }
        }
        for(int i =0 ;i<n;i++){
            for(int p=0;p<2048;p++){
                if(pair[p]){
                    triplet[(p^nums[i])]=true;
                }
            }
        }
        int ans=0;
        
        for(int y=0;y<2048;y++){
            if(triplet[y]){
                ans++;
            }
        }
        return ans;
    }
};