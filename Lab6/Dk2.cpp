#include <iostream>
using namespace std;
#define lar 100000 
#include <chrono>
using namespace std::chrono;

struct g{
    int arr[5][5]={0};

    void graph(int i,int j,int wt){
        arr[i][j]=wt;
    }
    
    void display(){
        for (int i = 0; i <=4; i++) {
            for (int j = 0; j <=4; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void del(int i,int j){
        arr[i][j]=0;
    }
};

void Dijkstra(int cost[5][5], int n, int v, int visited[], int dist[]) {
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
    g a;

    a.graph(2,0,3);
    a.graph(2,1,1);
    a.graph(0,1,2);
    a.graph(1,4,4);
    a.graph(4,2,6);
    a.graph(3,2,2);
    a.graph(4,3,5);

    cout << "Adjacency Matrix:\n";
    a.display();

    int src = 3; 
    int visited[5];
    int dist[5];
    
    auto start = high_resolution_clock::now();
    Dijkstra(a.arr, 5, src, visited, dist);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Time taken by Dijkstra's algorithm: " << duration.count() << " nanoseconds\n";

    cout << "\nShortest distances from Source Vertex " << src << ":\n";
    for (int i = 0; i < 5; i++) {
        cout << "To vertex " << i << " -> ";
        if (dist[i] == lar) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}