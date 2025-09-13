class Solution {
public:
    int maxFreqSum(string s) {
        int maxvowels=0,maxconsonants=0;
        unordered_map<char,int>map;
        for(int i=0;i<s.length();++i){
            map[s[i]]++;
        }
        for(auto& it: map){
            if(it.first=='a' || it.first=='e' || it.first=='i' || it.first=='o' || it.first=='u'){
                maxvowels=max(maxvowels,it.second);
            }else{
                maxconsonants=max(maxconsonants,it.second);
            }
        }
        return maxvowels+maxconsonants;
    }
};