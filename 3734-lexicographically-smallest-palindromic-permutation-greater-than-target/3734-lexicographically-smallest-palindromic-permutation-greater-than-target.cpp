class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        for (int x : cnt)
            odd += x & 1;

        if (odd > 1)
            return "";

        int mid = -1;

        if (s.size() & 1) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] & 1) {
                    mid = i;
                    cnt[i]--;
                    break;
                }
            }
        }

        string left;
        int m = s.size() / 2;

        int i = 0;

        for (; i < m; i++) {
            int x = target[i] - 'a';
            cnt[x] -= 2;
            left += target[i];

            if (cnt[x] < 0)
                break;
        }

        if (i == m) {
            string ans = left;

            if (mid != -1)
                ans += char('a' + mid);

            for (int j = (int)left.size() - 1; j >= 0; j--)
                ans += left[j];

            if (ans > target)
                return ans;

            if (mid != -1)
                ans.pop_back();
        }

        while (!left.empty()) {
            int x = left.back() - 'a';
            left.pop_back();
            cnt[x] += 2;

            for (int j = x + 1; j < 26; j++) {
                if (cnt[j] == 0)
                    continue;

                cnt[j] -= 2;
                left += char('a' + j);

                for (int k = 0; k < 26; k++) {
                    while (cnt[k] > 0) {
                        cnt[k] -= 2;
                        left += char('a' + k);
                    }
                }

                string ans = left;

                if (mid != -1)
                    ans += char('a' + mid);

                for (int k = (int)left.size() - 1; k >= 0; k--)
                    ans += left[k];

                return ans;
            }
        }

        return "";
    }
};