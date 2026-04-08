#include <iostream>
using namespace std;
#define lar 100000 

struct g {
    int arr[20][20] = {0};
    int n; 

    void graph(int i, int j, int wt) {
        arr[i][j] = wt;
    }
    
    void display() {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void del(int i, int j) {
        arr[i][j] = 0;
    }

    void count(int arr[20][20], int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 0) {
                    count++;
                    i=j;
                }
            }
        }
        cout << "Total number of stages: " << count+1 << endl;
    }

    void FMG(int n, int k) {
        int mcost[20];
        int d[20];
        int p[20];
        mcost[n - 1] = 0;

        for (int j = n - 2; j >= 0; j--) {
            int min_cost = lar;
            int min_r = -1;
            for (int r = j + 1; r < n; r++) {
                if (arr[j][r] != 0) {
                    if (arr[j][r] + mcost[r] < min_cost) {
                        min_cost = arr[j][r] + mcost[r];
                        min_r = r;
                    }
                }
            }
            mcost[j] = min_cost;
            d[j] = min_r;
        }
        p[1] = 0;
        p[k] = n - 1;

        for (int j = 2; j <= k - 1; j++) {
            p[j] = d[p[j - 1]];
        }
        cout << "\nMinimum Cost: " << mcost[0] << endl;
        cout << "Path: ";
        for (int i = 1; i <= k; i++) {
            cout << p[i];
            if (i < k) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    g a;
    a.graph(0,1,1);
    a.graph(0,2,7);
    a.graph(0,3,6);
    a.graph(1,4,2);
    a.graph(2,4,8);
    a.graph(2,5,9);
    a.graph(3,5,5);
    a.graph(4,6,3);
    a.graph(5,6,4);

    cout << "Adjacency Matrix:\n";
    a.display();    
    a.count(a.arr, 7);
    a.FMG(7, 4);
    return 0;
}