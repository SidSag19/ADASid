#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int parent, vector<bool>& visited, const vector<vector<int>>& adj) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj)) {
                return true; 
            }
        } 
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 4;

    cout << "--- Graph 1 ---" << endl;
    vector<vector<int>> adj1(V);
    adj1[0] = {1, 2};
    adj1[1] = {0, 2};
    adj1[2] = {0, 1, 3};
    adj1[3] = {2};

    if (hasCycle(V, adj1)) {
        cout << "Result: Graph 1 contains a cycle.\n\n";
    } else {
        cout << "Result: Graph 1 does not contain a cycle.\n\n";
    }

    cout << "--- Graph 2 ---" << endl;
    vector<vector<int>> adj2(V);
    adj2[0] = {1};
    adj2[1] = {0, 2};
    adj2[2] = {1, 3};
    adj2[3] = {2};

    if (hasCycle(V, adj2)) {
        cout << "Result: Graph 2 contains a cycle.\n";
    } else {
        cout << "Result: Graph 2 does not contain a cycle.\n";
    }

    return 0;
}