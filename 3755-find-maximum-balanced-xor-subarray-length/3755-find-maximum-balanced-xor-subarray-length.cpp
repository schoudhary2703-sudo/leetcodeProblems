class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxlength = 0;
        map<pair<int,int>,int> mp;
        int prefixXOR=0;
        int diff=0;
        mp[{0,0}]=-1;
        for(int i = 0 ; i<n ; i++ ){
            
            prefixXOR^=nums[i];
            if(nums[i]%2==0) diff++;
            else diff--;
            pair<int,int>curr={prefixXOR,diff};
            if(mp.find(curr) != mp.end()){
                maxlength=max(maxlength,i-mp[curr]);
            }
            else{
                mp[curr]=i;
            }
        }
        return maxlength;

    }
};