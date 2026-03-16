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

void Dijkstra(int cost[15][15], int n, int v, int visited[], int dist[]) {
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        if (cost[v][i] == 0 && v != i) {
            dist[i] = lar;
        } else {
            dist[i] = cost[v][i];
        }
    }

    visited[v] = 1;
    dist[v] = 0;

    for(int j = 1; j < n; j++){
        int min = lar;
        int u = -1;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;  

        for(int w = 0; w < n; w++){
            int c = (cost[u][w] == 0) ? lar : cost[u][w];
            if(visited[w] == 0 && c != lar){
                if(dist[w] > dist[u] + c){
                    dist[w] = dist[u] + c;
                }
            }
        }
    }
}

int main(){
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

    int src = rand() % num_points; 
    
    int visited[15];
    int dist[15];
    
    auto start = high_resolution_clock::now();
    
    int iterations = 100000;
    for(int k = 0; k < iterations; k++) {
        // Reset visited and dist arrays if necessary, though your Dijkstra 
        // function conveniently resets them at the beginning of the call!
        Dijkstra(a.arr, num_points, src, visited, dist);
    }
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    
    cout << "\nTotal time for " << iterations << " runs: " << duration.count() << " ns\n";
    cout << "Average time per Dijkstra run: " << duration.count() / iterations << " ns\n";

    cout << "\nShortest distances from Source Vertex " << src << ":\n";
    for (int i = 0; i < num_points; i++) {
        cout << "To vertex " << i << " -> ";
        if (dist[i] == lar) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}