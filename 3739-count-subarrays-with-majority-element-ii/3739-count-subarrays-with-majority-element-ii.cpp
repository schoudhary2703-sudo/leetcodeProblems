

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int,int> mp;
        int cumsum=0;
        mp[0]=1;
        long long validleftPoints=0;
        long long result=0;
        for(int j = 0;j<n;j++){
            if(nums[j]==target){
                validleftPoints+=mp[cumsum];
                cumsum+=1;
            }
            else{
                cumsum-=1;
                validleftPoints-=mp[cumsum];
                
            }
            mp[cumsum]+=1;
            result+=validleftPoints;
        }
        return result;
    }
};