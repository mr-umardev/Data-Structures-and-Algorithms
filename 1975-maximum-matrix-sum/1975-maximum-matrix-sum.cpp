class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minValue1 = INT_MAX;
        long long sum1 = 0;
        int negCount1 = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0)
                    negCount1++;
                int absValue = abs(matrix[i][j]);
                minValue1 = min(minValue1, absValue);
                sum1 += absValue;
            }
        }

        if (negCount1 % 2 == 0)
            return sum1;
        return sum1 - 2 * minValue1;
    }
};