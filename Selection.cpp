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
    const int SIZE = 10000; 
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

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int findMinIndex(int arr[], int start, int end) {
//     int min_idx = start;
//     for (int j = start + 1; j <= end; j++) {
//         if (arr[j] < arr[min_idx]) {
//             min_idx = j;
//         }
//     }
//     return min_idx;
// }

// void selectionSortRecursive(int arr[], int n, int index = 0) {
//     if (index >= n - 1) return;

//     int min_idx = findMinIndex(arr, index, n - 1);

//     if (min_idx != index) {
//         swap(arr[index], arr[min_idx]);
//     }

//     selectionSortRecursive(arr, n, index + 1);
// }

// int main() {
//     int arr[] = {29, 10, 14, 37, 13};
//     int n = 5;
//     selectionSortRecursive(arr, n);
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";
//     return 0;
// }