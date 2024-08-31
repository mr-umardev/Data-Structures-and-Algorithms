class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    long miss = 1; 
    int i = 0, patches = 0;
    int size = nums.size();

    while (miss <= n) {
        if (i < size && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            miss += miss;
            patches++;
        }
    }

    return patches;
}
};