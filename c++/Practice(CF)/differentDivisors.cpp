#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 
vector<bool> is_prime(N + 1, true); 
void sieveOfEratosthenes(lli N) {
    is_prime[0] = is_prime[1] = false;  // 0 and 1 are not primes

    for (lli p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            // Mark all multiples of p as non-prime
            for (lli multiple = p * p; multiple <= N; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieveOfEratosthenes(N);
    int t;
    cin>>t;
    while(t--){
        lli d;
        cin>>d;
        lli ans=1,ct=1,check=1;
        for(lli i=d+1;i<N;i++){
            if(is_prime[i]==true && (i-check)>=d){
                ans*=i;
                ct++;
                check=i;
            }
            if(ct>=3) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}