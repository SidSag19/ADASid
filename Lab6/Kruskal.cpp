#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int u, v, weight;
    
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

bool isReachable(int curr, int target, vector<bool>& visited, const vector<vector<int>>& adj) {
    if (curr == target) return true; 
    
    visited[curr] = true;

    for (int neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            if (isReachable(neighbor, target, visited, adj)) {
                return true;
            }
        }
    }
    return false; 
}

void kruskalDFS(int V, const vector<Edge>& edges) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;
    for (const auto& edge : edges) {
        minHeap.push(edge);
    }

    vector<vector<int>> mstAdj(V); 
    vector<Edge> mst;
    int minCost = 0;

    while (!minHeap.empty() && mst.size() < V - 1) {
        Edge currentEdge = minHeap.top();
        minHeap.pop();

        vector<bool> visited(V, false);

        if (!isReachable(currentEdge.u, currentEdge.v, visited, mstAdj)) {
            mst.push_back(currentEdge);
            minCost += currentEdge.weight;
            
            mstAdj[currentEdge.u].push_back(currentEdge.v);
            mstAdj[currentEdge.v].push_back(currentEdge.u);
        }
    }

    cout << "Edges in the Minimum Spanning Tree (MST):\n";
    cout << "-----------------------------------------\n";
    for (const auto& edge : mst) {
        cout << "Edge: " << edge.u << " - " << edge.v << " \tCost: " << edge.weight << "\n";
    }
    cout << "-----------------------------------------\n";
    cout << "Total Minimum Cost: " << minCost << "\n";
}

int main() {
    int V = 6; 
    
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

    kruskalDFS(V, edges);

    return 0;
}