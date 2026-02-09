#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Merge logic using a pre-allocated temp array
void merge(int arr[], int temp[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    for (i = low; i <= high; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, temp, low, mid);
        mergeSort(arr, temp, mid + 1, high);
        merge(arr, temp, low, mid, high);
    }
}

int main() {
    const int SIZE = 50000;
    int arr[SIZE];
    int copy_arr[SIZE];
    int temp[SIZE]; // Allocated ONCE, here on the stack
    
    unsigned seed = system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 50000);

    generate(begin(copy_arr), end(copy_arr), [&]() { return dist(engine); });

    const int ITERATIONS = 1000;
    auto start = high_resolution_clock::now();

    for(int i = 0; i < ITERATIONS; i++) {
        copy(begin(copy_arr), end(copy_arr), begin(arr));
        // Pass temp array into the function
        mergeSort(arr, temp, 0, SIZE - 1);
    }

    auto stop = high_resolution_clock::now();
    double average_duration = duration_cast<microseconds>(stop - start).count() / static_cast<double>(ITERATIONS);

    cout << "Sorted " << SIZE << " elements " << ITERATIONS << " times." << endl;
    cout << "Average time per sort: " << average_duration << " microseconds" << endl;

    return 0;
}