class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxrange=-1;
        int ans=0;
        
        for(int i = 0 ; i<n;i++){
            int num = abs(nums[i]);
            int l=0;
            int s=9;
            if(num==0){
                l=0;
                s=0;
            }
            else{
            while(num>0){
                l=max(l,num%10);
                s=min(s,num%10);
                num/=10;
            }
            }
            int diff=l-s;
            if(diff>maxrange){
                maxrange=diff;
                ans=nums[i];
            }
            else if(diff==maxrange)ans+=nums[i];
            
        }
        return ans;
    }
};