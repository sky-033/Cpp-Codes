#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    unordered_map<long long,int> freq;
    freq.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        ++freq[x];
    }
    int64 ans = 1;
    for (auto &p : freq) {
        ans = (ans * ( (int64)p.second + 1 )) % MOD;
    }
    ans = (ans - 1) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
    return 0;
}