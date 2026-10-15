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

    // DP array to store min health for the current row being processed.
    // We only need one row's worth of data at a time.
    vector<long long> dp(n);

    // Iterate from the bottom-right corner of the grid
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == m - 1 && j == n - 1) {
               
                dp[j] = max(1LL, 1LL - grid[i][j]);
            } else if (i == m - 1) {
               
                dp[j] = max(1LL, dp[j + 1] - grid[i][j]);
            } else if (j == n - 1) {
              
                dp[j] = max(1LL, dp[j] - grid[i][j]);
            } else {
                long long min_health_for_next_step = min(dp[j], dp[j + 1]);
                dp[j] = max(1LL, min_health_for_next_step - grid[i][j]);
            }
        }
    }

    // The answer is the health required for the starting cell (0, 0)
    cout << dp[0] << endl;

    return 0;
}