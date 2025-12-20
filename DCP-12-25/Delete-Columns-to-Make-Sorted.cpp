1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        const int n=strs.size(), m=strs[0].size();
5        int cnt=0;
6        for(int j=0; j<m; j++){
7            for (int i=0; i<n-1; i++){
8                if(strs[i][j]>strs[i+1][j]){
9                    cnt++;
10                    break;
11                }
12            }
13        }
14        return cnt;
15    }
16};