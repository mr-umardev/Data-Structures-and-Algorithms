class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; ++i) {
        auto min_it = min_element(nums.begin(), nums.end());
        *min_it *= multiplier;
    }
    
    return nums;
    }
};