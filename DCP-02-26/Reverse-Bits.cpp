1class Solution {
2public:
3    uint32_t reverseBits(uint32_t n) {
4        bitset<32> B(n);
5        for(int i=0; i<16; i++){
6            B[i]=B[i]^B[31-i];
7            B[31-i]=B[i]^B[31-i];
8            B[i]=B[i]^B[31-i];
9        }     
10        return B.to_ulong();
11    }
12};