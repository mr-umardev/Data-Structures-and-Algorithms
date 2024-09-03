class Solution {
public:
    int getLucky(string s, int k) {
       int sum = 0;

        // Step 1: Convert each character in the string to the corresponding number
        for (char ch : s) {
            int n = 0;
            if (ch >= 'a' && ch <= 'z') {
                n = ch - 'a' + 1;  // Convert lowercase to 1-based index
            } else if (ch >= 'A' && ch <= 'Z') {
                n = ch - 'A' + 1;  // Convert uppercase to 1-based index
            }

            // Add the digits of the number to sum
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
        }

        // Step 2: Perform k-1 transformations by summing the digits of sum
        for (int i = 1; i < k; ++i) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }

        return sum;
    }
};