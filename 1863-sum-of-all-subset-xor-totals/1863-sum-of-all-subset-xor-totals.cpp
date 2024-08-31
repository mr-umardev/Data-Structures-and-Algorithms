#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalXOR = 0;
        backtrack(nums, 0, 0, totalXOR);
        return totalXOR;
    }
    
    void backtrack(const vector<int>& nums, int index, int currentXOR, int& totalXOR) {
        if (index == nums.size()) {
            totalXOR += currentXOR;
            return;
        }
        
        // Include the current element
        backtrack(nums, index + 1, currentXOR ^ nums[index], totalXOR);
        
        // Exclude the current element
        backtrack(nums, index + 1, currentXOR, totalXOR);
    }
};
