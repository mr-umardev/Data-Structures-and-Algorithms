class Solution {
public:
    int findComplement(int num) {
       // Handle the edge case for 0 explicitly
    if (num == 0) return 1;
    
    // Initialize mask to the highest bit set in num
    unsigned int mask = ~0;
    
    // Shift the mask to the right until it matches the length of num
    while (num & mask) {
        mask <<= 1;
    }
    
    // XOR num with the inverse of the mask to flip all the bits
    return ~num & ~mask;
    }
};