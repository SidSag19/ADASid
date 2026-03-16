#include <iostream>
#include <climits>

using namespace std;

#define I INT_MAX

struct g {
    int arr[8][8] = {0};

    void graph(int i, int j, int wt) {
        arr[i][j] = wt;
        arr[j][i] = wt; 
    }
    
    void display() {
        for (int i = 0; i <= 7; i++) {
            for (int j = 0; j <= 7; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

void prims(int cost[8][8], int n) {
    int mincost = 0;
    int min_val = I;
    int k = 0, l = 0;

    int t[2][7];
    int near[8];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min_val) {
                min_val = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[0][0] = k;
    t[1][0] = l;
    mincost += cost[k][l];

    for (int i = 0; i < n; i++) {
        if (i == k || i == l) continue;
        
        int c_ik = (cost[i][k] == 0) ? I : cost[i][k];
        int c_il = (cost[i][l] == 0) ? I : cost[i][l];

        if (c_ik < c_il) {
            near[i] = k;
        } else {
            near[i] = l;
        }
    }
    
    near[k] = -1; 
    near[l] = -1;

    for (int j = 1; j < n - 1; j++) {
        int u = -1;
        int min_edge = I;

        for (int i = 0; i < n; i++) {
            if (near[i] != -1) {
                int c_in = (cost[i][near[i]] == 0) ? I : cost[i][near[i]];
                if (c_in < min_edge) {
                    min_edge = c_in;
                    u = i;
                }
            }
        }

        t[0][j] = u;
        t[1][j] = near[u];
        mincost += cost[u][near[u]];
        
        near[u] = -1; 

        for (int i = 0; i < n; i++) {
            if (near[i] != -1) {
                int c_iu = (cost[i][u] == 0) ? I : cost[i][u];
                int c_in = (cost[i][near[i]] == 0) ? I : cost[i][near[i]];
                if (c_iu < c_in) {
                    near[i] = u;
                }
            }
        }
    }

    cout << "Minimum Spanning Tree Edges:\n";
    cout << "----------------------------\n";
    for (int i = 0; i < n - 1; i++) {
        cout << "Edge: " << t[0][i] << " - " << t[1][i] << " \tCost: " << cost[t[0][i]][t[1][i]] << "\n";
    }
    cout << "----------------------------\n";
    cout << "Total Minimum Cost: " << mincost << "\n";
}

int main() {
    g a;

    a.graph(0, 1, 4);
    a.graph(0, 2, 8);
    a.graph(1, 2, 9);
    a.graph(1, 3, 8);
    a.graph(1, 4, 10);
    a.graph(2, 3, 2);
    a.graph(2, 5, 1);
    a.graph(3, 4, 7);
    a.graph(3, 5, 9);
    a.graph(4, 5, 5);
    a.graph(4, 6, 6);
    a.graph(5, 7, 2);
    a.graph(6, 7, 1);
    a.graph(3, 6, 4);

    cout << "Adjacency Matrix:\n";
    a.display();
    cout << "\n";

    prims(a.arr, 8);

    return 0;
}