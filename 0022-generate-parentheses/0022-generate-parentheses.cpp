class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        
        unordered_set<string> s;
        
        
        for (int i = 0; i < n; i++) {
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n - 1 - i);
            
            
            for (const string& l : left) {
                for (const string& r : right) {
                    s.insert("(" + l + ")" + r);
                }
            }
        }
        
        return vector<string>(s.begin(), s.end());
    }
};