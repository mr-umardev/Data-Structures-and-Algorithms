1#define ll long long
2class Solution {
3public:
4    int minCost(int n, vector<vector<int>>& edges) {
5        vector<vector<pair<int,int>>>ans(n);
6        for(const auto& edge: edges){
7            int u=edge[0];
8            int v=edge[1];
9            int w=edge[2];
10            ans[u].push_back({v,w});
11            ans[v].push_back({u,2*w});
12        }
13        vector<ll>distance(n,std::numeric_limits<ll>::max());
14        distance[0]=0;
15        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pqueue;
16        pqueue.push({0,0});
17        while(!pqueue.empty()){
18            auto [current_cost, u] = pqueue.top();
19            pqueue.pop();
20
21            if (current_cost > distance[u]) {
22                continue;
23            }
24
25            for (const auto& neighbor : ans[u]) {
26                int v = neighbor.first;
27                int weight = neighbor.second;
28
29                if (distance[u] + weight < distance[v]) {
30                    distance[v] = distance[u] + weight;
31                    pqueue.push({distance[v], v});
32                }
33            }
34        }
35        if (distance[n - 1] == numeric_limits<ll>::max()) {
36            return -1;
37        }
38
39        return distance[n - 1];
40        }
41};