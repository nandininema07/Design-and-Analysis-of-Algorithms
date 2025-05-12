#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Create a 2D table to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;  // Characters match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Take max of top or left
        }
    }

    // Print LCS length
    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;

    // Backtrack to find the actual LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}

/* 
Enter first string: ABCDGH  
Enter second string: AEDFHR
*/