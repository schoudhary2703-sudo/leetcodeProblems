class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sr = -1, sc = -1;

        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = classroom[i][j];
                if (c == 'S') {
                    sr = i; sc = j;
                } else if (c == 'L') {
                    litterIdx[i][j] = k++;
                }
            }
        }

        if (k == 0) return 0;
        int totalMask = (1 << k) - 1;

    
        vector<vector<vector<int>>> visited(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        int startMask = 0;
        if (litterIdx[sr][sc] != -1) startMask |= (1 << litterIdx[sr][sc]);

        visited[sr][sc][startMask] = energy;

        queue<tuple<int,int,int,int>> q;  
        q.push({sr, sc, energy, startMask});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == totalMask) return dist;
                if (e == 0) continue;  

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int newE = (classroom[nr][nc] == 'R') ? energy : e - 1;

                    int newMask = mask;
                    if (litterIdx[nr][nc] != -1) {
                        newMask |= (1 << litterIdx[nr][nc]);
                    }

                   
                    if (visited[nr][nc][newMask] >= newE) continue;

                    visited[nr][nc][newMask] = newE;
                    q.push({nr, nc, newE, newMask});
                }
            }
            dist++;
        }

        return -1;
    }
};