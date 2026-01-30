1// Use DP+ Floyd Warshall's algorithm
2uint64_t D[201][201];
3uint64_t dp[1001];
4class Solution {
5public:
6    unordered_map<string, int> id;
7    unordered_set<int> lens;
8
9    void init() {// fill all with ULLONG_MAX for all at 1 times
10        if (D[0][0]==ULLONG_MAX) return;
11        memset(D, 255, sizeof(D));
12    }
13    void FW(int m, int& sz, vector<string>& original, vector<string>& changed, vector<int>& cost) {
14        int row, col;
15        for (int i=0; i<m; i++) {
16            string& s=original[i];
17            string& t=changed[i];
18
19            auto it=id.find(s);
20            if (it==id.end()) {
21                row=sz++;
22                int slen=s.size();
23                auto it_lens=lens.find(slen);
24                if (it_lens==lens.end())
25                    lens.insert(slen);
26                id[s]=row;
27            }
28            else
29                row=it->second;
30            it=id.find(t);
31            if (it==id.end()) {
32                col=sz++;
33                id[t]=col;
34            }
35            else
36                col=it->second;
37            D[row][col]=min(D[row][col], (uint64_t)cost[i]);
38        }
39        for (int i=0; i<sz; i++) D[i][i]=0;
40
41        for (int k=0; k<sz; k++) {
42            for (int i=0; i<sz; i++) {
43                if (D[i][k]<ULLONG_MAX) {
44                    for (int j=0; j<sz; j++) {
45                        if (D[k][j]<LLONG_MAX) {
46                            D[i][j]=min(D[i][j], D[i][k] + D[k][j]);
47                        }
48                    }
49                }
50            }
51        }
52    }
53
54    long long minimumCost(string& source, string& target,
55                          vector<string>& original,
56                          vector<string>& changed,
57                          vector<int>& cost) {
58        init();
59        const int m=original.size(), n=source.size();       
60        id.reserve(m*2);
61        lens.reserve(n);
62        int sz=0;
63        FW(m, sz, original, changed, cost);
64        
65        memset(dp, 255, sizeof(uint64_t)*(n+1));
66        dp[0]=0;
67        for (int i=0; i<n; i++) {
68            if (dp[i]==ULLONG_MAX) continue;
69            if (source[i]==target[i])
70                dp[i+1]=min(dp[i+1], dp[i]);
71
72            for (int t : lens) {
73                if (i+t>n) continue;
74
75                string s_sub=source.substr(i, t);
76                string t_sub=target.substr(i, t);
77                auto it=id.find(s_sub);
78                int x=(it!=id.end()) ? it->second : -1;
79                it=id.find(t_sub);
80                int y=(it!=id.end()) ? it->second : -1;
81
82                if (x>=0 && y>=0 && D[x][y]<ULLONG_MAX) {
83                    dp[i+t]=min(dp[i+t], dp[i]+D[x][y]);
84                }
85            }
86        }
87        for (int i=0; i<sz; i++)// reset for the next testcase
88            memset(D[i], 255, sizeof(uint64_t)*sz);
89        return dp[n]==ULLONG_MAX ? -1 : dp[n];
90    }
91};
92auto init = []() {
93    ios::sync_with_stdio(0);
94    cin.tie(0);
95    cout.tie(0);
96    return 'c';
97}();