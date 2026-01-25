#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    const int SIZE = 100; 
    static int arr[SIZE];
    static int copy_arr[SIZE]; 
    
    unsigned seed = system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 100000);

    generate(begin(copy_arr), end(copy_arr), [&]() { return dist(engine); });

    const int ITERATIONS = 100; 
    auto start = high_resolution_clock::now();

    for(int i = 0; i < ITERATIONS; i++) {
        copy(begin(copy_arr), end(copy_arr), begin(arr));
        selectionSort(arr, SIZE);
    }

    auto stop = high_resolution_clock::now();

    auto total_duration = duration_cast<microseconds>(stop - start);
    double average_duration = total_duration.count() / static_cast<double>(ITERATIONS);

    cout << "Selection Sort: Sorted " << SIZE << " elements " << ITERATIONS << " times." << endl;
    cout << "Average time per sort: " << average_duration << " microseconds" << endl;

    return 0;
}