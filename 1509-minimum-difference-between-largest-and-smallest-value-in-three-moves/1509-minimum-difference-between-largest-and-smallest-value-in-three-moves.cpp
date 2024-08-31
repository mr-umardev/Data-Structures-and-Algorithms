class Solution {
public:
    int minDifference(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 4) return 0;
    
    std::sort(nums.begin(), nums.end());
    
    int min_diff = INT_MAX;
    // We can remove up to 3 largest or smallest elements
    for (int i = 0; i <= 3; ++i) {
        int current_diff = nums[n - 4 + i] - nums[i];
        min_diff = std::min(min_diff, current_diff);
    }
    
    return min_diff;
}
};