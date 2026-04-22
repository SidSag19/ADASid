#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

#define lar 100000 

struct g {
    int arr[15][15] = {0};
    int n; 

    void graph(int i, int j, int wt) {
        arr[i][j] = wt;
    }
    
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void del(int i, int j) {
        arr[i][j] = 0;
    }
};

void FloydWarshall(int cost[15][15], int n, int dist[15][15]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (cost[i][j] == 0) {
                dist[i][j] = lar;
            } else {
                dist[i][j] = cost[i][j];
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != lar && dist[k][j] != lar && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int num_points;
    cout << "Enter the total number of points (between 3 and 15): ";
    cin >> num_points;

    if (num_points < 3 || num_points > 15) {
        cout << "Invalid input. Please restart and enter a number between 3 and 15.\n";
        return 1;
    }

    g a;
    a.n = num_points;
    
    srand(time(0));

    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_points; j++) {
            if (i != j) {
                if (rand() % 100 < 40) { 
                    int weight = (rand() % 20) + 1;
                    a.graph(i, j, weight);
                }
            }
        }
    }

    cout << "\nAdjacency Matrix:\n";
    a.display();

    int dist[15][15];
    
    auto start = high_resolution_clock::now();
    
    int iterations = 100000;
    for(int k = 0; k < iterations; k++) {
        FloydWarshall(a.arr, num_points, dist);
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    
    cout << "\nTotal time for " << iterations << " runs: " << duration.count() << " ns\n";
    cout << "Average time per Floyd-Warshall run: " << duration.count() / iterations << " ns\n";

    cout << "\nAll Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_points; j++) {
            if (dist[i][j] == lar) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << "\n";
    }

    return 0;
}