class Solution {
public:
   
    long long countArrangements(vector<int> cnt, long long limit) {
        long long ways = 1;
        int total = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                total++;
                ways = ways * total / j;     
                if (ways > limit) return limit + 1;
            }
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        long long kk = k; 

        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        char middle = '\0';
        vector<int> half(26, 0);
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) middle = i + 'a';
            half[i] = count[i] / 2;
            halfLen += half[i];
        }

       
        
        long long totalArrangements = countArrangements(half, kk);
        if (totalArrangements < kk) return "";

        
        string leftHalf = "";
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--; 
                long long ways = countArrangements(half, kk); 
                if (ways >= kk) {
                    leftHalf += (char)('a' + c);
                    break;                     
                } else {
                    kk -= ways;   
                    half[c]++;    
                }
            }
        }

        string rev = leftHalf;
        reverse(rev.begin(), rev.end());
        if (middle != '\0')
            return leftHalf + middle + rev;
        return leftHalf + rev;
    }
};