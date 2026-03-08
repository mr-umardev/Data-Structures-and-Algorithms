1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        string ans = string(nums.size(), '0');  // Start with "000...0"
5        
6        if(find(nums.begin(), nums.end(), ans) == nums.end()) return ans;  // Check if it already works
7
8        for(int i = 0; i < nums.size(); i++) { 
9            ans[i] = '1';  // Try flipping one bit at a time
10            if(find(nums.begin(), nums.end(), ans) == nums.end()) 
11                return ans;  
12            ans[i] = '0';  // Revert back if needed
13        }
14        return ans;  // Fallback case
15    }
16};