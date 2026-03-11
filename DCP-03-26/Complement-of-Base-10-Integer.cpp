1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        if(n == 0) return 1 ; 
5        int mask = (1 << (32 - __builtin_clz(n))) - 1; 
6        return n ^ mask ;
7    }
8};