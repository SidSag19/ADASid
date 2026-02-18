#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void permute(string &str, int left, int right) {
    if (left == right) {
        cout << str << endl;
    } else {
        for (int i = left; i <= right; i++) {
            swap(str[left], str[i]);
            permute(str, left + 1, right);
            swap(str[left], str[i]);
        }
    }
}

int main() {
    string input = "abcd";
    int n = input.size();
    
    cout << "Permutations of " << input << ":" << endl;
    permute(input, 0, n - 1);
    
    return 0;
}