class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum  = 0 ;
        long long x=0;
        long long multiplier = 1;
        while (n>0){
            int num=n%10;
            if(num!=0){
                sum+=num;
                x=(multiplier*num)+x;
                multiplier*=10;
            }
            n/=10;
        }
        return sum*x;
    }
};