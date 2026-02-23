1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        unordered_set<string> st;
5        for(int i=0;i+k<=s.size();++i){
6            st.insert(s.substr(i,k));
7        }
8        return st.size()==(int)pow(2,k);
9    }
10};