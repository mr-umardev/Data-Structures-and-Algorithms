1class Solution {
2public:
3    int minOperations(string s) {
4        int count = 0, n = s.length();
5        for (int i = 0; i < n; i++)
6            count += (s[i] ^ i) & 1;
7          
8        return min(count, n - count);
9    }
10};