1class Solution {
2public:
3    long long maxSumTrionic(vector<int>& nums) {
4        int n = nums.size();
5        long long res = -2e18;
6        for (int i = 1; i < n - 2; ) {
7            int a = i, b = i;
8            long long net = nums[a];
9            while (b + 1 < n && nums[b + 1] < nums[b]) {
10                net += nums[++b];
11            }
12            if (b == a) { i++; continue; }
13            int c = b;
14            long long left = 0, right = 0, lx = -2e18, rx = -2e18;
15            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
16                left += nums[--a];
17                lx = max(lx, left);
18            }
19            if (a == i) { i++; continue; }
20            while (b + 1 < n && nums[b + 1] > nums[b]) {
21                right += nums[++b];
22                rx = max(rx, right);
23            }
24            if (b == c) { i++; continue; }
25            res = max(res, lx + rx + net);
26            i = b;
27        }
28        return res;
29    }
30};