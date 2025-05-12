#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter amount to make: ";
    cin >> amount;

    // Sort in descending order for greedy
    sort(coins.rbegin(), coins.rend());

    cout << "\nCoins used:\n";
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            cout << coins[i] << " ";
            amount -= coins[i];
        }
    }

    if (amount > 0)
        cout << "\nCannot make exact change with given denominations.";

    return 0;
}
/*
Enter number of coin denominations: 3
Enter coin denominations: 1 3 4
Enter amount to make: 6
*/