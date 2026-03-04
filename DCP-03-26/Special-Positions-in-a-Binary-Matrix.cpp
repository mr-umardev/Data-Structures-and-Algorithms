1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4        int m = mat.size(), n = mat[0].size();
5        vector<int> row(m, 0), col(n, 0);
6
7        for (int i = 0; i < m; i++)
8            for (int j = 0; j < n; j++)
9                if (mat[i][j] == 1) {
10                    row[i]++;
11                    col[j]++;
12                }
13
14        int ans = 0;
15        for (int i = 0; i < m; i++)
16            for (int j = 0; j < n; j++)
17                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
18                    ans++;
19
20        return ans;
21    }
22};