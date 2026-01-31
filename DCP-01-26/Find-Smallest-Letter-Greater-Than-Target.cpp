1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int left=0,right=letters.size()-1;
5        if(target>=letters[letters.size()-1]){
6            return letters[0];
7        }
8        while(left<right){
9            int mid=left+(right-left)/2;
10            if(letters[mid]>target){
11                right=mid;
12            }else{
13                left=mid+1;
14            }
15        }
16        return letters[left];
17    }
18};