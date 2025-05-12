#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> value(n + 1), weight(n + 1);

    cout << "Enter value and weight of each item:\n";
    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> weight[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Maximum value
    cout << "Maximum value in knapsack = " << dp[n][capacity] << endl;

    // Find which items are selected
    int w = capacity;
    cout << "Selected items (value weight):\n";
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            // Item i is included
            cout << value[i] << " " << weight[i] << endl;
            w -= weight[i];
        }
    }

    return 0;
}

/*
Enter number of items: 3
Enter value and weight of each item:
60 10
100 20
120 30
Enter knapsack capacity: 50
*/