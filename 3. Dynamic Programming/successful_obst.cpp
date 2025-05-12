#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
using namespace std;

// Function to calculate the cost of Optimal BST
int optimalBSTCost(vector<int>& keys, vector<int>& freq, int n) {
    // Create a table to store the cost of subtrees
    vector<vector<int>> cost(n, vector<int>(n, 0));

    // Fill the diagonal with the frequency of the keys
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Calculate the cost for chains of length 2 to n
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            // Try all roots in the range [i, j]
            for (int r = i; r <= j; r++) {
                int left_cost = (r > i) ? cost[i][r - 1] : 0;
                int right_cost = (r < j) ? cost[r + 1][j] : 0;
                int root_cost = left_cost + right_cost + accumulate(freq.begin() + i, freq.begin() + j + 1, 0);
                cost[i][j] = min(cost[i][j], root_cost);
            }
        }
    }

    // Return the minimum cost for the whole tree
    return cost[0][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<int> keys(n), freq(n);
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the frequencies for each key: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << "Optimal BST cost: " << optimalBSTCost(keys, freq, n) << endl;

    return 0;
}

/* 
Enter the number of keys: 4
Enter the keys: 10 12 20 30
Enter the frequencies for each key: 34 8 50 40
*/
