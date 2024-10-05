class Solution {
public:
    int lengthOfLastWord(string s) {
        /**if(s.size()==NULL){
            return 0;
        }
        istringstream stream(s);
        while(stream>>s){
            s.length();
        }
    return s.length();**/
        if(s.size()==NULL){
            return 0;
        }
        istringstream stream(s);
        while(stream>>s){
            s.length();
        }
        return s.length();
    }
};