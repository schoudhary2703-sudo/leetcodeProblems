using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> paths(n + 1, vector<int>(n + 1, 0));
        
        dp[n - 1][n - 1] = 0;
        paths[n - 1][n - 1] = 1;
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'S' || board[r][c] == 'X') {
                    continue;
                }
                
                int max_val = max({dp[r + 1][c], dp[r][c + 1], dp[r + 1][c + 1]});
                
                if (max_val == -1) {
                    continue;
                }
                
                long long ways = 0;
                if (dp[r + 1][c] == max_val) ways = (ways + paths[r + 1][c]) % mod;
                if (dp[r][c + 1] == max_val) ways = (ways + paths[r][c + 1]) % mod;
                if (dp[r + 1][c + 1] == max_val) ways = (ways + paths[r + 1][c + 1]) % mod;
                
                int current_score = (board[r][c] == 'E') ? 0 : board[r][c] - '0';
                dp[r][c] = max_val + current_score;
                paths[r][c] = ways;
            }
        }
        
        if (paths[0][0] == 0) {
            return {0, 0};
        }
        
        return {dp[0][0], paths[0][0]};
    }
};