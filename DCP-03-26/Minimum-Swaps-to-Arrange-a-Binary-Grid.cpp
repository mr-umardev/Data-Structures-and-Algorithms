1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int size = 1;
6        while (size < n) size <<= 1;
7
8        // maxT stores max trailing zeros in range;
9        // sumT tracks count of active rows
10        vector<int> maxT(size << 1, -1);
11        vector<int> sumT(size << 1, 0);
12
13        for (int i = 0; i < n; i++) {
14            int trail = 0;
15            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) trail++;
16            maxT[size | i] = trail;
17            sumT[size | i] = 1;
18        }
19
20        // Build tree: O(n)
21        for (int i = size - 1; i > 0; i--) {
22            maxT[i] = max(maxT[i << 1], maxT[(i << 1) | 1]);
23            sumT[i] = sumT[i << 1] + sumT[(i << 1) | 1];
24        }
25
26        int swap = 0;
27        for (int i = 0; i < n; i++) {
28            int req = n - 1 - i;
29            if (maxT[1] < req) return -1; // No row satisfies the condition
30
31            int idx = 1;
32            // Greedy search for the first available row with enough zeros: O(log n)
33            while (idx < size) {
34                if (maxT[idx << 1] >= req) {
35                    idx <<= 1;
36                } else {
37                    // Skip the left subtree, add its active row count to swaps
38                    swap += sumT[idx << 1];
39                    idx = (idx << 1) | 1;
40                }
41            }
42
43            // Mark row as deleted by resetting values
44            maxT[idx] = -1;
45            sumT[idx] = 0;
46            
47            // Update ancestors: O(log n)
48            for (int p = idx >> 1; p > 0; p >>= 1) {
49                maxT[p] = max(maxT[p << 1], maxT[(p << 1) | 1]);
50                sumT[p] = sumT[p << 1] + sumT[(p << 1) | 1];
51            }
52        }
53
54        return swap;
55    }
56};
57