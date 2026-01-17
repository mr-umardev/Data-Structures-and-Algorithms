1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
4        long long maxSide = 0;
5        int n = bottomLeft.size();
6
7        for (int i = 0; i < n; i++) {
8            for (int j = i + 1; j < n; j++) {
9                // Calculate the intersection boundaries
10                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
11                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
12                long long x2 = min(topRight[i][0], topRight[j][0]);
13                long long y2 = min(topRight[i][1], topRight[j][1]);
14
15                // Calculate width and height of the intersection
16                long long width = x2 - x1;
17                long long height = y2 - y1;
18
19                // Check if they actually intersect
20                if (width > 0 && height > 0) {
21                    long long currentSide = min(width, height);
22                    maxSide = max(maxSide, currentSide);
23                }
24            }
25        }
26
27        return maxSide * maxSide;
28    }
29};