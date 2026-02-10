1constexpr int N=1e5+1;
2short freq[N]={0};
3class Solution {
4public:
5    static int longestBalanced(vector<int>& nums) {
6        const int n=nums.size();
7        int len=0;
8        for(int l=0; l<n; l++){
9            int cnt[2]={0};
10            for(int r=l; r<n; r++){
11                const int x=nums[r];
12                if (++freq[x]==1) cnt[x&1]++;
13                if (cnt[0]==cnt[1])
14                    len=max(len, r-l+1);
15            }
16            for(int i=l; i<n; i++) freq[nums[i]]=0;
17        }
18        return len;
19    }
20};