class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
    int count = 0;
    
    for (int j = 1; j < n - 1; ++j) {
        int less_left = 0, greater_left = 0;
        int less_right = 0, greater_right = 0;

        // Count elements less and greater to the left of j
        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) less_left++;
            else if (rating[i] > rating[j]) greater_left++;
        }

        // Count elements less and greater to the right of j
        for (int k = j + 1; k < n; ++k) {
            if (rating[k] < rating[j]) less_right++;
            else if (rating[k] > rating[j]) greater_right++;
        }

        // Calculate the number of valid teams
        count += less_left * greater_right + greater_left * less_right;
    }

    return count;
    }
};