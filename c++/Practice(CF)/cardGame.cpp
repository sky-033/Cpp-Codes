#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        // Create all possible play orders for Suneet and Slavic
        vector<pair<int, int>> suneetCards = {{a1, a2}, {a2, a1}};
        vector<pair<int, int>> slavicCards = {{b1, b2}, {b2, b1}};

        int winCount = 0;

        // Loop through all possible combinations of plays
        for (auto suneet : suneetCards) {
            for (auto slavic : slavicCards) {
                int suneetWins = 0;
                int slavicWins = 0;

                // Compare first round
                if (suneet.first > slavic.first) {
                    suneetWins++;
                } else if (suneet.first < slavic.first) {
                    slavicWins++;
                }

                // Compare second round
                if (suneet.second > slavic.second) {
                    suneetWins++;
                } else if (suneet.second < slavic.second) {
                    slavicWins++;
                }

                // If Suneet wins more rounds, count it as a win for him
                if (suneetWins > slavicWins) {
                    winCount++;
                }
            }
        }

        // Output the result for the test case
        cout << winCount << endl;
    }
    return 0;
}
