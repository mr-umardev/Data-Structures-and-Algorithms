class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        vector<string>nums;
        string str="";
        while(ss>>str){
            nums.push_back(str);
        }
        int count=0;
        for(string& word: nums){
            bool found=false;
            for(char c: word){
                if(brokenLetters.find(c)!=string::npos){
                    found=true;
                    break;
                }
            }
            if(!found){
                count+=1;
            }
        }
        return count;
    }
};