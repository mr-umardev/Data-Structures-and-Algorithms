1#define ll long long
2class Solution {
3public:
4    int minRemoval(vector<int>& nums, int k) {
5        int n=nums.size();
6        if(n<=1){
7            return 0;
8        }
9        sort(nums.begin(),nums.end());
10        int maxlength=0,left=0;
11        for(int right=0;right<n;++right){
12            while(nums[right]>(ll)k*nums[left]){
13                left++;
14            }
15            maxlength=max(maxlength,right-left+1);
16        }
17        return n-maxlength;
18    }
19};