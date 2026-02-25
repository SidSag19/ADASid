#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

struct Item {
    double weight;
    double profit;
    double ratio;
};

//3 Greedy Strategies

// Method 1:Least Weight
bool sortByWeight(const Item& a, const Item& b) {
    if (a.weight == b.weight) return a.profit > b.profit;
    return a.weight < b.weight;
}

// Method 2:Highest Profit
bool sortByProfit(const Item& a, const Item& b) {
    if (a.profit == b.profit) return a.weight < b.weight;
    return a.profit > b.profit;
}

// Method 3:Highest Profit/Weight Ratio (Optimal for Fractional Knapsack)
bool sortByRatio(const Item& a, const Item& b) {
    if (a.ratio == b.ratio) return a.profit > b.profit;
    return a.ratio > b.ratio;
}

// --- Main Algorithm ---

double solveKnapsack(vector<Item> items, int method, double maxWeight) {
    if (method == 1) {
        sort(items.begin(), items.end(), sortByWeight);
    } else if (method == 2) {
        sort(items.begin(), items.end(), sortByProfit);
    } else {
        sort(items.begin(), items.end(), sortByRatio);
    }

    double totalProfit = 0;

    for (const auto& item : items) {
        if (maxWeight <= 0) break; // Knapsack is full

        double weightToTake = min(item.weight, maxWeight); 
        
        totalProfit += weightToTake * item.ratio; 
        
        maxWeight -= weightToTake; 
    }

    return totalProfit;
}

int main() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);

    uniform_real_distribution<> weightDist(1.0, 1000.0);
    uniform_real_distribution<> profitDist(0.0, 1000.0);

    int numItems = 10;
    double maxCapacity = 500.0;
    vector<Item> items(numItems);

    // Generate random items
    for (int i = 0; i < numItems; i++) {
        items[i].weight = weightDist(gen);
        items[i].profit = profitDist(gen);
        items[i].ratio = items[i].profit / items[i].weight;
    }

    // Test the 3 different greedy approaches
    cout << "Knapsack Capacity: " << maxCapacity << "\n\n";

    cout << "Method 1 (Least Weight First) Profit: " 
         << solveKnapsack(items, 1, maxCapacity) << "\n";
         
    cout << "Method 2 (Highest Profit First) Profit: " 
         << solveKnapsack(items, 2, maxCapacity) << "\n";
         
    cout << "Method 3 (Highest Ratio First - OPTIMAL) Profit: " 
         << solveKnapsack(items, 3, maxCapacity) << "\n";

    return 0;
}