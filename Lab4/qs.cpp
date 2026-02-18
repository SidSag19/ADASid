#include <iostream>
#include <stack>
#include <utility> 
using namespace std;

int partition(int a[], int low, int high) {
    int v = a[low];
    int i = low;
    int j = high + 1;

    do {
        do { i++; } while (i <= high && a[i] < v);
        do { j--; } while (a[j] > v);

        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    a[low] = a[j];
    a[j] = v;
    return j;
}

void qs(int a[], int start, int end) {
    stack<pair<int, int>> s;
    s.push({start, end});

    while (!s.empty()) {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();

        if (low < high) {
            int p = partition(a, low, high);
            
            int leftSize = p - 1 - low;
            int rightSize = high - (p + 1);

            if (leftSize > rightSize) {
                if (p - 1 > low) s.push({low, p - 1});
                if (p + 1 < high) s.push({p + 1, high});
            } else {
                if (p + 1 < high) s.push({p + 1, high});
                if (p - 1 > low) s.push({low, p - 1});
            }
        }
    }
}

int main() {
    int arr[8] = {3, 6, 4, 1, 12, 10, 11, 19};
    qs(arr, 0, 7);
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    return 0;  
}