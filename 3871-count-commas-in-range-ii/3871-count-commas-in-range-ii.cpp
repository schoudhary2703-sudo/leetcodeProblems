class Solution {
public:
    long long countCommas(long long n) {
        long long comma=0;
        long long p=1;
        while(pow(10,3*p)<=n){
            long long first = pow(10,3*p);
            long long last=min(n , (long long )pow( 10,(3 * (p+1)))-1);
            long long count = last-first+1;
            comma+=count*p;
            p++;
        }
        return comma;
    }
};