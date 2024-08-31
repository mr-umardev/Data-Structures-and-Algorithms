class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>s(nums.size());
        int element,sum=0;
        cout<<"nums=";
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            s[i]=sum;
         
        }
   return s;
    }
};