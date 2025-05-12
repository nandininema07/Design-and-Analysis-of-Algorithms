#include <iostream>
#include <vector>
#include <climits>
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

    vector<int> dp(amount + 1, INT_MAX);      // Minimum coins needed
    vector<int> coinUsed(amount + 1, -1);     // To trace which coin was used
    dp[0] = 0;  // Base case

    // Fill dp and coinUsed arrays
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            int coin = coins[j];
            if (coin <= i && dp[i - coin] != INT_MAX && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                coinUsed[i] = coin;
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        cout << "Cannot make the amount with given denominations.\n";
    } else {
        cout << "Minimum coins required: " << dp[amount] << endl;
        cout << "Coins used: ";
        int current = amount;
        while (current > 0) {
            cout << coinUsed[current] << " ";
            current -= coinUsed[current];
        }
        cout << endl;
    }

    return 0;
}
/*
Enter number of coin denominations: 3
Enter coin denominations: 1 3 4
Enter amount to make: 6
*/