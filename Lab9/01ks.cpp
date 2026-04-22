#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> V(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } 
            else if (wt[i - 1] <= j) {
                V[i][j] = max(val[i - 1] + V[i - 1][j - wt[i - 1]], V[i - 1][j]);
            } 
            else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    return V[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}