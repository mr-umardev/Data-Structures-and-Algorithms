1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n=nums.size();
5        if(n<4){
6            return false;
7        }
8        for(int i=1;i<n-2;++i){
9            bool first=true;
10            for(int j=0;j<i;++j){
11                if(nums[j]>=nums[j+1]){
12                    first=false;
13                    break;
14                }
15            }
16            if(!first){
17                continue;
18            }
19            for(int k=i+1;k<n-1;++k){
20                bool second=true;
21                for(int h=i;h<k;++h){
22                    if(nums[h]<=nums[h+1]){
23                        second=false;
24                        break;
25                    }
26                }
27                if(!second){
28                    continue;
29                }
30                bool third=true;
31                for(int a=k;a<n-1;++a){
32                    if(nums[a]>=nums[a+1]){
33                        third=false;
34                        break;
35                    }
36                }
37                if(third){
38                    return true;
39                }
40            }
41        }
42        return false;
43    }
44};