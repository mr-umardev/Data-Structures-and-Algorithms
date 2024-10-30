class Solution {
public:
    int n;
    void print(vector<int> nums){
        for(int x: nums)
            cout<<x<<", ";
        cout<<endl;
    }
    vector<int> dp;
    inline void LIS(vector<int>& nums) 
    {
        vector<int> L;
        for (int i = 0; i<n; i++) {
            int x=nums[i];
            auto it=lower_bound(L.begin(), L.end(), x);
            if (it==L.end()) L.push_back(x);
            else *it=x;
        //    print(L);
            dp[i]=L.size();
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        if (n <= 3) {
            return 0; // There can't be a mountain with less than 3 elements
        }
        dp.assign(n, 0);

        LIS(nums);
        vector<int> R;
    //    print(dp);
    //    cout<<"\n-----\n";
        int ans=n;
        for (int i=n-1; i>0; i--) {
            int x=nums[i];
            auto it=lower_bound(R.begin(), R.end(), x);
            if (it==R.end()) R.push_back(x);
            else *it=x;
            
        //    print(R);
            if (dp[i]>1 && R.size()>1)
                ans=min(ans, n+1-dp[i]-(int)R.size());
        }
        return ans; 
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();