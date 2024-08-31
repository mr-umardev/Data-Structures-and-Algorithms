class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of indices
    vector<int> indices(heights.size());
    for (int i = 0; i < heights.size(); ++i) {
        indices[i] = i;
    }

    // Sort indices based on corresponding heights in descending order
    sort(indices.begin(), indices.end(), [&heights](int a, int b) {
        return heights[a] > heights[b];
    });

    // Create a result vector for sorted names
    vector<string> sortedNames;
    sortedNames.reserve(names.size());

    // Populate sortedNames based on sorted indices
    for (int index : indices) {
        sortedNames.push_back(names[index]);
    }

    return sortedNames;
    }
};