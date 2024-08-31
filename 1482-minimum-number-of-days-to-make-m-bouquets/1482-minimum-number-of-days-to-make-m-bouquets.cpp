class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
     int n = bloomDay.size();
    if (static_cast<int64_t>(m) * static_cast<int64_t>(k) > static_cast<int64_t>(n)) return -1;  // Not enough flowers to make the required bouquets

    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if it's possible to make the required number of bouquets by 'mid' days
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) break;
        }

        if (bouquets >= m) {
            right = mid;  // Try for fewer days
        } else {
            left = mid + 1;  // Need more days
        }
    }
    return left;
}
};