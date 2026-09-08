class Solution {
public:
    int countCommas(int n) {
        long long comma=0;
        int p=1;
        while(pow(10,3*p)<=n){
            long long first = pow(10,3*p);
            long long last = min((long long)n,(long long)pow(10,3*(p+1))-1);
            long long count=last - first + 1;
            comma+=count*p;
            p++;
        }
        return comma;
    }
};