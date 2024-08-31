class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
    vector<int> dp(n + 1, 0); // dp[i] will store the minimum deletions for the substring s[0..i-1]
    
    int countB = 0; // To keep track of the number of 'b's encountered so far
    
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'a') {
            // To make s[0..i-1] balanced ending with 'a', we either:
            // 1. delete this 'a' which gives us dp[i-1] + 1 deletions
            // 2. keep this 'a' which gives us countB deletions to remove all 'b's before it
            dp[i] = min(dp[i - 1] + 1, countB);
        } else {
            // If s[i-1] is 'b', we don't need to do anything special to keep it balanced
            dp[i] = dp[i - 1];
            ++countB; // Increment the count of 'b's
        }
    }
    
    return dp[n];
    }
};