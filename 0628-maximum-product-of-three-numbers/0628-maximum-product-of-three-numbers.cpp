class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX;
        // min2 min1 max3 max2 max1 yeh type se hoga x-axis pr
        for(int num:nums){
            if(num>max1){
                max3=max2;
                max2=max1;
                max1=num;
            }else if(num>max2){
                max3=max2;
                max2=num;
            }else if(num>max3){
                max3=num;
            }
            
            if(num<min2){
                min1=min2;
                min2=num;
            }else if(num<min1){
                min1=num;
            }
        }
        int posmul=max1*max2*max3;
        int negmul=max1*min1*min2;
        return max(negmul,posmul);
    }
};