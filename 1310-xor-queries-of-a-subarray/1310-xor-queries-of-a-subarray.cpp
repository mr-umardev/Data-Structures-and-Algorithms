class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
    vector<int> prefixXor(n);
    vector<int> result;
    prefixXor[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }
    for (const auto& query : queries) {
        int left = query[0];
        int right = query[1];
        
        if (left == 0) {
            result.push_back(prefixXor[right]);
        } else {
            result.push_back(prefixXor[right] ^ prefixXor[left - 1]);
        }
    }
    
    return result;
    }
};