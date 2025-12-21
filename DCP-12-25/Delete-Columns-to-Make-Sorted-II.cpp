1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n=strs.size(), m=strs[0].size();
5        bitset<100> isSorted=0, remove=0;
6        for (int j=0; j<m; j++) {
7            for (int i=0; i<n-1; i++) {
8                if (isSorted[i]==0 & strs[i][j]>strs[i+1][j]) {
9                    remove[j]=1;
10                    break;
11                }
12            }
13
14            if (remove[j]) continue;
15            
16            for (int i=0; i<n-1; i++) 
17                isSorted[i]=isSorted[i]|(strs[i][j]<strs[i+1][j]);
18        }
19        return remove.count();
20    }
21};