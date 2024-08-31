class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            long long jSquared = c - i * i;
            long long j = static_cast<long long>(sqrt(jSquared));
            if (j * j == jSquared) {
                return true;
            }
        }
        return false;
    }
};