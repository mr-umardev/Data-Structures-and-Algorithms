class Solution {
public:
    int maxArea(vector<int>& height) {
         int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the current area
        int width = right - left;
        int current_area = std::min(height[left], height[right]) * width;

        // Update the maximum area if the current area is larger
        max_area = std::max(max_area, current_area);

        // Move the pointer that points to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;

    }
};