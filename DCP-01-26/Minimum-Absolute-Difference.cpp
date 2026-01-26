1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(arr.begin(), arr.end());
5
6        int minDiff = INT_MAX;
7        vector<vector<int>> result;
8
9        // Find minimum difference
10        for (int i = 1; i < arr.size(); i++) {
11            minDiff = min(minDiff, arr[i] - arr[i - 1]);
12        }
13
14        // Collect all pairs with minimum difference
15        for (int i = 1; i < arr.size(); i++) {
16            if (arr[i] - arr[i - 1] == minDiff) {
17                result.push_back({arr[i - 1], arr[i]});
18            }
19        }
20
21        return result;
22    }
23};
24