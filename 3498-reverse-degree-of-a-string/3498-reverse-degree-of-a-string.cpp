class Solution {
public:
    int reverseDegree(string s) {
        int product=0;
        for(int i=0;i<s.length();i++){
            product += (i+1)*(26-s[i]+'a');
        }
        return product;
    }
};