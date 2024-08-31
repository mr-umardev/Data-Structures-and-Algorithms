class Solution {
public:
string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;  // Initialize the result as 0/1
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;  // Default sign is positive

            // Check for '+' or '-' sign at the start of the fraction
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            // Parse the numerator
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;  // Apply the sign to the numerator

            i++;  // Skip the '/' character

            // Parse the denominator
            int den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            // Update the result fraction: (numerator/denominator) + (num/den)
            numerator = numerator * den + num * denominator;
            denominator *= den;

            // Simplify the fraction by dividing by the gcd of the numerator and denominator
            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        // Return the result as a string in the format "numerator/denominator"
        return to_string(numerator) + "/" + to_string(denominator);
    }
};