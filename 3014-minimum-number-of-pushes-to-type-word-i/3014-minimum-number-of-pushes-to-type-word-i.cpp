class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int> count(26,0); 
        // lets count the frequency 
        for(char c: word){
            count[c-'a']++;
        }
        sort(count.begin(),count.end(),greater<int>());
        int ans =0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) break;

            if (i < 8)
                ans += count[i];
            else if (i < 16)
                ans += count[i] * 2;
            else if (i < 24)
                ans += count[i] * 3;
            else
                ans += count[i] * 4;
        }
        return ans;
    }
};