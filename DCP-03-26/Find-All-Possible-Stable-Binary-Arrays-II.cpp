1class Solution {
2public:
3    const int N=1e9+7;
4    int dp[1001][1001][2];
5    int numberOfStableArrays(int zero, int one, int limit) {
6        for(int i=0;i<=min(limit,max(one,zero));i++){
7            dp[i][0][0]=dp[0][i][1]=1;
8        }
9        for(int i=1;i<=zero;i++){
10            for(int j=1;j<=one;j++){
11                dp[i][j][0]=((long long)dp[i-1][j][0]+dp[i-1][j][1])%N;
12                dp[i][j][1]=((long long)dp[i][j-1][1]+dp[i][j-1][0])%N;
13                
14                if(i-1-limit>=0) dp[i][j][0]=dp[i][j][0]-dp[i-1-limit][j][1];
15                if(j-1-limit>=0) dp[i][j][1]=dp[i][j][1]-dp[i][j-1-limit][0];
16                if(dp[i][j][0]<0) dp[i][j][0]+=N;
17                if(dp[i][j][1]<0) dp[i][j][1]+=N;
18            }
19        }
20        return ((long long)dp[zero][one][1]+dp[zero][one][0])%N;
21    }
22};