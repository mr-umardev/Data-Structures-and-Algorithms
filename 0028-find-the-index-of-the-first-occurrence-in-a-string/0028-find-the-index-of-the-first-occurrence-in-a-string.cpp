class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(needle.empty()){
            return 0;
        }
        for(int i=0;i<=n-m;++i){
            if(haystack.substr(i,needle.size())==needle){
                return i;
            }
        }
        return -1;
    }
};