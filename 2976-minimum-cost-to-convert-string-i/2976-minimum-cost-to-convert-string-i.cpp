class Solution {
public:
   const int INF = INT_MAX / 2; // Define infinity as half of INT_MAX to prevent overflow

void floydWarshall(vector<vector<long long>>& costMatrix, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (costMatrix[i][k] < INF && costMatrix[k][j] < INF) {
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }
    }
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int n = 26; // Number of letters in the alphabet
    vector<vector<long long>> costMatrix(n, vector<long long>(n, INF));

    // Initialize the cost matrix
    for (int i = 0; i < n; ++i) {
        costMatrix[i][i] = 0; // Cost to change a character to itself is zero
    }

    for (size_t i = 0; i < original.size(); ++i) {
        costMatrix[original[i] - 'a'][changed[i] - 'a'] = min(costMatrix[original[i] - 'a'][changed[i] - 'a'], static_cast<long long>(cost[i]));
    }

    // Apply Floyd-Warshall to find all-pairs shortest paths
    floydWarshall(costMatrix, n);

    long long totalCost = 0;
    for (size_t i = 0; i < source.size(); ++i) {
        int srcChar = source[i] - 'a';
        int tgtChar = target[i] - 'a';
        if (costMatrix[srcChar][tgtChar] == INF) {
            return -1; // If it's impossible to convert one of the characters
        }
        totalCost += costMatrix[srcChar][tgtChar];
    }

    return totalCost;
}

};