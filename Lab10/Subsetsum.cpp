#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void findSubsets(const int set[], int setSize, int target, int index, int currentSum, int currentSubset[], int currentSubsetSize, int& resultCount) {
    if (currentSum == target) {
        resultCount++;
        cout << "{ ";
        for (int i = 0; i < currentSubsetSize; i++) {
            cout << currentSubset[i] << " ";
        }
        cout << "}\n";
        return; 
    }

    for (int i = index; i < setSize; i++) {
        if (currentSum + set[i] <= target) {
            currentSubset[currentSubsetSize] = set[i];  
            findSubsets(set, setSize, target, i + 1, currentSum + set[i], currentSubset, currentSubsetSize + 1, resultCount); 
        }
    }
}

int main() {
    int set[MAX_SIZE] = {1, 2, 3, 4, 5};
    int setSize = 5; 
    int m = 7;
    
    int currentSubset[MAX_SIZE];
    int resultCount = 0;
    cout << "The subsets are:\n";
    findSubsets(set, setSize, m, 0, 0, currentSubset, 0, resultCount);
    cout << "\nNumber of subsets giving sum " << m << ": " << resultCount << "\n";
    
    return 0;
}