class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26,0);
        string ans="";
        char middle='\0';
        for(char c :  s){
            count[c-'a']++;
        }
        for( int i= 0 ;i<26;i++){
            int half=count[i]/2;
            if(count[i]%2!=0){
                middle=i+'a';

            }
            while(half--){
                ans+=(char)(i+'a');
                count[i]--;
            }

        }
        string rev=ans;
        reverse(rev.begin(),rev.end());
        if(middle!='\0'){
            return (ans+middle+rev);
        }
        return (ans+rev);
    }
};