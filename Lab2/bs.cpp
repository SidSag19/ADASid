#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

//time measured in nanoseconds
using namespace std;
using namespace std::chrono;

void Sort(int arr[], int n) {
    std::sort(arr, arr + n); 
}

int bs(const int arr[], int x, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;
    }
    if (arr[mid] > x) {
        return bs(arr, x, low, mid - 1);
    } else {
        return bs(arr, x, mid + 1, high);
    }
}

int main() {
    const int SIZE = 100000;
    static int arr[SIZE];

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(1, 100000);
    
    generate(begin(arr), end(arr), [&]() { return dist(engine); });

    Sort(arr, SIZE); 

    const int ITERATIONS = 1000000;
    int searchTarget = 10000000; 

    auto start = high_resolution_clock::now();

    int resultIndex = -1;
    for (int i = 0; i < ITERATIONS; i++) {
        resultIndex = bs(arr, searchTarget, 0, SIZE - 1);
    }

    auto stop = high_resolution_clock::now();

    auto total_duration = duration_cast<nanoseconds>(stop - start);
    double average_duration = total_duration.count() / static_cast<double>(ITERATIONS);

    if (resultIndex != -1) 
        cout << "Found at index: " << resultIndex << endl;
    else 
        cout << "Not found." << endl;

    cout << "time to search: " << average_duration << " ns" << endl;

    return 0;
}