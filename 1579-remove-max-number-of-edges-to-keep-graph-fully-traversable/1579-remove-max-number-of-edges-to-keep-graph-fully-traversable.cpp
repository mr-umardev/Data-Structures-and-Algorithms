class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<int> parentAlice(n + 1), parentBob(n + 1), rankAlice(n + 1, 1), rankBob(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        parentAlice[i] = i;
        parentBob[i] = i;
    }
    
    function<int(vector<int>&, int)> find = [&](vector<int>& parent, int u) {
        if (parent[u] != u) parent[u] = find(parent, parent[u]);
        return parent[u];
    };
    
    auto unionSets = [&](vector<int>& parent, vector<int>& rank, int u, int v) {
        int pu = find(parent, u), pv = find(parent, v);
        if (pu == pv) return false;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    };
    
    int removedEdges = 0;
    int edgesUsedAlice = 0, edgesUsedBob = 0;

    // Type 3 edges (usable by both Alice and Bob)
    for (const auto& edge : edges) {
        if (edge[0] == 3) {
            bool aliceUnion = unionSets(parentAlice, rankAlice, edge[1], edge[2]);
            bool bobUnion = unionSets(parentBob, rankBob, edge[1], edge[2]);
            if (aliceUnion) edgesUsedAlice++;
            if (bobUnion) edgesUsedBob++;
            if (!aliceUnion && !bobUnion) removedEdges++;
        }
    }

    // Type 1 edges (usable by Alice only)
    for (const auto& edge : edges) {
        if (edge[0] == 1) {
            if (unionSets(parentAlice, rankAlice, edge[1], edge[2])) {
                edgesUsedAlice++;
            } else {
                removedEdges++;
            }
        }
    }

    // Type 2 edges (usable by Bob only)
    for (const auto& edge : edges) {
        if (edge[0] == 2) {
            if (unionSets(parentBob, rankBob, edge[1], edge[2])) {
                edgesUsedBob++;
            } else {
                removedEdges++;
            }
        }
    }

    // Check if both Alice and Bob can traverse the entire graph
    if (edgesUsedAlice != n - 1 || edgesUsedBob != n - 1) return -1;
    return removedEdges;
}
};

