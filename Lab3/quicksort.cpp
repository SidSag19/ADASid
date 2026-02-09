#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(int a[], int m, int p) {
    int v = a[m];
    int i = m;
    int j = p + 1;

    do {
        do { i++; } while (i <= p && a[i] < v);
        do { j--; } while (a[j] > v);

        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i < j);

    a[m] = a[j];
    a[j] = v;
    return j;
}

void qs(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        qs(a, low, j - 1);
        qs(a, j + 1, high);
    }
}

int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    int copy_arr[SIZE];
    
    unsigned seed = system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 10000);

    generate(begin(copy_arr), end(copy_arr), [&]() { return dist(engine); });

    const int ITERATIONS = 4000;
    auto start = high_resolution_clock::now();

    for(int i = 0; i < ITERATIONS; i++) {
        copy(begin(copy_arr), end(copy_arr), begin(arr));
        qs(arr, 0, SIZE - 1);
    }

    auto stop = high_resolution_clock::now();
    auto total_duration = duration_cast<microseconds>(stop - start);
    double average_duration = total_duration.count() / static_cast<double>(ITERATIONS);

    cout << "Sorted " << SIZE << " elements " << ITERATIONS << endl;
    cout << "Average time: " << average_duration << " microseconds" << endl;

    return 0;
}