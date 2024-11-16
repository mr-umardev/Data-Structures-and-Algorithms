#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) ++left;

            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) --right;

            // Compare characters case-insensitively
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move pointers inward
            ++left;
            --right;
        }
        return true;
    }
};
