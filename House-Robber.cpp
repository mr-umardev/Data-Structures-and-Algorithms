class Solution {
public:
int solve(int ind,vector<int>& dp,vector<int>& nums){
    if(ind<0){
        return 0;
    }
    if(ind==0){
        return nums[0];
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
        int rob=nums[ind]+solve(ind-2,dp,nums);
        int minmoney=solve(ind-1,dp,nums);
    return dp[ind]=max(rob,minmoney);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};