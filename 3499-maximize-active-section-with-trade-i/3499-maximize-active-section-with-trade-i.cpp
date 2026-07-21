class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        std::vector<int> zeroBlocks;
        int n = s.length();
        
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                totalOnes++;
                i++;
            } else {
                int j = i;
                while (j < n && s[j] == '0') {
                    j++;
                }
                zeroBlocks.push_back(j - i);
                i = j;
            }
        }
        
        int maxGain = 0;
        for (size_t k = 0; k + 1 < zeroBlocks.size(); ++k) {
            maxGain = std::max(maxGain, zeroBlocks[k] + zeroBlocks[k + 1]);
        }
        
        return totalOnes + maxGain;
    }
};