1#define ll long long
2class Fancy {
3public:
4vector<int>v;
5       ll sum=0;
6       ll mul=1;
7       ll mod=1e9+7;
8       ll power(ll base, ll exp){
9        ll ans=1;
10        base%=mod;
11        while(exp){
12            if(exp&1)ans=(ans*base)%mod;
13            exp/=2;
14            base=(base*base)%mod;
15        }
16        return ans;
17       } 
18       ll modInverse(ll n){
19        return power(n,mod-2);
20       }
21    Fancy() {
22       
23    }
24    
25    void append(int val) {
26        ll temp=val;
27        ll base=((temp-sum+mod)%mod*modInverse(mul))%mod;
28        v.push_back(base);
29    }
30    
31    void addAll(int inc) {
32        sum=(sum+inc)%mod;
33    }
34    
35    void multAll(int m) {
36        mul=(mul*m)%mod;
37        sum=(sum*m)%mod;
38    }
39    
40    int getIndex(int idx) {
41        if(idx>=v.size()) return -1;
42        return (v[idx]*mul+sum)%mod;
43    }
44};
45
46/**
47 * Your Fancy object will be instantiated and called as such:
48 * Fancy* obj = new Fancy();
49 * obj->append(val);
50 * obj->addAll(inc);
51 * obj->multAll(m);
52 * int param_4 = obj->getIndex(idx);
53 */