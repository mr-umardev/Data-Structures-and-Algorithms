1class Solution {
2public:
3    int binaryGap(unsigned n) {
4        int d=0, p=32;
5        for(; n>0; n&=(n-1)){
6            int ctz=countr_zero(n);
7            d=max(d, ctz-p);
8            p=ctz;
9        }
10        return d;
11    }
12};