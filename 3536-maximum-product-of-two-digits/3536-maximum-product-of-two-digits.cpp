class Solution {
public:
    int maxProduct(int n) {
        int a=n%10;
        n/=10;
        int b=n%10;
        n/=10;
        int maxi=max(a,b);
        int secondMax=min(a,b);
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