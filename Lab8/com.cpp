#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; 
    
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; 
            
            for (int k = i; k <= j - 1; k++) {
                int current_cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (current_cost < m[i][j]) {
                    m[i][j] = current_cost;
                }
            }
        }
    }

    return m[1][n];
}

int main() {
    vector<int> arr = {5, 10, 3, 12, 5}; 
    
    cout << "The minimum number of multiplications is: " << matrixChainOrder(arr) << endl;
    
    return 0;
}