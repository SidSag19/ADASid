#include <iostream>
#include <string>

using namespace std;

struct LCS_DP {
    int c[100][100] = {0};
    char p[100][100]; 

    void LCS(string X, string Y) {
        int m = X.length();
        int n = Y.length();

        for (int i = 0; i <= n; i++) {
            c[0][i] = 0;
        }
        
        for (int i = 1; i <= m; i++) {
            c[i][0] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    c[i][j] = 1 + c[i - 1][j - 1];
                    p[i][j] = 'D'; 
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    p[i][j] = 'U'; 
                } else {
                    c[i][j] = c[i][j - 1];
                    p[i][j] = 'L'; 
                }
            }
        }
    }

    void WriteSol(string X, int i, int j) {
        if (i == 0 || j == 0) {
            return;
        }
        
        if (p[i][j] == 'D') {
            WriteSol(X, i - 1, j - 1);
            cout << X[i - 1]; 
        } else if (p[i][j] == 'U') {
            WriteSol(X, i - 1, j);
        } else {
            WriteSol(X, i, j - 1);
        }
    }
};

int main() {
    LCS_DP a;
    
    string X = "COMPUTER";
    string Y = "CONTROL";

    a.LCS(X, Y);
    
    cout << "String X: " << X << endl;
    cout << "String Y: " << Y << endl;
    
    cout << "Longest Common Subsequence: ";
    a.WriteSol(X, X.length(), Y.length());
    cout << "\nLength: " << a.c[X.length()][Y.length()] << endl;

    return 0;
}