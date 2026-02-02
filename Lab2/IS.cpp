#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
}}}}

void IS(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    int copy_arr[SIZE]; // We'll keep a master copy to reset the array
    
    // Setup random engine with time-based seed
    unsigned seed = system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 100000);

    // Fill the master copy with random numbers
    generate(begin(copy_arr), end(copy_arr), [&]() { return dist(engine); });

    const int ITERATIONS = 100; // Lower iterations because sorting is slower than searching
    auto start = high_resolution_clock::now();

    for(int i = 0; i < ITERATIONS; i++) {
        // RESET: Copy the unsorted master array back into arr
        copy(begin(copy_arr), end(copy_arr), begin(arr));
        
        IS(arr, SIZE);
    }

    if (is_sorted(arr, arr + SIZE)) {
    cout << "SUCCESS: Array is sorted correctly." << endl;
    } else {
    cout << "ERROR: Array is NOT sorted!" << endl;
    }
    auto stop = high_resolution_clock::now();

    auto total_duration = duration_cast<microseconds>(stop - start);
    double average_duration = total_duration.count() / static_cast<double>(ITERATIONS);

    cout << "Sorted " << SIZE << " elements " << ITERATIONS << " times." << endl;
    cout << "Average time per sort: " << average_duration << " microseconds" << endl;
    return 0;
}
