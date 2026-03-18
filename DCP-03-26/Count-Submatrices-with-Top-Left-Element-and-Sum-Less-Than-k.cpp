1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int ans = 0;
5        int m = grid.size(), n = grid[0].size();
6        vector<vector<int>> px(m+1, vector<int>(n+1, 0));
7        for (int i = 0; i < m; i++) {
8            for (int j = 0; j < n; j++) {
9                px[i+1][j+1] = grid[i][j] + px[i][j+1] + px[i+1][j] - px[i][j];
10                if (px[i+1][j+1] <= k) ans++;
11            }
12        }
13        return ans;
14    }
15};