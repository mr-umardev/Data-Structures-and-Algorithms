1double A[2][102];// as global variable
2class Solution {
3public:
4    double champagneTower(int poured, int query_row, int query_glass) {
5        if (poured==0) return 0;
6        // reset to 0 only for needs
7        memset(A[0], 0, (query_row+2)*sizeof(double));
8    
9        A[0][0]=poured; //poured
10        for(int i=0; i<query_row; i++){
11            // consider the parities for the current i & the next one
12            bool cur=i&1, nxt=!cur;
13            // clear the next row
14            memset(A[nxt], 0, (i+2)*sizeof(double));
15            for(int j=0; j<=i; j++){
16                double A_ij=A[cur][j];
17                if ( A_ij<=1) continue;
18                double excess=(A_ij-1)/2.0;
19                A[nxt][j]+=excess;
20                A[nxt][j+1]+=excess;
21            }
22        }
23        // query_row&1
24        return min(1.0, A[query_row&1][query_glass]);
25    }
26};