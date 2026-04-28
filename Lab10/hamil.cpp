#include <iostream>

using namespace std;

const int MAX_NODES = 10;

bool isSafe(int v, const int graph[MAX_NODES][MAX_NODES], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool hamil(const int graph[MAX_NODES][MAX_NODES], int path[], int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            path[pos] = path[0]; 
            return true;
        }
        return false;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamil(graph, path, pos + 1, n)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    int n = 5; 

    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int path[MAX_NODES + 1]; 
    for (int i = 0; i <= n; i++) {
        path[i] = -1;
    }

    path[0] = 0; 

    if (hamil(graph, path, 1, n)) {
        for (int i = 0; i <= n; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "No Hamiltonian Cycle found\n";
    }

    return 0;
}