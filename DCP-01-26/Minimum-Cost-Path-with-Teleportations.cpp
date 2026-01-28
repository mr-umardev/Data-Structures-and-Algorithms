1class Solution {
2public:
3    static constexpr int INF = 1000000000;
4    int rows = 0, cols = 0, maxval = 0;
5
6    void dp_iteration(vector<vector<int>>& dp, vector<int>& best_teleport, vector<vector<int>>& grid) {
7        for (int r = rows - 1; r >= 0; --r) {
8            for (int c = cols - 1; c >= 0; --c) {
9                int walk = ((r != rows - 1) || (c != cols - 1)) ? INF : 0;
10                if (r + 1 < rows) walk = min(walk, dp[r + 1][c] + grid[r + 1][c]);
11                if (c + 1 < cols) walk = min(walk, dp[r][c + 1] + grid[r][c + 1]);
12                dp[r][c] = min(walk, best_teleport[grid[r][c]]);
13            }
14        }
15    }
16
17    vector<int> build_teleport(vector<vector<int>>& dp, vector<vector<int>>& grid) {
18        vector<int> teleport(maxval + 1, INF);
19
20        // First build mincost for each v = value
21        for (int r = 0; r < rows; ++r)
22            for (int c = 0; c < cols; ++c) 
23                teleport[grid[r][c]] = min(teleport[grid[r][c]], dp[r][c]);
24
25        // Then build prefix mincost for v <= value
26        for (int v = 0; v <= maxval; ++v)
27            teleport[v] = min(teleport[v], v > 0 ? teleport[v - 1] : INF);
28
29        return teleport;
30    }
31
32    int minCost(vector<vector<int>>& grid, int k) {
33        // Calculate dimensions
34        rows = grid.size(), cols = grid[0].size();
35        for (auto &row: grid) maxval = max(maxval, *max_element(row.begin(), row.end()));
36
37        vector<int> best_teleport(maxval + 1, INF);
38        vector<vector<int>> dp(rows, vector<int>(cols, INF));
39        dp[rows - 1][cols - 1] = 0; // zero cost to reach dest from dest
40
41        for (int t = 0; t <= k; ++t) { // t teleports allowed
42            dp_iteration(dp, best_teleport, grid);
43            best_teleport = build_teleport(dp, grid);
44        }
45
46        return dp[0][0];
47    }
48};