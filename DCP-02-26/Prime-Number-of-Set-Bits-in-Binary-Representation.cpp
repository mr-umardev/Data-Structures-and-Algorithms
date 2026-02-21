1/*
2There is a combinatorial formula for computing 
3#{x <N| x is natural number with bitcount(x)=k} =
4\sum_{i=0}^k C(p[i], k-i)
5where p[i]=position for i-th 1 in N's binary expression.
6*/
7
8int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};
9int C[21][21] = {0};
10
11class Solution {
12public:
13    void PascalTriangle(int n) {
14        for (int i = 0; i <= n; i++) {
15            fill(C[i], C[i] + (i + 1), 1);
16            for (int j = 1; j <= i / 2; j++) {
17                C[i][i-j] = C[i][j] = C[i-1][j-1] + C[i-1][j];
18            }
19        }
20    }
21
22    vector<int> N2p(int N) {
23        bitset<21> bN(N);
24        vector<int> p;
25        for (int i=20; i >= 0; i--) {
26            if (bN[i]) p.push_back(i);
27        }
28        return p;
29    }
30
31    int nums_bitcount(vector<int>& p, int k) {
32        int sum = 0;
33        for (int i = 0; i < p.size(); i++) {
34            int maxIndex = min(p[i], k-i);
35            if (maxIndex >= 0) {
36                sum += C[p[i]][k-i];
37            }
38        }
39        return sum;
40    }
41
42    int nums_bitcount_isPrime(int N) {
43        vector<int> p = N2p(N);
44        int sum = 0;
45        for (int k : prime) {
46            sum += nums_bitcount(p, k);
47        }
48        return sum;
49    }
50
51    int countPrimeSetBits(int left, int right) {
52        int L = log2(right+1) + 1;
53        PascalTriangle(L);
54        return nums_bitcount_isPrime(right+1)-nums_bitcount_isPrime(left);
55    }
56};