1class Solution {
2public:
3    bool hasAlternatingBits(unsigned n) {
4        bitset<32> B(n);
5        int mB=31-countl_zero(n);
6        bool prevB=1;
7        for(int i=mB-1; i>=0; i--, prevB=!prevB){
8            if (B[i]==prevB) return 0;
9        }
10        return 1;
11    }
12};