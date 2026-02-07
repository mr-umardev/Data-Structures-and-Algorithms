1// Optimizations for faster execution (Beats 100%)
2#pragma GCC optimize("O3,unroll-loops")
3#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
4
5static const bool _ = []() {
6    ios_base::sync_with_stdio(false);
7    cin.tie(NULL);
8    cout.tie(NULL);
9    return false;
10}();
11
12class Solution {
13public:
14    int minimumDeletions(string s) {
15        int res = 0;
16        int b_count = 0;
17        
18        // Iterate by reference to avoid unnecessary copying
19        for (const char& c : s) {
20            if (c == 'b') {
21                b_count++;
22            } else { 
23                // Encountered 'a'
24                // If there are preceding 'b's, we have a conflict ("ba")
25                if (b_count > 0) {
26                    res++;      // Delete one character to resolve conflict
27                    b_count--;  // Decrease count of unmatched 'b's
28                }
29            }
30        }
31        
32        return res;
33    }
34};