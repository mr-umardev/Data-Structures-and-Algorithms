1// faster variant
2#include <memory_resource>
3pmr::unsynchronized_pool_resource pool;
4class Solution {
5public:
6    static int has1(string& s, int n){
7        int cnt=1, len=1;
8        for(int i=1; i<n; i++){
9            if (s[i]==s[i-1]) len++;
10            else {
11                cnt=max(cnt, len);
12                len=1;
13            }
14        }
15        return max(cnt, len);
16    }
17
18    static constexpr long long bias=1<<18, shift=32;
19    inline static long long pack(int x, int y){
20        // Deal with negative int
21        return ((long long)(x+bias)<<shift)|(long long)(y+bias);
22    }
23
24    static int longestBalanced(string& s) {
25        const int n=s.size();
26        int ans=has1(s, n);
27
28        pmr::unordered_map<long long, int> ab(&pool), bc(&pool), ca(&pool), abc(&pool);
29        
30        ab.reserve(n), bc.reserve(n), ca.reserve(n), abc.reserve(n);
31        // INITIAL STATE: Differences at index -1
32        abc[pack(0, 0)]=-1;
33        ab[pack(0, 0)]=-1; // (A-B, C)
34        bc[pack(0, 0)]=-1; // (B-C, A)
35        ca[pack(0, 0)]=-1; // (C-A, B)
36    
37        array<int, 3> cnt={0};
38        for(int i=0; i<n; i++){
39            cnt[s[i]-'a']++; 
40            const auto [A, B, C]=cnt;
41
42            // 3-letter balance: A=B=C
43            long long key=pack(B-A, C-A);
44            auto it=abc.find(key);// find once 
45            if(it!=abc.end()) ans=max(ans, i-it->second);
46            else abc[key]=i;
47
48            // 2-letter balance: A=B and NO C
49            key=pack(A-B, C);
50            it=ab.find(key);
51            if(it!=ab.end()) ans = max(ans, i-it->second);
52            else ab[key]=i;
53
54            // 2-letter balance: B=C and NO A
55            key=pack(B-C, A);
56            it=bc.find(key);
57            if(it!=bc.end()) ans=max(ans, i-it->second);
58            else bc[key]=i;
59
60            // 2-letter balance: C=A and NO B
61            key=pack(C-A, B);
62            it=ca.find(key);
63            if(it!=ca.end()) ans=max(ans, i-it->second);
64            else ca[key]=i;
65        }
66        
67        return ans;
68    }
69};