#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

class TSP {
private:
    int n;
    vector<vector<int>> dist;
    vector<vector<int>> memo;

    int tsp(int i, int mask) {
        if (mask == (1 << n) - 1) {
            return dist[i][0];
        }

        if (memo[i][mask] != -1) {
            return memo[i][mask];
        }

        int min_cost = INF;

        for (int j = 0; j < n; ++j) {
            if ((mask & (1 << j)) == 0) {
                int new_mask = mask | (1 << j);
                int cost = dist[i][j] + tsp(j, new_mask);
                min_cost = min(min_cost, cost);
            }
        }

        return memo[i][mask] = min_cost;
    }

public:
    TSP(const vector<vector<int>>& distances) {
        dist = distances;
        n = dist.size();
        memo.assign(n, vector<int>(1 << n, -1));
    }

    int solve() {
        return tsp(0, 1);
    }
};

int main() {
    vector<vector<int>> dist_matrix = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    TSP solver(dist_matrix);
    int min_tour_cost = solver.solve();

    cout << "The minimum cost to visit all cities is: " << min_tour_cost << endl;

    return 0;
}