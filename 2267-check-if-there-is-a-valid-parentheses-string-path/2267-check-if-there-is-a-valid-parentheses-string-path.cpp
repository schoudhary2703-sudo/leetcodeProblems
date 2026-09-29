#include <vector>
#include <cstring>

using namespace std;

class Solution {
    int m, n;
    int memo[100][100][105];

    bool dfs(int r, int c, int balance, vector<vector<char>>& grid) {
        if (grid[r][c] == '(') balance++;
        else balance--;

        if (balance < 0) return false;
        if (balance > (m + n) / 2) return false;

        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool canReach = false;
        if (r + 1 < m) {
            canReach = canReach || dfs(r + 1, c, balance, grid);
        }
        if (c + 1 < n) {
            canReach = canReach || dfs(r, c + 1, balance, grid);
        }

        return memo[r][c][balance] = canReach;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, 0, grid);
    }
};