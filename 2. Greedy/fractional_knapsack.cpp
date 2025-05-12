#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item {
    int value, weight;
    double ratio; // value per weight
};

// Comparator to sort items by descending value/weight ratio
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    cout << "\nSelected items (value, weight, fraction used):\n";

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            // Take the full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
            cout << items[i].value << " " << items[i].weight << " 1.0" << endl;
        } else {
            // Take fraction of item
            double fraction = capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            cout << items[i].value << " " << items[i].weight << " " << fraction << endl;
            capacity = 0;
        }
    }

    cout << "\nMaximum total value in knapsack = " << totalValue << endl;

    return 0;
}
