#include <iostream>
#include <vector>

using namespace std;
double hornerRecursive(const vector<double>& poly, int n, int x) {
    // Base Case: If we are at the last coefficient (leading coefficient an)
    if (n == poly.size() - 1) {
        return poly[n];
    }
    return poly[n] + x * hornerRecursive(poly, n + 1, x);
}

int main() {
    // Example: 3x^2 + 2x + 5 , a0=5, a1=2, a2=3
    vector<double> poly = {5, 2, 3}; 
    int x = 2;
    double result = hornerRecursive(poly, 0, x);
    cout << "The value of the polynomial at x = " << x << " is: " << result << endl;

    return 0;
}