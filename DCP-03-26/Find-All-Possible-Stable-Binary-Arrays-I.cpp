1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        static int MOD = 1e9 + 7;
5        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
6        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
7
8        for (int i = 1; i <= min(zero, limit); i++) {
9            dp0[i][0] = 1;
10        }   
11
12        for (int j = 1; j <= min(one, limit); j++) {
13            dp1[0][j] = 1;
14        }
15
16        for (int i = 1; i <= zero; i++) {
17            for (int j = 1; j <= one; j++) {
18                // dp0[i][j]:
19                // Add one more zero to states with (i-1, j),
20                // then remove the invalid states where the zero-run becomes > limit
21                long long val0 = (long long)dp0[i - 1][j] + dp1[i - 1][j];
22                if (i - limit - 1 >= 0) {
23                    val0 -= dp1[i - limit - 1][j];
24                }
25                dp0[i][j] = (val0 % MOD + MOD) % MOD;
26
27                // dp1[i][j]:
28                // Add one more one to states with (i, j-1),
29                // then remove the invalid states where the one-run becomes > limit
30                long long val1 = (long long)dp0[i][j - 1] + dp1[i][j - 1];
31                if (j - limit - 1 >= 0) {
32                    val1 -= dp0[i][j - limit - 1];
33                }
34                dp1[i][j] = (val1 % MOD + MOD) % MOD;
35            }
36            
37        }
38        return ((long long)dp0[zero][one] + dp1[zero][one]) % MOD;
39    }
40};