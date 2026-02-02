#include <iostream>
#include <vector>

using namespace std;

int xorRange(int n) {
    if (n == 0) return 0;
    return n ^ xorRange(n - 1);
}

int xorVector(const vector<int>& nums, int index) {
    if (index >= nums.size()) return 0;
    return nums[index] ^ xorVector(nums, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6};
    int n = 6;
    int result = xorRange(n) ^ xorVector(nums, 0);
    cout << "The missing number is: " << result << endl;

    return 0;
}