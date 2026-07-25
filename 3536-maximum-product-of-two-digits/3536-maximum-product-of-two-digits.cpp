class Solution {
public:
    int maxProduct(int n) {
        
        int maxi=0;
        int secondMax=0;
        while(n>0){
            int digit=n%10;
            if(digit > maxi){
                secondMax=maxi;
                maxi=digit;
            }else if(digit > secondMax){
                secondMax=digit;
            }
            n/=10;
        }
        return maxi*secondMax;
    }
};