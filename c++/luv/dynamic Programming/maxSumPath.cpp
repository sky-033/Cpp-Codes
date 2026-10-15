#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    // Read the grid values
    vector<vector<long long>> grid(m, vector<long long>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Full DP table to store min health required at each cell
    vector<vector<long long>> dp(m, vector<long long>(n));

    // Process from bottom-right to top-left
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == m - 1 && j == n - 1) {
                // Base Case: Destination cell
                // If grid[i][j] is positive, we need at least 1 health
                // If grid[i][j] is negative, we need enough to survive the damage + 1
                dp[i][j] = max(1LL, 1LL - grid[i][j]);
            } 
            else if (i == m - 1) {
                // Last row: Can only move right
                dp[i][j] = max(1LL, dp[i][j + 1] - grid[i][j]);
            } 
            else if (j == n - 1) {
                // Last column: Can only move down
                dp[i][j] = max(1LL, dp[i + 1][j] - grid[i][j]);
            } 
            else {
                // General case: Choose the path that requires less health
                long long min_health_for_next_step = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1LL, min_health_for_next_step - grid[i][j]);
            }
        }
    }

    // The answer is the health required for the starting cell (0, 0)
    cout << dp[0][0] << endl;

    return 0;
}