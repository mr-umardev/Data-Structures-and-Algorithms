class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int perimeter=0,maxperimeter=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;++i){
            if(nums[i+1]+nums[i+2]>nums[i]){
                perimeter=nums[i]+nums[i+1]+nums[i+2];
                maxperimeter=max(maxperimeter,perimeter);
            }
        }
        return maxperimeter;
    }
};