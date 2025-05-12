#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    // Base case: If all cities are visited (mask is all 1s)
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the starting city
    }

    // If this state has already been computed, return the value
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX; // Initialize the answer as a large number

    // Try to go to all cities from the current position
    for (int city = 0; city < n; city++) {
        // Check if the city has not been visited yet
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns); // Take the minimum cost
        }
    }

    return dp[mask][pos] = ans; // Store and return the answer
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Initialize dp table with -1
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    // Start TSP from city 0
    int result = tsp(1, 0, dist, dp, n);

    cout << "Minimum cost to visit all cities: " << result << endl;

    return 0;
}
/*
Enter the number of cities: 4
Enter the distance matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
*/