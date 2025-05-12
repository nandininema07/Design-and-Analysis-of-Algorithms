#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dim(n + 1);
    cout << "Enter dimensions (p0 p1 p2 ... pn): ";
    for (int i = 0; i <= n; i++) {
        cin >> dim[i];
    }

    // dp[i][j] = minimum number of scalar multiplications needed
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Length of the chain (from 2 to n)
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                // Cost = cost of multiplying A[i..k] and A[k+1..j] + cost of final multiplication
                int cost = dp[i][k] + dp[k + 1][j] + dim[i] * dim[k + 1] * dim[j + 1];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    cout << "Minimum number of multiplications: " << dp[0][n - 1] << endl;

    return 0;
}

/* 
Enter number of matrices: 4
Enter dimensions (p0 p1 p2 p3 p4): 10 20 30 40 30
*/