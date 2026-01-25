#include <iostream>
using namespace std;

int bounce(float vel, int n) {
    if (vel < 1) {
        return n;
    } else {
        return bounce(0.575 * vel, n + 1);
    }
}

int main() {
    int a;
    a = bounce(8, 0);
    cout << "Total bounces: " << a;
    return 0;
}