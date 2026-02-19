1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        vector<int>nums;
5        int count=1;
6        for(int i=1;i<s.length();++i){
7            if(s[i]!=s[i-1]){
8                nums.push_back(count);
9                count=1;
10            }else{
11                count++;
12            }
13        }
14        nums.push_back(count);
15        int ans=0;
16        for(int i=1;i<nums.size();++i){
17            ans+=min(nums[i],nums[i-1]);
18        }
19        return ans;
20    }
21};