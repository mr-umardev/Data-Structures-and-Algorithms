class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
    int numOnes = 0;

    // Count total number of 1's in the array
    for (int num : nums) {
        if (num == 1) {
            numOnes++;
        }
    }

    // If there are no 1's or all are 1's, no swaps are needed
    if (numOnes == 0 || numOnes == n) {
        return 0;
    }

    // Initial window of size numOnes
    int currentOnes = 0;
    for (int i = 0; i < numOnes; i++) {
        if (nums[i] == 1) {
            currentOnes++;
        }
    }

    // Maximum number of 1's in any window of size numOnes
    int maxOnesInWindow = currentOnes;
    for (int i = 1; i < n; i++) {
        // Slide the window by removing the element going out and adding the element coming in
        if (nums[(i - 1) % n] == 1) {
            currentOnes--;
        }
        if (nums[(i + numOnes - 1) % n] == 1) {
            currentOnes++;
        }
        maxOnesInWindow = std::max(maxOnesInWindow, currentOnes);
    }

    // Minimum swaps is the number of 0's in the window with maximum 1's
    return numOnes - maxOnesInWindow;
    }
};