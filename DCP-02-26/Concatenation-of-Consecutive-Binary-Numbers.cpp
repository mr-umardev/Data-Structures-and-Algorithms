1class Solution {
2public:
3    int concatenatedBinary(int n) {
4        int shifter = 1;
5        int val = 1;
6        long long answer = 0;
7        int mod = 1'000'000'007;
8        
9        for(int a = 1; a <= n; a++){
10            if(val * 2 == a){
11                shifter++;
12                val = a;
13            }
14            answer = ((answer << shifter) | a) % mod;
15        }
16        
17        return answer;
18    }
19};