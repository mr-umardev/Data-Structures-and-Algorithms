1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        int ans = nums[k - 1] - nums[0];
7        for(int i = 0; i + k <= n; i ++){
8            ans = min(ans, nums[i + k - 1] - nums[i]);
9        }
10        return ans;
11    }
12};