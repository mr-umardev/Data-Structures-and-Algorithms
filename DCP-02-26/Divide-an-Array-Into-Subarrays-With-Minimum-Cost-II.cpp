1//pmr multiset version
2#include <memory_resource>
3class Solution {
4    long long Sum=0;
5    std::pmr::unsynchronized_pool_resource pool;
6    //Define the multisets using the PMR namespace
7    std::pmr::multiset<int> small{&pool};
8    std::pmr::multiset<int> large{&pool};
9
10    void add(int x, int m) {
11        small.insert(x);
12        Sum+=x;
13        if (small.size()>m) {// small should have at most m elements
14            int toMove=*small.rbegin();
15            Sum-=toMove;
16            large.insert(toMove);
17            small.erase(prev(small.end()));
18        }
19    }
20
21    void remove(int x) {
22        auto it=small.find(x);
23        if (it!=small.end()) {
24            Sum-=x;
25            small.erase(it);
26            if (!large.empty()) {
27                auto lit=large.begin(); // Use iterator 
28                int toMove=*lit;
29                Sum+=toMove;
30                small.insert(toMove);
31                large.erase(lit); // removal by iterator
32            }
33        } 
34        else {
35            auto itL=large.find(x);
36            large.erase(itL); //remove
37        }
38    }
39
40public:
41    long long minimumCost(vector<int>& nums, int k, int dist) {
42        const int n=nums.size();
43        k--; // Need k-1 more elements after nums[0]
44
45        // Initialize the first window [1, dist+1]
46        const int iN=dist+2;
47        vector<int> win(nums.begin()+1, nums.begin()+iN);
48    
49        // initialize small & large in linear time
50        // the (k-1)-th smallest element at its sorted position
51        nth_element(win.begin(), win.begin()+k, win.end());// O(dist+2)
52        small.insert(win.begin(), win.begin() + k);
53        Sum=accumulate(win.begin(), win.begin()+k, 0LL);
54        large.insert(win.begin()+k, win.end());
55    
56        long long minCost=nums[0]+Sum;
57
58        // Slide the window starting from index 1.
59        // Elements in window nums[l...r]
60        for (int l=1, r=dist+2; r<n; l++, r++) {
61            remove(nums[l]);
62            add(nums[r], k);
63
64            // Update the minCost
65            minCost=min(minCost, nums[0]+Sum);
66        }
67        return minCost;
68    }
69};