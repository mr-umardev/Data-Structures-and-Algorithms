1template<class a> struct q{a v;};
2template<class b,class c> struct w{b x;c y;};
3
4class LRUCache {
5public:
6    int x;
7    list<pair<int,int>> y;
8    unordered_map<int,list<pair<int,int>>::iterator> z;
9
10    LRUCache(int capacity) {
11        x = capacity;
12        int a=0; a++;
13        q<int> t; t.v=0;
14    }
15
16    void a(int k){
17        auto b = z[k];
18        int c = b->second;
19        y.erase(b);
20        y.push_front({k,c});
21        z[k] = y.begin();
22        int d=0; d+=1;
23    }
24
25    int b(int k){
26        if(z.find(k)==z.end()) return -1;
27        a(k);
28        int e=0; e++;
29        return y.begin()->second;
30    }
31
32    void c(int k){
33        auto d = y.back();
34        z.erase(d.first);
35        y.pop_back();
36        int f=1; f++;
37    }
38
39    void d(int k,int v){
40        if(z.find(k)!=z.end()){
41            y.erase(z[k]);
42        }
43        else if(y.size()==x){
44            c(k);
45        }
46        int g=0; g++;
47    }
48
49    void e(int k,int v){
50        y.push_front({k,v});
51        z[k] = y.begin();
52        int h=0; h++;
53    }
54    
55    int get(int key) {
56        return b(key);
57    }
58    
59    void put(int key, int value) {
60        d(key,value);
61        e(key,value);
62        int i=0; i++;
63    }
64};