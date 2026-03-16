#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    
    // Operator overloading for the priority queue to act as a Min-Heap
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

// Disjoint Set Union (DSU) Data Structure for Cycle Detection
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

// Kruskal's Algorithm implementation
void kruskal(int V, const vector<Edge>& edges) {
    // 1. Initialize Min-Heap and push all edges into it
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    for (const auto& edge : edges) {
        minHeap.push(edge);
    }

    DSU dsu(V);
    vector<Edge> mst;
    int minCost = 0;

    // 2. Extract edges from Min-Heap until we have V-1 edges in our MST
    while (!minHeap.empty() && mst.size() < V - 1) {
        // Get the edge with the minimum weight
        Edge currentEdge = minHeap.top();
        minHeap.pop();

        // 3. Cycle Detection: Check if adding this edge forms a cycle
        if (dsu.findSet(currentEdge.u) != dsu.findSet(currentEdge.v)) {
            // No cycle formed, include it in the MST
            mst.push_back(currentEdge);
            minCost += currentEdge.weight;
            
            // Union the two sets
            dsu.unite(currentEdge.u, currentEdge.v);
        }
    }

    // Output the resulting Minimum Spanning Tree
    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    cout << "-----------------------------------------\n";
    for (const auto& edge : mst) {
        cout << "Edge: " << edge.u << " - " << edge.v << " \tCost: " << edge.weight << "\n";
    }
    cout << "-----------------------------------------\n";
    cout << "Total Minimum Cost: " << minCost << "\n";
}

int main() {
    int V = 6; // Number of vertices (0 to 5)
    
    // Sample Graph Edges {u, v, weight}
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 5},
        {2, 4, 9},
        {3, 4, 7},
        {3, 5, 2},
        {4, 5, 8}
    };

    kruskal(V, edges);

    return 0;
}