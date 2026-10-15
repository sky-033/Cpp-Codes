#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int N = 1e6 + 1;

vector<bool> isPrime(N, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve(); // Precompute prime numbers using Sieve of Eratosthenes

    int n;
    cin >> n;
    vector<lli> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            cout << "NO\n";
            continue;
        }
        
        lli sq = sqrt(x[i]);
        if (sq * sq == x[i] && isPrime[sq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
