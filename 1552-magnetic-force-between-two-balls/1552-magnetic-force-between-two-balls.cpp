class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

    // Helper function to determine if we can place m balls with at least minDist distance apart
    auto canPlaceBalls = [](const vector<int>& position, int m, int minDist) {
        int count = 1; // Place the first ball in the first basket
        int lastPos = position[0]; // Position of the last placed ball

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                if (count == m) {
                    return true;
                }
            }
        }
        return false;
    };

    // Initialize binary search bounds
    int left = 1; // Minimum possible distance
    int right = position.back() - position[0]; // Maximum possible distance
    int result = 0;

    // Binary search to find the maximum minimum distance
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceBalls(position, m, mid)) {
            result = mid;
            left = mid + 1; // Try for a larger minimum distance
        } else {
            right = mid - 1; // Try for a smaller minimum distance
        }
    }

    return result;
    }
};