#include <iostream>
#include <algorithm>

using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool sortFinish(Activity a, Activity b) {
    return a.finish < b.finish;
}

bool sortDuration(Activity a, Activity b) {
    return (a.finish - a.start) < (b.finish - b.start);
}

void selectActivities(Activity arr[], int n, int method) {
    Activity t[10];
    for (int i = 0; i < n; i++) {
        t[i] = arr[i];
    }

    if (method == 1) {
        sort(t, t + n, sortFinish);
        cout << "Method: Sort by Finish Time (fi)\n";
    } else {
        sort(t, t + n, sortDuration);
        cout << "Method: Sort by Duration (fi - si)\n";
    }

    int count = 1;
    int i = 0;
    cout << "Selected Activities: A" << t[i].id << " ";

    for (int j = 1; j < n; j++) {
        if (t[j].start >= t[i].finish) {
            cout << "A" << t[j].id << " ";
            i = j;
            count++;
        }
    }
    cout << "\nTotal Selected: " << count << "\n\n";
}

int main() {
    Activity arr[10] = {
        {1, 0, 4}, {2, 3, 5}, {3, 4, 8},
        {4, 5, 9}, {5, 8, 12}, {6, 11, 13},
        {7, 12, 16}, {8, 15, 17}, {9, 16, 20}, {10, 1, 19}
    };

    int n = 10;

    selectActivities(arr, n, 1);
    
    selectActivities(arr, n, 2);

    return 0;
}