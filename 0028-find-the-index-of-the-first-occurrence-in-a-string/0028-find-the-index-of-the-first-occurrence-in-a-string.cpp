class Solution {
public:
    int strStr(string haystack, string needle) {
        // If needle is an empty string, return 0
        if (needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        // Iterate through the haystack, but only up to a point where the remaining part is at least as long as the needle
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            // Check if the substring of haystack starting at i matches the needle
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we matched the entire needle, return the starting index i
            if (j == m) {
                return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
