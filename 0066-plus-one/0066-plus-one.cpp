class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int size = digits.size();
        
        // Start from the last digit and add one
        for (int i = size - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        
        // If all digits were 9, we need to add an extra digit at the start
        digits.insert(digits.begin(), 1);
        
        return digits;
    }

};