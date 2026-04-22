#include <iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono; 

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
        cout << "Total number of stages: " << count+1 << endl;}

    void FMG_Forward(int n, int k, bool print_output = true) {
        int mcost[20];
        int d[20];
        int p[20];
        
        mcost[0] = 0;

        for (int j = 1; j < n; j++) {
            int min_cost = lar;
            int min_predecessor = -1;
            
            for (int i = 0; i < j; i++) {
                if (arr[i][j] != 0) {
                    if (arr[i][j] + mcost[i] < min_cost) {
                        min_cost = arr[i][j] + mcost[i];
                        min_predecessor = i;
                    }
                }
            }
            mcost[j] = min_cost;
            d[j] = min_predecessor;
        }
        
        p[1] = 0;         
        p[k] = n - 1;     

        for (int j = k - 1; j >= 2; j--) {
            p[j] = d[p[j + 1]];}
        
        if (print_output) {
            cout << "\nMinimum Cost: " << mcost[n - 1] << endl;
            cout << "Path: ";
            for (int i = 1; i <= k; i++) {
                cout << p[i];
                if (i < k) cout << " -> ";
            }
            cout << endl;
        }
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
    
    auto start = high_resolution_clock::now();
    
    int iterations = 100000;
    for(int k = 0; k < iterations; k++) {
        a.FMG_Forward(7, 4, false); 
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Average time per Forward FMG run: " << duration.count() / iterations << " ns\n";
    
    a.FMG_Forward(7, 4, true);
    
    return 0;
}