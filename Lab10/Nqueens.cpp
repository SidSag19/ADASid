#include <iostream>
#include <cmath>
using namespace std;

const int MAX_SIZE = 16; 

bool isSafe(int row, int col, int cols[]) {
    for (int i = 1; i < row; i++) {
        if (cols[i] == col || abs(cols[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool backtrack(int row, int n, int cols[]) {
    if (row > n) {
        cout << "[ ";
        for (int i = 1; i <= n; i++) cout << cols[i] << " ";
        cout << "]\n";
        return true; 
    }
    
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col, cols)) {
            cols[row] = col;
            
            if (backtrack(row + 1, n, cols)) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
    int n = 4; 
    int cols[MAX_SIZE];
    
    if (n >= MAX_SIZE) return 1;
    
    if (!backtrack(1, n, cols)) {
        cout << "No solution exists.\n";
    }
    
    return 0;
}