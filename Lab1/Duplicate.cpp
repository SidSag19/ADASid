#include <iostream>
#include <vector>

using namespace std;

bool checkPrevious(const vector<int>& arr, int currentVal, int j) {
    if (j < 0) return false;
    if (arr[j] == currentVal) return true;
    return checkPrevious(arr, currentVal, j - 1);
}

void findFirstDuplicateRecursive(const vector<int>& arr, int i) {
    if (i >= arr.size()) {
        cout << "No duplicates found." << endl;
        return;
    }

    if (checkPrevious(arr, arr[i], i - 1)) {
        cout << "First duplicate entry: " << arr[i] << endl;
        cout << "Found at index: " << i << endl;
        return;
    }

    findFirstDuplicateRecursive(arr, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 2, 3};
    findFirstDuplicateRecursive(arr, 0);
    return 0;
}