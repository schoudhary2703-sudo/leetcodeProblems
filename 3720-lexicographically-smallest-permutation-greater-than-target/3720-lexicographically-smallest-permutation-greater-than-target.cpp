class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < s.size(); ++i) {
            int x = target[i] - 'a';

            if (cnt[x]) {
                cnt[x]--;
                ans += target[i];
            } else {
                int j = x + 1;
                while (j < 26 && !cnt[j]) ++j;

                if (j < 26) {
                    cnt[j]--;
                    ans += char('a' + j);

                    for (int k = 0; k < 26; ++k)
                        ans.append(cnt[k], char('a' + k));

                    return ans;
                }
                break;
            }
        }

        while (!ans.empty()) {
            int i = ans.size() - 1;
            int x = ans.back() - 'a';
            ans.pop_back();
            cnt[x]++;

            int j = target[i] - 'a' + 1;
            while (j < 26 && !cnt[j]) ++j;

            if (j < 26) {
                cnt[j]--;

                ans += char('a' + j);
                for (int k = 0; k < 26; ++k)
                    ans.append(cnt[k], char('a' + k));

                return ans;
            }
        }

        return "";
    }
};