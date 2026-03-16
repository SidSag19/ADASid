#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findSet(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findSet(parent[i]); 
    }

    void unite(int u, int v) {
        int root_u = findSet(u);
        int root_v = findSet(v);

        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

bool hasCycle(int V, const vector<pair<int, int>>& edges) {
    DSU dsu(V);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        if (dsu.findSet(u) != dsu.findSet(v)) {
            dsu.unite(u, v);
        } else {
            cout << "Cycle detected at edge (" << u << ", " << v << ")\n";
            return true; 
        }
    }
    
    return false;
}

int main() {
    int V = 4;

    cout << "--- Graph 1 ---" << endl;
    vector<pair<int, int>> edges1 = {
        {0, 1}, 
        {1, 2}, 
        {2, 0},
        {2, 3}
    };

    if (hasCycle(V, edges1)) {
        cout << "Result: Graph 1 contains a cycle.\n\n";
    } else {
        cout << "Result: Graph 1 does not contain a cycle.\n\n";
    }

    cout << "--- Graph 2 ---" << endl;
    vector<pair<int, int>> edges2 = {
        {0, 1}, 
        {1, 2}, 
        {2, 3}
    };

    if (hasCycle(V, edges2)) {
        cout << "Result: Graph 2 contains a cycle.\n";
    } else {
        cout << "Result: Graph 2 does not contain a cycle.\n";
    }

    return 0;
}