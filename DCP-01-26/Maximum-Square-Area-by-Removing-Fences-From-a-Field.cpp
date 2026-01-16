1class Solution {
2public:
3    static constexpr int mod=1e9+7;
4    vector<int> seen;
5    int maxL=0;
6    void findLen(vector<int>& fences, int sz, bool calM){
7        sort(fences.begin(), fences.end());
8        for (int l=0; l<sz-1; l++){
9            int L=fences[l];
10            for (int r=l+1; r<sz; r++){
11                int Len=fences[r]-L;
12             //   cout<<Len<<"; ";
13                if (calM){
14                    if(Len>maxL && binary_search(seen.begin(), seen.end(),Len)) maxL=Len;
15                }
16                else seen.push_back(Len);
17            }
18        }
19    }
20    
21    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
22        const int hz=hFences.size()+2,
23        vz=vFences.size()+2;
24        if (hz>vz)
25           return maximizeSquareArea(n, m, vFences, hFences);
26        hFences.push_back(1);
27        hFences.push_back(m);
28        vFences.push_back(1);
29        vFences.push_back(n);
30        seen.reserve(hz*(hz-1));
31        findLen(hFences, hz, 0);
32
33        // for binary search version only
34        sort(seen.begin(), seen.end());
35        seen.erase(unique(seen.begin(), seen.end()), seen.end());
36
37        findLen( vFences,  vz, 1);
38        return (maxL==0)?-1:(long long)maxL*maxL%mod;
39    }
40};