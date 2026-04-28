#include <iostream>

using namespace std;

const int MAX_NODES = 10;

bool isSafe(int v, const int graph[MAX_NODES][MAX_NODES], int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoring(const int graph[MAX_NODES][MAX_NODES], int m, int color[], int v, int n) {
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            
            if (graphColoring(graph, m, color, v + 1, n)) {
                return true;
            }
            
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n = 4; 
    
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int color[MAX_NODES];
    int minColors = 1; 

    while (true) {
        for (int i = 0; i < MAX_NODES; i++) {
            color[i] = 0;
        }
        
        if (graphColoring(graph, minColors, color, 0, n)) {
            cout << "Minimum number of colors required: " << minColors << "\n\n";
            
            cout << "Color assignments for nodes:\n";
            for (int i = 0; i < n; i++) {
                cout << "Node " << i << " -> Color " << color[i] << "\n";
            }
            break; 
        }
        minColors++; 
    }

    return 0;
}