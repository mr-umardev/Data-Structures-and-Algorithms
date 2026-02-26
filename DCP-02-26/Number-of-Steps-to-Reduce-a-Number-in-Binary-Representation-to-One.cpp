1class Solution {
2public:
3    int numSteps(string& s) {
4        int n=s.size(), div=n-1, add1=0, carry=0, cnt1=0;
5        for(int i=n-1; i>0; i--){
6            while(i>0 && (s[i]-'0'+carry)&1){
7                carry|=s[i]=='1';
8                cnt1++;
9                i--;
10            }
11            add1+=cnt1;
12            cnt1=0;
13            carry|=s[i]=='1';
14        }
15        return div+add1+carry;
16    }
17};
18
19
20
21auto init = []() {
22    ios::sync_with_stdio(0);
23    cin.tie(0);
24    cout.tie(0);
25    return 'c';
26}();