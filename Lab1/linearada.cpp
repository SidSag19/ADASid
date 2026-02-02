#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    const int SIZE = 50000;
    static int arr[SIZE];
    
    // random_device rd;
    // mt19937 engine(rd());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 50000);
    generate(begin(arr), end(arr), [&]() { return dist(engine); });

    int search_elem;
    cout << "Enter element to search (1-100000): ";
    cin >> search_elem;

    const int ITERATIONS = 1000;
    auto start = high_resolution_clock::now();

    int resultIndex = -1;
    for(int i = 0; i < ITERATIONS; i++) {
        resultIndex = linearSearch(arr, SIZE, search_elem);
    }
    auto stop = high_resolution_clock::now();

    auto total_duration = duration_cast<microseconds>(stop - start);
    double average_duration = total_duration.count() / static_cast<double>(ITERATIONS);

    if (resultIndex != -1) cout << "Found at index: " << resultIndex << endl;
    else cout << "Not found." << endl;

    cout << "Average time per search: " << average_duration << " micros" << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int linearSearchRecursive(const int arr[], int size, int target, int index) {
//     if (index >= size) {
//         return -1;
//     }
//     if (arr[index] == target) {
//         return index;
//     }
//     return linearSearchRecursive(arr, size, target, index + 1);
// }

// int main() {
//     int arr[] = {10, 20, 30, 40, 50};
//     int size = 5;
//     int target = 30;
//     int result = linearSearchRecursive(arr, size, target, 0);
    
//     if (result != -1) cout << "Found at index: " << result << endl;
//     else cout << "Not found." << endl;
//     return 0;
// }