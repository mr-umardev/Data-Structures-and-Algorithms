1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        int count = 0, i = 0;
5        vector<string> res;
6        
7        for (int j = 0; j < s.length(); j++) {
8            // Track balance: +1 for '1', -1 for '0'
9            count += (s[j] == '1') ? 1 : -1;
10            
11            // Found a balanced chunk when count returns to 0
12            if (count == 0) {
13                // Recursively maximize inner part, wrap with 1...0
14                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
15                i = j + 1; // Move to next potential chunk
16            }
17        }
18        
19        // Sort chunks in descending order for largest arrangement
20        sort(res.begin(), res.end(), greater<string>());
21        
22        string result;
23        for (const string& str : res) {
24            result += str;
25        }
26        return result;
27    }
28};