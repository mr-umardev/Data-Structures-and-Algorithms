class Solution {
public:
    int minAddToMakeValid(string& s) {
        int l=0, r=0;
        for (char c: s){
            bool isLeft=(c=='(');
            l+=isLeft;
            (l>0)?l-=(!isLeft):r+=(!isLeft);
        }
        return l+r;
    }
};