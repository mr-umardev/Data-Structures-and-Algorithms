1class DSU {
2public:
3    vector<int> parent, rankv;
4    int components;
5
6    DSU(int n) {
7        parent.resize(n);
8        rankv.assign(n, 0);
9        iota(parent.begin(), parent.end(), 0);
10        components = n;
11    }
12
13    int find(int x) {
14        if (parent[x] != x) parent[x] = find(parent[x]);
15        return parent[x];
16    }
17
18    bool unite(int a, int b) {
19        a = find(a);
20        b = find(b);
21
22        if (a == b) return false;
23
24        if (rankv[a] < rankv[b]) swap(a, b);
25        parent[b] = a;
26        if (rankv[a] == rankv[b]) rankv[a]++;
27
28        components--;
29        return true;
30    }
31};
32
33class Solution {
34public:
35    bool canAchieve(int n, vector<vector<int>>& edges, int k, int x) {
36        DSU dsu(n);
37
38        // 1. Mandatory edges must be included
39        for (auto &e : edges) {
40            int u = e[0], v = e[1], s = e[2], must = e[3];
41
42            if (must == 1) {
43                if (s < x) return false;          // mandatory edge too weak
44                if (!dsu.unite(u, v)) return false; // mandatory cycle
45            }
46        }
47
48        // 2. Use all free optional edges
49        for (auto &e : edges) {
50            int u = e[0], v = e[1], s = e[2], must = e[3];
51
52            if (must == 0 && s >= x) {
53                dsu.unite(u, v);
54            }
55        }
56
57        // 3. Use upgradeable optional edges if needed
58        int usedUpgrades = 0;
59
60        for (auto &e : edges) {
61            int u = e[0], v = e[1], s = e[2], must = e[3];
62
63            if (must == 0 && s < x && 2 * s >= x) {
64                if (dsu.unite(u, v)) {
65                    usedUpgrades++;
66                    if (usedUpgrades > k) return false;
67                }
68            }
69        }
70
71        return dsu.components == 1;
72    }
73
74    int maxStability(int n, vector<vector<int>>& edges, int k) {
75        // Early check: mandatory edges alone must not form a cycle
76        {
77            DSU dsu(n);
78            for (auto &e : edges) {
79                if (e[3] == 1) {
80                    if (!dsu.unite(e[0], e[1])) return -1;
81                }
82            }
83        }
84
85        int low = 1, high = 200000, ans = -1;
86
87        while (low <= high) {
88            int mid = low + (high - low) / 2;
89
90            if (canAchieve(n, edges, k, mid)) {
91                ans = mid;
92                low = mid + 1;
93            } else {
94                high = mid - 1;
95            }
96        }
97
98        return ans;
99    }
100};